
#include<stdio.h>


/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0dfU   /* constant vector a */
#define UPPER_MASK 0x80000000U /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffU /* least significant r bits */

/* Tempering parameters */
#define TEMPERING_MASK_B 0x9d2c5680U
#define TEMPERING_MASK_C 0xefc60000U
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)


#define	NUM_RNG	100		/* JTD */


static unsigned long mt[NUM_RNG][N]; /* the array for the state vector  */
/* was static int mti=N+1;  mti[x]==N+1 means mt[x][N] is not initialized */
static int mti[NUM_RNG]; /* mti[x]==N+1 means mt[x][N] is not initialized */


/*+ Call this before sgenrand. +*/
static void init_twister(void)
{
    int		i;

    for (i = 0; i < NUM_RNG; i++) {
	mti[i] = N+1;	/* mti[x]==N+1 means mt[x][N] is not initialized */
    }
}


/*+ initializing the array with a NONZERO seed. +*/
static void sgenrand(unsigned long int rng_num, unsigned long seed)
{
    /* setting initial seeds to mt[x][N] using         */
    /* the generator Line 25 of Table 1 in          */
    /* [KNUTH 1981, The Art of Computer Programming */
    /*    Vol. 2 (2nd Ed.), pp102]                  */
    mt[rng_num][0]= seed & 0xffffffffU;
    for (mti[rng_num]=1; mti[rng_num]<N; mti[rng_num]++)
        mt[rng_num][mti[rng_num]] = (69069 * mt[rng_num][mti[rng_num]-1]) &
	    0xffffffffU;
}


/*+ Make a random number. +*/
static unsigned long genrand(unsigned long int rng_num)
{
    unsigned long y;

    static int	first = 1;
/* was static unsigned long mag01[2]={0x0, MATRIX_A}; */
    static unsigned long mag01[NUM_RNG][2];
    /* mag01[rng_num][x] = x * MATRIX_A  for x=0,1 */

    assert(rng_num < NUM_RNG);

	/* Init mag01 */
    if (first == 1) {
	int	i;

	for (i = 0; i < NUM_RNG; i++) {
	    mag01[i][0] = 0x0;
	    mag01[i][1] = MATRIX_A;
	}

	first = 0;
    }

    if (mti[rng_num] >= N) { /* generate N words at one time */
        int kk;

        if (mti[rng_num] == N+1) /* if sgenrand() has not been called, */
            sgenrand(rng_num, 4357);	 /* a default initial seed is used   */

        for (kk=0;kk<N-M;kk++) {
            y = (mt[rng_num][kk]&UPPER_MASK)|(mt[rng_num][kk+1]&LOWER_MASK);
            mt[rng_num][kk] = mt[rng_num][kk+M] ^
		(y >> 1) ^ mag01[rng_num][y & 0x1];
        }
        for (;kk<N-1;kk++) {
            y = (mt[rng_num][kk]&UPPER_MASK)|(mt[rng_num][kk+1]&LOWER_MASK);
            mt[rng_num][kk] = mt[rng_num][kk+(M-N)] ^
		(y >> 1) ^ mag01[rng_num][y & 0x1];
        }
        y = (mt[rng_num][N-1]&UPPER_MASK)|(mt[rng_num][0]&LOWER_MASK);
        mt[rng_num][N-1] = mt[rng_num][M-1] ^
	    (y >> 1) ^ mag01[rng_num][y & 0x1];

        mti[rng_num] = 0;
    }

    y = mt[rng_num][mti[rng_num]++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);

    return y;
}


/*+ Open a file, exit with message on exit on failure. +*/
static FILE * Vfopen(const char *FileName, const char *mode)
{
    FILE	*fp;

    assert(FileName != NULL);
    assert(strlen(FileName) > 0);
    assert(mode != NULL);

    fp = fopen(FileName, mode);
    if (fp == NULL) {
	fprintf(stderr, "erfi: Fatal Error: failed to open "
		"file '%s' in mode '%s'", FileName, mode);
	exit(EXIT_FAILURE);
    }
    return fp;
}


/*+ Write output to ERFI_OUT environment variable or stderr. */
static void Write_Output(const char *buf,  FA)
{
    FILE	*fp;

    if (Print_File_Name != NULL && FA == ERFI_Print_Env) {
	fp = Vfopen(Print_File_Name, "a");
	fprintf(fp, buf);
	fclose(fp);
    } else {
	fprintf(stderr, buf);
    }
}
