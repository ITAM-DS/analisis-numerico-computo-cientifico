#include <stdio.h>
#include <math.h>
#include <omp.h>

double valor_c (double a, double b); 

double valor_s (double a, double b);

int main(void){
	int m, n, i, j, g1, g2, col, d, k, m2, y, g, w, z, c1, d1, k1, h, e;
	double c, s;
	char archivo[256];

	printf("Nombre del archivo que contiene la matriz:");
    	scanf("%s" , archivo);

	printf("Ingresa el número de filas de matriz:");
    	scanf("%d", &m);
	m2 = m;
    	printf("Ingresa el número de columnas de la matriz:");
    	scanf("%d", &n);

	
	double A[m][n], Q[m][m], R[m][n], temporal[m][m], temporal2[m][n], G[m][m], AA[m][n];

	//Leemos el archivo .txt que contiene la matriz
	FILE *file;
  	file=fopen(archivo, "r");

 	for(i = 0; i < m; i++)
  	{
      		for(j = 0; j < n; j++) 
      		{
			fscanf(file, "%lf", &A[i][j]);
			R[i][j] = A[i][j];
      		}

  	}
	printf("\n");


	//Generamos una matriz I de tamaño mxm
	# pragma omp parallel for num_threads(m)
		for(i = 0; i < m; i++){
			# pragma omp parallel for num_threads(m)
				for(j = 0; j < m; j++){
					if(i == j){
						Q[i][j] = 1.0;
					}else{
						Q[i][j] = 0.0;
					}
				}
		}

	//Imprimimos la matriz A
	printf("Imprimimos la matriz A\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%lf\t", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	

	for(j = 0; j < n; j++){
		for(i = m-1; i >= j+1; i--){

			//Generamos una matriz I de tamaño mxm
			# pragma omp parallel for num_threads(m)
				for(g1 = 0; g1 < m; g1++){
					# pragma omp parallel for num_threads(m)
						for(g2 = 0; g2 < m; g2++){
							if(g1 == g2){
								G[g1][g2] = 1.0;
							}else{
								G[g1][g2] = 0.0;
							}
						}
				}

			c = valor_c(R[i-1][j], R[i][j]);
			s = valor_s(R[i-1][j], R[i][j]);
				
			G[i-1][i-1] = c;
			G[i-1][i  ] = s*(-1);

			G[i][i-1] = s;
			G[i][i  ] = c;

			
			//Iniciamos/Reiniciamos la matriz temporal2 de tamaño mxm
			# pragma omp parallel for num_threads(m)
			for(h = 0; h < m; h++){
				# pragma omp parallel for num_threads(n)
					for(e = 0; e < n; e++){
						temporal2[h][e] = 0.0;	
					}
			}
			
			//temporal2 = t(G)*R;
			#pragma omp parallel for schedule(dynamic) collapse(2) private(col,d,k) shared(G,R,temporal2) num_threads(m)
			for(col=0;col<m;col++)for(d=0;d<n;d++)for(k=0;k<m;k++)temporal2[col][d]+=G[k][col]*R[k][d];
	
			//R = temporal2
			# pragma omp parallel for num_threads(m)
				for(y = 0; y < m; y++){
					# pragma omp parallel for num_threads(m)
						for(g = 0; g < m; g++){
							R[y][g] = temporal2[y][g];	
						}
				}
			
			//Iniciamos/Reiniciamos la matriz temporal de tamaño mxm
			# pragma omp parallel for num_threads(m)
			for(h = 0; h < m; h++){
				# pragma omp parallel for num_threads(m)
					for(e = 0; e < m; e++){
						temporal[h][e] = 0.0;
					}
			}

			//temporal = Q*G
			#pragma omp parallel for schedule(dynamic) collapse(2) private(col,d,k) shared(Q,G,temporal) num_threads(m2)
			for(col=0;col<m2;col++)for(d=0;d<m2;d++)for(k=0;k<m2;k++)temporal[col][d]+=Q[col][k]*G[k][d];			
		
			//Q = temporal
			# pragma omp parallel for num_threads(m2)
				for(w = 0; w < m2; w++){
					# pragma omp parallel for num_threads(m2)
						for(z = 0; z < m2; z++){
							Q[w][z] = temporal[w][z];	
						}
				}
					
		}	
	}
	printf("\n");

	//Multiplicamos AA = Q*R
	#pragma omp parallel for schedule(dynamic) collapse(2) private(c1,d1,k1) shared(Q,R,AA) num_threads(m)
	for(c1 = 0; c1 < m; c1++)for(d1 = 0; d1 < n; d1++)for(k1 = 0; k1 < m; k1++)AA[c1][d1]+=Q[c1][k1]*R[k1][d1];

	//Imprimimos AA, que debe ser lo más parecida posible a A
	printf("Imprimimos la matriz que resulta de Q*R\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%lf\t", AA[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//Imprimimos la matriz Q
	printf("Imprimimos la matriz Q\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			printf("%lf\t", Q[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	//Imprimimos la matriz R
	printf("Imprimimos la matriz R\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%lf\t", R[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	

return 0;
}



double valor_c ( double a, double b ){   

	double r, c_i, s_i;

	if(b == 0){
		c_i = 1;
		s_i = 0;
	}else{
		if(fabs(b) > fabs(a)){
			r = a / b;
			s_i = 1 / sqrt(1 + pow(r, 2));
			c_i = s_i*r;
		}else{
			r = b / a;
			c_i = 1 / sqrt(1 + pow(r, 2));
			s_i = c_i*r;
		}
	}

	return c_i;

}

double valor_s ( double a, double b ){   

	double r, c_i, s_i;

	if(b == 0){
		c_i = 1;
		s_i = 0;
	}else{
		if(fabs(b) > fabs(a)){
			r = a/b;
			s_i = 1 / sqrt(1 + pow(r, 2));
			c_i = s_i*r;
		}else{
			r = b / a;
			c_i = 1 / sqrt(1 + pow(r, 2));
			s_i = c_i*r;
		}
	}

	return s_i;

}







