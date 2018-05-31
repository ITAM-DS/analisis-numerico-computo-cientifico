#include <stdio.h>
#include <math.h>

// Mario Vázquez Corte 127252 

void main ()
{
		/*  
			Asumiendo que el arreglo o matriz es de tipo int. Si se desea de otro tipo solo hay que cambiar el tipo en la declaracion del arrelgo y deĺ apuntador correspondiente.
			Lo mismo pasa con el tamaño,

		*/
        int n ;       // Numero de filas
        int m;      // Numero de columnas


        // Si se desea imprimir un vector el indicador de columna debe ir en 1 v[a][1];
		int v[5][3] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; 	// Defino el vector o matriz
		int *p;		// Defino el apuntador

		p = &v[0][0];		// Guardo el address del vector o matriz en el apuntador de p
        
        n= sizeof(v)/sizeof(v[0]); // encuientra el numero de de filas
        m= sizeof(v)/sizeof(v[0][0])/n; // encuentra el numero de columnas
        
        printf(" rows = %d \n",n);
        printf(" col  = %d \n -------------------- \n",m);
        
       
        contentsprint(p,n,m);		// imprime las entradas impares del vector
        addressprint(p,n,m);

        

        // matrixprint(p,n,m);		// imprime el address del vector




}

/* Imprime los valores  */

void contentsprint (int *pf, int n, int m)
{		
		

	printf("\n ---   Elements   --- \n");

	if(m==1) // vector 
	{	

		for(int i = 0; i< n ; i = i+2)
		{
			
			printf(" v[%d] = %d \n", i, *(pf+i));
			
		}
	}else  //matriz
	{
			int r,c;
			r=0;
			c=0;


		for(int i = 0; i< (n*m); i = i+2)
		{	

				
			printf(" v[%d][%d] = %d \n", r,c,*(pf+i));
			c +=2;
			
			if(c == m)
			{
				r++;
				c=0;
			}else if( c == m+1)
			{
				r++;
				c=1;
			}
			
		}


	}

       
}



/* Impreme las direcciones*/
void addressprint (int *pf, int n, int m)
{		




		printf("\n ---   Address   --- \n");


		if(m==1) //para vectores
		{
			for(int i = 0; i< n ; i = i+2)
			{
			
			
			printf(" &v[%d] = %p \n", i, &pf[i]);
			
			}


		}else  // apra matriz
		{
			int r,c;
			r=0;
			c=0;

			for(int i = 0; i< (n*m); i = i+2)
			{	
			
				
				
				printf(" &v[%d][%d] = %p \n", r,c, &pf[i]);
				c +=2;

				if(c == m)
				{
					r++;
					c=0;
				}else if( c == m+1)
				{
					r++;
					c=1;
				}
			}

		}

	

}


