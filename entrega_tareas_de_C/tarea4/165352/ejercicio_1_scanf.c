#include<stdio.h>
#define MAX_LONG 100

int longitud_string(char *s){
	int i;
	i=0;
	while(*s != '\0'){
		i++;
		s=s+1;
	}

return i;
}

int main(){
	char string[MAX_LONG];
	int longitud, i, contador = 0;
	int longitudes[4];
	int k=0;

	scanf("%[^EOF]s", string);
	longitud = longitud_string(string);

	//printf("%s\n", string);


	for(i=0; i<longitud; i++)
	{
		if(string[i]==' '||string[i]=='\n')
		{
			printf(" %d\n", contador);
			contador = 0;
			k++;
		}
		else
		{
			printf("%c", string[i]);
			contador++;
		}

	}

return 0;
}


