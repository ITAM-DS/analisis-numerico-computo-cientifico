#include<stdio.h>

int string_length(char*);
void reverse(char*);

main()
{
    char texto[] = "hola que tal, tarea ejercicio 4";
    char *s;
    s  = (char *)  malloc(sizeof(texto));
    strcpy(s,texto);

   reverse(s);
   printf("El texto al derecho es \"%s\".\n", texto);
   printf("El texto al reves es \"%s\".\n", s);
   return 0;
}

void reverse(char *s)
{
   int length, c;
   char *begin, *end, temp;

   length = string_length(s);
   begin  = s;
   end    = s;

   for (c = 0; c < length - 1; c++)
      end++;

   for (c = 0; c < length/2; c++)
   {
      temp   = *end;
      *end   = *begin;
      *begin = temp;
      begin++;
      end--;
   }
}

int string_length(char *pointer)
{
   int c = 0;

   while( *(pointer + c) != '\0' )
      c++;

   return c;
}
