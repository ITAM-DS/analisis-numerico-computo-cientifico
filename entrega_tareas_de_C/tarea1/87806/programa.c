// Alejandro Hernandez Farias, Clave Unica: 87806
// Equipo 13, por lo tanto me tocan los ejercicios impares.
// Ejercicios impares: x+y, xy, x-u, (x-u)v
// Considero: beta=10, k=5  â

#include<stdio.h>
#include<math.h>

// Hago funcion para contar enteros
int n_ent(int entero){
	int n=entero;
	int count=0;
	if (n==0){
		count=0;
	}
	else{
		while(n != 0 ){
			n/=10;
			++count;
		}
	}
	return count;
}


// Hago una funcion para truncar tomando en cuenta los enteros 
double truncar(double valor, int k){
	return  truncf(valor*pow(10,k-n_ent(truncf(valor))))/pow(10,k-n_ent(truncf(valor)));

}


main(){
	//Defino variblesâ
	double x,y,u,v,w,suma_8,suma_5,mult_8,mult_5,dif_8,dif_5,dif_mult_8,dif_mult_5;
	//Inicializo variables:
	u = 0.714251;
	v = 98765.9;
	w = 111111e-4;
	x = 5.0/7.0;
	y = 1.0/3.0;

	// X+Y:
	suma_8 = truncar(x+y,8);
	suma_5 = truncar(truncar(x,5)+truncar(y,5),5);
	printf("X+Y\n");
	printf("Valor a 8: %1.8f\n", suma_8);
	printf("Aritmetica de maquina: %1.5f\n", suma_5);
	printf("ErrA: %1.8f\n",suma_8-suma_5);
	printf("ErrB: %1.8f\n\n",(suma_8-suma_5)/suma_8);

	// X*Y:
        mult_8 = truncar(x*y,8);
        mult_5 = truncar(truncar(x,5)*truncar(y,5),5);
        printf("X*Y\n");
        printf("Valor a 8: %1.8f\n", mult_8);
        printf("Aritmetica de maquina: %1.5f\n", mult_5);
        printf("ErrA: %1.8f\n",mult_8-mult_5);
        printf("ErrB: %1.8f\n\n",(mult_8-mult_5)/mult_8);

	// X-U:
        dif_8 = truncar(x-u,8);
        dif_5 = truncar(truncar(x,5)-truncar(u,5),5);
        printf("X-U\n");
        printf("Valor a 8: %1.8f\n", dif_8);
        printf("Aritmetica de maquina: %1.5f\n", dif_5);
        printf("ErrA: %1.8f\n",dif_8-dif_5);
        printf("ErrB: %1.8f\n\n",(dif_8-dif_5)/dif_8);

	// (X-U)*V:
        dif_mult_8 = truncar((x-u)*v,8);
        dif_mult_5 = truncar((truncar(x,5)-truncar(u,5))*truncar(v,5),5);
        printf("(X-U)*V\n");
        printf("Valor a 8: %1.8f\n", dif_mult_8);
        printf("Aritmetica de maquina: %1.5f\n", dif_mult_5);
        printf("ErrA: %1.8f\n",dif_mult_8-dif_mult_5);
        printf("ErrB: %1.8f\n\n",(dif_mult_8-dif_mult_5)/dif_mult_8);
}


// Nota: para compilar tuve que incoporar -lm para que poder "ligar" la libreria math 
// a la compilacion con gcc de la siguiente manera "gcc -o programa.out programa.c -lm" 
