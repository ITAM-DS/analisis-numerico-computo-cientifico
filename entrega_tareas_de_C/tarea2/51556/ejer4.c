#include<stdio.h> 

void main(void){
          int c;
          int n=0;
          int line=0;
          char lc;
          while((c=getchar())!=EOF){
                
             lc=c;
             if(lc=='\n') {
                 ++line;
          
             }
                
             ++n;

          }          
       printf("lineas: %d\n",line);
       printf("\n");

       
}
