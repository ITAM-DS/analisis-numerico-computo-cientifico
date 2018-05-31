#include <stdio.h>
#include <stdlib.h>
#include "blas.h"

int main()
{
        double  m[10],n[10];
        int i;
        int result;

        printf("Poner elementos de primer vector.\n");
        for(i=0;i<10;i++)
        scanf("%lf",&m[i]);

        printf("Poner elementos de segundo vector.\n");
        for(i=0;i<10;i++)
        scanf("%lf",&n[i]);

        result = cblas_ddot(10, m, 1, n, 1);
        printf("Resultado: %d\n",result);

        return 0;
}
