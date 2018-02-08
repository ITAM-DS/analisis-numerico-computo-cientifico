// Tarea de equipo 13: x+y, xy, x-u, (x-u)v

#include<stdio.h>
#include<math.h>


// Funcion para truncar z hasta i posiciones
double trnc(double z, int i){
	return truncf(z * pow(10, i - n_ent(truncf(z)))) / pow(10, i - n_ent(truncf(z)));
}

// FUncion cuenta enteros
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

main(){
	// Definicion de variables
	double x,y,u,v,val_ocho,val_cinco;
	u = 0.714251;
	v = 98765.9;
	x = 5.0/7.0;
	y = 1.0/3.0;

	// X + Y
	val_ocho = truncf((x+y)*pow(10,8-n_ent(truncf(x+y))))/pow(10,8-n_ent(truncf(x+y)));
	printf(" X + Y \n");
	printf("Valor 8: %1.8f\n", val_ocho);
	
	val_cinco = trnc(trnc(x, 5) + trnc(y, 5), 5);
	printf("Aritmetica de maquina: %1.8f\n", val_cinco);
	printf("Error tipo A: %1.8f\n", val_ocho - val_cinco);
	printf("Error tipo B: %1.8f\n", (val_ocho - val_cinco) / val_ocho);


	// X * Y
	val_ocho = truncf((x*y)*pow(10,8-n_ent(truncf(x*y))))/pow(10,8-n_ent(truncf(x*y)));
	printf(" X * Y \n");
	printf("Valor 8: %1.8f\n", val_ocho);
	
	val_cinco = trnc(trnc(x, 5) * trnc(y, 5), 5);
	printf("Aritmetica de maquina: %1.8f\n", val_cinco);
	printf("Error tipo A: %1.8f\n", val_ocho - val_cinco);
	printf("Error tipo B: %1.8f\n", (val_ocho - val_cinco) / val_ocho);


	// X - U
	val_ocho = truncf((x-u)*pow(10,8-n_ent(truncf(x-u))))/pow(10,8-n_ent(truncf(x-u)));
	printf(" X - U \n");
	printf("Valor 8: %1.8f\n", val_ocho);
	
	val_cinco = trnc(trnc(x, 5) - trnc(u, 5), 5);
	printf("Aritmetica de maquina: %1.8f\n", val_cinco);
	printf("Error tipo A: %1.8f\n", val_ocho - val_cinco);
	printf("Error tipo B: %1.8f\n", (val_ocho - val_cinco) / val_ocho);


	// (X - U) * V
	val_ocho = truncf(((x-u)*v)*pow(10,8-n_ent(truncf((x-u)*v))))/pow(10,8-n_ent(truncf((x-u)*v)));
	printf(" (X - U) * V \n");
	printf("Valor 8: %1.8f\n", val_ocho);
	
	val_cinco = trnc((trnc(x, 5) - trnc(u, 5)) * trnc(v, 5), 5);
	printf("Aritmetica de maquina: %1.8f\n", val_cinco);
	printf("Error tipo A: %1.8f\n", val_ocho - val_cinco);
	printf("Error tipo B: %1.8f\n", (val_ocho - val_cinco) / val_ocho);

}
