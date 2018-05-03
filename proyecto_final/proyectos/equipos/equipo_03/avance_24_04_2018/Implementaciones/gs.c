#include <stdio.h>
#include <math.h>


float dot_product(float col1[], float col2[], int filas)
{
    float result = 0.0;
    for (int i = 0; i < filas; i++)
        result += col1[i]*col2[i];
    return result;
}

int main(void){
	int r, c, i, j, q;
	float zero = 0.0;

	printf("Ingresa el número de filas de matriz:");
    	scanf("%d", &r);
    	printf("Ingresa el número de columnas de la matriz:");
    	scanf("%d", &c);

	
	float V[c][r], U[c][r], tmp[c][r];

	//Leemos la matriz, columna por columna
	for(i = 0; i < c; i++){
		for(j = 0; j < r; j++){
			printf("Ingresa el valor %d de la columna %d:", j, i);
			scanf("%f", &V[i][j]);
			U[i][j] = 0.0;
			tmp[i][j] = 0.0;
		}
	}
	printf("\n");

	printf("Imprimimos la matriz A\n");
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			printf("%f ", V[j][i]);
		
		}
		printf("\n");
	}
	printf("\n");

	//Creamos la primer columna de la matriz Q
	for(j = 0; j < r; j++){
		U[0][j] = V[0][j]/sqrt(dot_product(V[0],V[0],r));
		tmp[0][j] = V[0][j]/sqrt(dot_product(V[0],V[0],r));
	}
		
	
	for(i = 1; i < c; i++){
		for(q = 0; q < r; q++){			
			U[i][q] = V[i][q];
			tmp[i][q] = V[i][q];
		}
		
		for(j = 0; j < i; j++){
			for(q = 0; q < r; q++){	
				U[i][q] = tmp[i][q] - (dot_product(tmp[i],tmp[j],r)/dot_product(tmp[j],tmp[j],r)) * tmp[j][q];
			}
			for(q = 0; q < r; q++){			
				tmp[i][q] = U[i][q];			
			}
		}
		for(q = 0; q < r; q++){			
				U[i][q] = tmp[i][q]/sqrt(dot_product(tmp[i],tmp[i],r));			
			}
		for(q = 0; q < r; q++){			
				tmp[i][q] = U[i][q];			
			}	
	}

	printf("Imprimimos la matriz Q\n");
	for(i = 0; i < r; i++){
		for(j = 0; j < c; j++){
			printf("%f ", U[j][i]);
		
		}
		printf("\n");
	}

	printf("\n");
	
	printf("Imprimimos la matriz R\n");
	for(i = 0; i < c; i++){
		for(j = 0; j < c; j++){
			if(i <= j){
				printf("%f ", dot_product(V[j],U[i],r));
			}else{
				printf("%f ", zero);
			}
		}
		printf("\n");
	}
	
return 0;
}
