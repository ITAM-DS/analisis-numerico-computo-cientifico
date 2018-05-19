#include <stdio.h>
#include <math.h>

float valor_c (float a, float b); 

float valor_s (float a, float b);

int main(void){
	int m, n, i, j, q, g1, g2, col, d, k, m2, y, g, w, z;
	float zero = 0.0, c, s, sum = 0;

	printf("Ingresa el número de filas de matriz:");
    	scanf("%d", &m);
	m2 = m;
    	printf("Ingresa el número de columnas de la matriz:");
    	scanf("%d", &n);

	
	float A[m][n], Q[m][m], temporal[m][m], R[m][n], temporal2[m][n], G[m][m];

	//Leemos la matriz, columna por columna
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("Ingresa el valor %d de la fila %d:", j, i);
			scanf("%f", &A[i][j]);
			R[i][j] = A[i][j];
			temporal2[i][j] = A[i][j]; 
		}
	}
	printf("\n");

	//Generamos una matriz I de tamaño mxm
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			if(i == j){
				Q[i][j] = 1.0;
				temporal[i][j] = 1.0;
			}else{
				Q[i][j] = 0.0;
				temporal[i][j] = 1.0;
			}
		}
	}

	//Imprimimos la matriz A
	printf("Imprimimos la matriz A\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%f\t", A[i][j]);
		
		}
		printf("\n");
	}
	printf("\n");

	

	for(j = 0; j < n; j++){
		for(i = m-1; i >= j+1; i--){

			//Generamos una matriz I de tamaño mxm
			for(g1 = 0; g1 < m; g1++){
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

			//R = t(G)*R;
			for (col = 0; col < m; col++) {
      				for (d = 0; d < n; d++) {
        				for (k = 0; k < m; k++) {
          					sum = sum + G[k][col]*R[k][d];
        				}
 
        				temporal2[col][d] = sum;
       					sum = 0;
      				}
    			}

			for(y = 0; y < m; y++){
				for(g = 0; g < m; g++){
					R[y][g] = temporal2[y][g];	
				}
			}
			
					
			//Q = Q*G
			for (col = 0; col < m2; col++) {
     				for (d = 0; d < m2; d++) {
       					for (k = 0; k < m2; k++) {
         					sum = sum + Q[col][k]*G[k][d];
        				}
 
        				temporal[col][d] = sum;
        				sum = 0;
      				}
    			}

			for(w = 0; w < m2; w++){
				for(z = 0; z < m2; z++){
					Q[w][z] = temporal[w][z];	
				}
			}
			
		}
	}
	printf("\n");



	//Imprimimos la matriz Q
	printf("Imprimimos la matriz Q\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < m; j++){
			printf("%f\t", Q[i][j]);
		
		}
		printf("\n");
	}
	printf("\n");

	//Imprimimos la matriz R
	printf("Imprimimos la matriz R\n");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			printf("%f\t", R[i][j]);
		
		}
		printf("\n");
	}
	printf("\n");

return 0;
}



float valor_c ( float a, float b ){   

	float r, c_i, s_i;

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

float valor_s ( float a, float b ){   

	float r, c_i, s_i;

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







