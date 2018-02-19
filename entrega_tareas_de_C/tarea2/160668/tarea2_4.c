#include <ctype.h>
#include <stdio.h>

int main(void) {

    int linecount = 0;
    int c, last;

    for (last = '\n'; (c = getchar()) != EOF; last = c) {

        if (c == '\n') 
            linecount++;
    }
    if (last != '\n') {
        linecount++;
    }
    printf("%d \n", linecount);
    return 0;
}
