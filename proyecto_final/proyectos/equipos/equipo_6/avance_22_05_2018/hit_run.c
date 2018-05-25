#include "Headers/init.h"
#include "Headers/chebyshev_center.h"
#include "Headers/matrix_operations.h"
#include "Headers/box_muller.h"

int main(int argc, char *argv[]) {
  parse_arguments(argc, argv);

  define_pointers();
  define_parameters();

  get_initvalue();


  // Free mallocs
  free(P_EQUALITY->a);
  free(P_INEQUALITY->a);
  free(P_EQUALITY->b);
  free(P_INEQUALITY->b);
  return 0;
}
