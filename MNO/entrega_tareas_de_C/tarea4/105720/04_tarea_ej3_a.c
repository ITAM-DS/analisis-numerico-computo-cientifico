// Tarea 4

// 105720
// Sonia Mendizabal Claustro


// Ejercicio 3a
// Modifica esta función de modo que haga este chequeo:
// * Si el string tiene más de un caracter entonces devuelve el string sin el caracter inicial.
// * Si no se cumple lo anterior entonces devuelve un mensaje de error.




# include <stdio.h>
# include <string.h>

char *corta_string(char *apuntador){
    int l; 
    l = strlen(apuntador);
    if(l > 0){
        apuntador = apuntador+1;
        return apuntador;
    }else{
        printf("Longitud %d \n", l);
        return "ERROR";
    }  
}

int main(void){
    char *s="Campos verdes";
    // char *s = "";
    s = corta_string(s);
    printf("%s\n", s);
 
return 0;
}