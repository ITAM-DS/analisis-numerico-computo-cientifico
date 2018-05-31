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
	char str[MAX_LONG];
	int longi, i, counter = 0;
	int j=0;

	scanf("%[^EOF]s", str);
	longi = longitud_string(str);


	for(i=0; i<longi; i++)
	{
		if(str[i]==' '||str[i]=='\n')
		{
			printf(" %d\n", counter);
			counter = 0;
			j++;
		}
		else
		{
			printf("%c", str[i]);
			counter++;
		}

	}

return 0;
}


