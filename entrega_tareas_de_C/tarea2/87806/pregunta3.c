#include <stdio.h>
main(void)
{
	double cuenta;
    	cuenta = 0;
	while(getchar() != '\n')
        	cuenta=cuenta+1;
	printf("\n%.0f\n",cuenta);
}
