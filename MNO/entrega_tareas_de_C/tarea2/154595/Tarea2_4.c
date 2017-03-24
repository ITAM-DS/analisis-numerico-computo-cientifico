#include <stdio.h>
#include <unistd.h>

int main(void){
    char ch;
    int i=0;
	while(read(STDIN_FILENO, &ch, 1) > 0)
	{
 		if(ch == '\n') 
 		{
            i++;
        }
	}
    printf("El número de filas es:%i\n", ++i);
}