#include <stdio.h>
#include <string.h>

#define MAX_LONG 200

int main(void) {
  char s[MAX_LONG];
  while (scanf("%s", s) != EOF)
    printf("longitud %s %lu\n", s, strlen(s));
  return 0;
}
 