//MNO: tarea 2, inciso 3 y 4
//Autor: Mónica Vargas
//CU. 129318
 

#include <stdio.h>

 int main(void) {
    unsigned long int charcount = 0;
    unsigned long int wordcount = 0;
    unsigned long int linecount = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if ((c != ' ') && (c != '\n')) {
            charcount++;
        }
        if ((c == ' ') || (c == '\n')) {
            wordcount++;
        }
        if (c == '\n') {
            linecount++;
        }
    }

    printf("%lu %lu %lu\n", charcount, wordcount, linecount);
    return 0;
}
