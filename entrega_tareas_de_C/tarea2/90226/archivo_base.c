include <stdio.h>
main(void) {
    int c;
    c = getchar();
    while (c !=EOF){
        putchar(c);
        c = getchar();
    }
}
