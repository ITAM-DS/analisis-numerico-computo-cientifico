#include<stdio.h>
#include<string.h>
#define MAX_LONG 200
int main(void){
char word[MAX_LONG]; //se define y declara la variable donde se guardaran las palabras que se iran escaneando

while (scanf("%s", word)!=EOF){
  printf("longitud %s: %d\n", word, strlen(word));
 }
return 0;
} 
