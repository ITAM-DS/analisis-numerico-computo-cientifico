
/*
Tarea Eduardo Hidalgo 
Calculo Numerico
000117036
2018/01/29
*/

#include<stdio.h>
#include<math.h>


 main(){
      	//Valores "Reales" (a 8 digitos) 
	double valorx8 = 0.71428571; 
	double valory8 = 0.33333333;   	
	double valoru8 = .714251;
	double valorv8 = 98765.9;	
	double valorw8 = .111111e-4;
	//Valores "De Máquina" (a 5 digitos)
	double valorx5;
	double valory5;
	double valoru5;	
	double valorv5;
	double valorw5;
	 //Inicializando los valores con base en el valor "Real"   	
	valorx5 = truncf(valorx8*1e5)*1e-5;	
   	valory5 = truncf(valory8*1e5)*1e-5;
	valoru5 = truncf(valoru8*1e5)*1e-5;
	valorv5 = truncf(valorv8*1e5)*1e-5;
	valorw5 = truncf(valorw8*1e5)*1e-5;
   	
// x -y

   	double restarealxy 	= valorx8 - valory8; 						// Valor "Real" resta x con y
   	double restamaqlxy	= truncf( valorx5*1e5 - valory5*1e5)*1e-5; 	// Valor en "Aritmética de Máquina" de la resta x con y  
   	double errorabsrestaxy	= fabs( restarealxy - restamaqlxy);    		// error absoluto
   	double errorrelrestaxy	= errorabsrestaxy/restarealxy	;					// error relativo



// x / y

   	double divrealxy	= valorx8 / valory8; 								// Valor "Real" division x con y
   	double divrmaqxy	= truncf( (valorx5*1e5) / (valory5*1e5))*1e-5 ;		// Valor en "Aritmética de Máquina" de la division x con y
   	double errorabsdivxy	= fabs( divrealxy- divrmaqxy)  ;   				// error absoluto
   	double errorreldivxy	= errorabsdivxy/divrealxy	;							// error relativo


// (x-u)/w

   	double divrestarealxuw 	= (valorx8 - valoru8)/ valorw8; 										// Valor "Real" de la resta de x con y divida de w
   	double divrestamaqxuw	= truncf( ((valorx5*1e5 - valoru5*1e5 ) / (valorw5*1e5)*1e5) )*1e-5 ;	// Valor en "Aritmética de Máquina" de la resta de x con y divida de w
   	double errorabsdivrestaxuw	= fabs( divrestarealxuw - divrestamaqxuw)     ;								// error absoluto
   	double errorreldivrestaxuw	= errorabsdivrestaxuw/divrestarealxuw		;										// error relativo



// u + v

   	double sumarealuv 	= valoru8 + valorv8; 						// Valor "Real" de la suma u con v
   	double sumamaquv	= truncf( valoru5*1e5 + valorv5*1e5)*1e-5 ;	// Valor en "Aritmética de Máquina" de la suma u con v
   	double errorabssumauv	= fabs( sumarealuv - sumamaquv)   ;  		// error absoluto
   	double errorrelsumauv	= errorabssumauv/sumarealuv		;				// error relativo


printf( "\n Operación | Valor Real | Maq   | Abs.Err.| Rel.Er.|    \n");

printf( "\n   x-y         %1.4e      %1.4e    %1.4e    %1.4e   \n", restarealxy, restamaqlxy, errorabsrestaxy, errorrelrestaxy);

printf( "\n   x/y        %1.4e      %1.4e    %1.4e    %1.4e   \n", divrealxy, divrmaqxy, errorabsdivxy, errorreldivxy);

printf( "\n (x-u)/w      %1.4e      %1.4e    %1.4e    %1.4e   \n", divrestarealxuw, divrestamaqxuw, errorabsdivrestaxuw, errorreldivrestaxuw);

printf( "\n   u+v        %1.4e      %1.4e    %1.4e    %1.4e   \n", sumarealuv, sumamaquv, errorabssumauv, errorrelsumauv);


}
