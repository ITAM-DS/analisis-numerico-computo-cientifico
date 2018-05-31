/*
Eduardo Hidalgo Garcia
000117036
Programa para contar caracteres
$echo -e "texto para contar caracteres\n" | ./ejecutable.out
*/

#include <stdio.h>

main(void)
{
int c ;
int count ;

while ( ( c = getchar() ) != EOF )
   count ++ ;

printf( "%d characters\n" , count ) ;
}
