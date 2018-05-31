#include<stdio.h>
#include<math.h>
#define func(x) x*x
int main()
{
      int interval, count;
      float m = 0, n = 0, sum, lower_limit, upper_limit, length,x;
      printf("\nIngresa el numero de iteraciones:\t");
      scanf("%d", &interval);
      interval += (interval % 2);
      printf("\nlimite inferior a:\t");
      scanf("%f", &lower_limit);
      printf("\nlimite superior b:\t");
      scanf("%f", &upper_limit);
      length = (upper_limit - lower_limit) / interval;

            for(count = 1; count <= interval - 1; count++)
            {
             x = lower_limit + count * length;
                  if(count%2 == 0)
                  {
                        m +=  func(x);
                  }
                  else
                  {
                        n += func(x);
                  }
            }
            sum = length / 3 * (func(lower_limit) + func(upper_limit) + 4 * n + 2 * m);
            printf("\nEl resultado es:\t%f\n", sum);

      return 0;
}
