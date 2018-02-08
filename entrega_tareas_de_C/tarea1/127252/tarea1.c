/* 
Tarea 1 Analisis Númerico
Mario Vázquez Corte
000127252
*/


#include<stdio.h>
#include<math.h>


 main(){
	double x_8 = 0.71428571; //valor a 8 digitos
   	double x_5 ;
   	x_5 = truncf(x_8*1e5)*1e-5; // valor maquina

    double y_8 = 0.33333333;//valor a 8 digitos
	double y_5 ;
   	y_5 = truncf(y_8*1e5)*1e-5; // valor maquina

	double u_8 = .714251;//valor a 8 digitos
	double u_5 ;
   	u_5 = truncf(u_8*1e5)*1e-5;// valor maquina

	double v_8 = .987659*1e5;//valor a 8 digitos
	double v_5 ;
   	v_5 = truncf(v_8*1e5)*1e-5;// valor maquina

	double w_8 = .111111e-4;//valor a 8 digitos
	double w_5 ;
   	w_5 = truncf(w_8*1e5)*1e-5;// valor maquina



// x -y

   	double valor_1 	= x_8 - y_8; 						// valor de resta aritmetica a 8 digitos
   	double maq_1	= truncf( x_5*1e5 - y_5*1e5)*1e-5; 	// valor de aritmetica de maquina 
   	double abs_1	= fabs( valor_1 - maq_1);    		// error absoluto
   	double rel_1	= abs_1/valor_1	;					// error relativo



// x / y

   	double valor_2 	= x_8 / y_8; 								// valor de resta aritmetica a 8 digitos
   	double maq_2	= truncf( (x_5*1e5) / (y_5*1e5))*1e-5 ;		// valor de aritmetica de maquina 
   	double abs_2	= fabs( valor_2 - maq_2)  ;   				// error absoluto
   	double rel_2	= abs_2/valor_2	;							// error relativo


// (x-u)/w

   	double valor_3 	= (x_8 - u_8)/ w_8; 										// valor de resta aritmetica a 8 digitos
   	double maq_3	= truncf( ((x_5*1e5 - u_5*1e5 ) / (w_5*1e5))*1e5 )*1e-5 ;	// valor de aritmetica de maquina 
   	double abs_3	= fabs( valor_3 - maq_3)     ;								// error absoluto
   	double rel_3	= abs_3/valor_3		;										// error relativo



// u + v

   	double valor_4 	= u_8 + v_8; 						// valor de resta aritmetica a 8 digitos
   	double maq_4	= truncf( u_5*1e5 + v_5*1e5)*1e-5 ;	// valor de aritmetica de maquina 
   	double abs_4	= fabs( valor_4 - maq_4)   ;  		// error absoluto
   	double rel_4	= abs_4/valor_4		;				// error relativo


     
printf("\n   x_8: %1.7e  |   y_8: %1.7e  |   u_8: %1.7e  \n   v_8: %1.7e  |   w_8: %1.7e     \n", x_8,y_8,u_8,v_8,w_8);

printf("\n   x_5: %1.4e  |   y_5: %1.4e  |   u_5: %1.4e  \n   v_5: %1.4e  |   w_5: %1.4e     \n", x_5,y_5,u_5,v_5,w_5);

printf( "\n Operación |    Valor a 8      |    A. de Maq   |      ErrA       |    ErrR    \n");

printf( "\n   x-y     |   %1.7e   |   %1.4e   | %1.7e   | %1.7e   \n", valor_1, maq_1, abs_1, rel_1);

printf( "\n   x/y     |   %1.7e   |   %1.4e   | %1.7e   | %1.7e   \n", valor_2, maq_2, abs_2, rel_2);

printf( "\n (x-u)/w   |   %1.7e   |   %1.4e   | %1.7e   | %1.7e   \n", valor_3, maq_3, abs_3, rel_3);

printf( "\n   u+v     |   %1.7e   |   %1.4e   | %1.7e   | %1.7e   \n", valor_4, maq_4, abs_4, rel_4);


}
