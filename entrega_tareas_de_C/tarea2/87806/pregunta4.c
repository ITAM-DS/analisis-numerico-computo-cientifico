#include <stdio.h>
main(void)
{
        int c,lineas;
	lineas = 0;
        while((c=getchar()) != EOF)
		if (c=='\n')
			lineas=lineas+1;
        printf("\n%d\n",lineas);
}


