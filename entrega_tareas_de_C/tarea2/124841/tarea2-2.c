#include <stdio.h>
main ( void )
{
 
    int n,c;
    n=0;
   c=getchar();
    while(c != EOF){
     c=getchar();
    if(c=='\n'){ n++;}
    } 
 printf ("El archivo tiene %d lineas.\n", n);



}
