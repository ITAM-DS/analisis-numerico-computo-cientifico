/* Tarea 4 114535 - Parte 2 */
#include <stdio.h>
#define MAX_LONG 200

int main()
{
	char text[MAX_LONG]; 
	int len=0,i=0;
	
	scanf("%[^\n]s",text); 
	printf("longitud ");
	while(1){
		// if you get to end of word or line
		if(text[i]==' ' || text[i]=='\0'){
			//check end of string
			if(text[i]=='\0'){
				if(len>0){
					printf(": %d\n", len);
					len=0;
				}
				break; 
			}
			// You are at end of word, print len
			printf(": %d \nlongitud ", len);
			// & restart counter
			len=0;
		}
		else{
			printf("%c", text[i]);
			len++;
		}		
		i++;
	}
	return 0;
}
