#include <stdio.h>
#include <stdlib.h>

// Area bajo 'curva' y = x^2 en un plano 1x1

int main()
{
    float i, n = 99999.0, puntos_bajo_curva = 0.0;
    long double randX, randY;

    srand(time(NULL)+1);

    for (i = 0; i < n; ++i) {
      randX = rand() / (double)RAND_MAX;
      randY = rand() / (double)RAND_MAX;
      if (randX * randX > randY) ++puntos_bajo_curva;
    }


    printf("AREA: puntos_bajo_curva/n:\n");
    printf("%f\n", (puntos_bajo_curva/n));

    return 0;
}
