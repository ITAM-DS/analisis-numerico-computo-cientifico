/************************************************************************************************/
/************ Arturo Gonzalez Bencomo 172906, Arturo Torre Gonzalez 90226 ***********************/
/************************************************************************************************/
/********************************** grayscale.cu ************************************************/
/************************************************************************************************/
/** Este programa escrito en c++ convierte una imagen rgb a una en escala de grises *************/
/** cuda. ***************************************************************************************/

#include <cuda_runtime.h>      //Administrador del runtime de cuda
#include <stdlib.h>
#include <iostream>
#include <png.h>
#include <math.h>
#include "kernel.h"
#include "kernel.cu"

int width, height;
png_byte color_type;
png_byte bit_depth;
png_bytep *row_pointers;


void read_png_file(char *filename) {
  FILE *fp = fopen(filename, "rb");

  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) abort();

  png_infop info = png_create_info_struct(png);
  if(!info) abort();

  if(setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  png_read_info(png, info);

  width      = png_get_image_width(png, info);
  height     = png_get_image_height(png, info);
  color_type = png_get_color_type(png, info);
  bit_depth  = png_get_bit_depth(png, info);

  // Read any color_type into 8bit depth, RGBA format.
  // See http://www.libpng.org/pub/png/libpng-manual.txt

  if(bit_depth == 16)
    png_set_strip_16(png);

  if(color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
  if(color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha(png);

  // These color_type don't have an alpha channel then fill it with 0xff.
  if(color_type == PNG_COLOR_TYPE_RGB ||
     color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

  if(color_type == PNG_COLOR_TYPE_GRAY ||
     color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);

  png_read_update_info(png, info);

  row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
  for(int y = 0; y < height; y++) {
    row_pointers[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
  }

  png_read_image(png, row_pointers);

  fclose(fp);
}

void write_png_file(char *filename) {
  int y;

  FILE *fp = fopen(filename, "wb");
  if(!fp) abort();

  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) abort();

  png_infop info = png_create_info_struct(png);
  if (!info) abort();

  if (setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  // Output is 8bit depth, RGBA format.
  png_set_IHDR(
    png,
    info,
    width, height,
    8,
    PNG_COLOR_TYPE_RGBA,
    PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_DEFAULT,
    PNG_FILTER_TYPE_DEFAULT
  );
  png_write_info(png, info);

  // To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
  // Use png_set_filler().
  //png_set_filler(png, 0, PNG_FILLER_AFTER);

  png_write_image(png, row_pointers);
  png_write_end(png, NULL);

  for(int y = 0; y < height; y++) {
    free(row_pointers[y]);
  }
  free(row_pointers);

  fclose(fp);
}

void process_png_file() {
  const size_t width = 963;
  const size_t height = 502;
  int *matrizR;
  int *matrizG;
  int *matrizB;
  int *gray;

  //Asignamos memoria para cada matriz de cada color
  cudaMalloc((void **)&matrizR, width * height * sizeof(int));
  cudaMalloc((void **)&matrizG, width * height * sizeof(int));
  cudaMalloc((void **)&matrizB, width * height * sizeof(int));

  cudaMalloc((void **)&gray, width * height * sizeof(int));

  cudaError_t result = cudaMemcpy(matrizR, src, width*height * sizeof(int), cudaMemcpyHostToDevice);
  cudaError_t result = cudaMemcpy(matrizG, src, width*height * sizeof(int), cudaMemcpyHostToDevice);
  cudaError_t result = cudaMemcpy(matrizB, src, width*height * sizeof(int), cudaMemcpyHostToDevice);

  //ejecutamos el kernel de cuda
  grayscale(matrizR,matrizG,matrizB,gray)
}

int main(int argc, char *argv[]) {
  if(argc != 3) abort();

  read_png_file(argv[1]);
  process_png_file();
//  write_png_file(argv[2]);
  //Imprimimos matriz

  for(int x=0; x<502; x++)
  {
     for(int y=0; y<963; y++)
     {
         cout << matriz[x][y];
         if(y < 962){
           cout << ",";
         }
     }
     cout << "\n";
  }
  return 0;
}
