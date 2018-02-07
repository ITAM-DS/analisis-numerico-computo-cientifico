#include <stdio.h>

int main(void) {
    int charcount=0;
    int c;

    while ( (c = getchar()) != '\n' && c !=EOF)
	charcount++;

   printf("%d \n",charcount);
   return 0;
}
