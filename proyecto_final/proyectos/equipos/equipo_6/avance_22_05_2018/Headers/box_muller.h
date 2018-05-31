#include <math.h>
// Define number of variables
static unsigned NUMBER_VARIABLES;

// Define number of equalities and inequalities
static unsigned NUMBER_EQUALITIES;
static unsigned NUMBER_INEQUALITIES;

void normal_generator(double *d){

/*The algorith creates them in pairs, so one entry may need to be discarded */
  unsigned discard = NUMBER_VARIABLES % 2;
  unsigned discard_index = rand()%NUMBER_VARIABLES ;
  double U1, U2, W, mult;

  for(int i = 0; i< NUMBER_VARIABLES ; i +=2 )
  {
    do
    {
      U1 = -1 + ((double) rand () / RAND_MAX) * 2;
      U2 = -1 + ((double) rand () / RAND_MAX) * 2;
      W = pow (U1, 2) + pow (U2, 2);
    }while (W >= 1 || W == 0);

    mult = sqrt ((-2 * log (W)) / W);

    if( discard & (discard_index == i || discard_index == i+1 ))
    {
        d[i] = U1 * mult;
        i--;
    }else{
        d[i] = U1 * mult;
        d[i+1] = U2 * mult;
    }
  }
  double a =0;

  for(int j = 0 ; j<NUMBER_VARIABLES; j++)
  {
    a += d[j];
  }

  for(int j = 0 ; j<NUMBER_VARIABLES; j++)
  {
    d[j] = d[j]/a;
  }

} // END of normal_generator
