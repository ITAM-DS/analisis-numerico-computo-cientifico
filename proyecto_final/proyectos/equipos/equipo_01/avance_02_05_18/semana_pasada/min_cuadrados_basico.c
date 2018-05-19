#include <stdio.h>
#include <math.h>
#include<stdio.h>

//declaracion de funciones
void input_data(int Dat,  float Val[][102], FILE *pFile);
void prepara_sistema(int Ord,  int Dat,  float Sist[][102],  float Val[][102]);
void resuelve_Gauss(int Dim,  float Sist[][102]);
void write_data(int Dim,  float Sist[][102]);


int main(int argc, char *argv[]) {
    int Datos, Orden, C;
    
    float Valores[2][102], Sistema[102][102];
    FILE * pFile;
    pFile = fopen (argv[1],"r");
    fscanf(pFile, "%d", &Datos);
    fscanf(pFile, "%d", &Orden);

    printf("\n\n Metodo de minimmos cuadrados\n\n");
    printf("\n numero de datos (Puntos): %d", Datos);
    printf("\n El orden del polinomio: %d \n\n", Orden); 

    //llamada para introducir los valores en consola.
    input_data( Datos, Valores, pFile);
    fclose(pFile);

    Orden++;
    //esta funcion prepara el sistema de ecuaciones basado en los puntos
    prepara_sistema(Orden, Datos, Sistema, Valores);
    
    printf("\n\n El sistema a resolver es el siguiente:");
    write_data(Orden, Sistema);
    resuelve_Gauss(Orden, Sistema);
    printf("\n\n El sistema resuelto:");
    write_data(Orden, Sistema);
    printf("\n\n La Ecuacion del Polinomio ajustado por minimos Cuadrados\n\n:");
    for(C=1;C<=Orden;C++)
        printf(" + (%f)X^%d", Sistema[C][Orden+1], C-1);

    return(0);
}



void input_data(int Dat, float Val[][102], FILE *pFile) {
    int A;
    
    //ciclo de lectura de datos.
    for(A=1;A<=Dat;A++) {
        printf("\n Valores del Punto %d:  ", A);
        fscanf(pFile, "%f", &Val[0][A]);
        fscanf(pFile, "%f", &Val[1][A]);
        printf("   X%d: %f", A, Val[0][A]); 
        printf("   Y%d: %f", A, Val[1][A]);
    }
    
}


//funcion que genera el sistema de ecuaaciones apartir de los puntos capturados
void prepara_sistema(int Ord,  int Dat,  float Sist[][102],  float Val[][102]) {
    int A, B, C, Exp;
    float suma, termino;
    
    for(A=1;A<=Ord;A++)    
        for(B=1;B<=Ord;B++) {
            suma=0;
            Exp=A+B-2;
            for(C=1;C<=Dat;C++) {
                termino=Val[0][C];
                suma=suma+pow(Exp, termino);
            }
            Sist[A][B]=suma;
        }

    for(A=1;A<=Ord;A++) {
        suma=0;
        Exp=A-1;
       
        for(C=1;C<=Dat;C++) {
            termino=Val[0][C];
            suma=suma+Val[1][C]*pow(Exp, termino);
        }
        Sist[A][Ord+1]=suma;
    }
}

///funcion que resuelve el sistema de ecuacion con la matriz identidad
void resuelve_Gauss(int Dim,  float Sist[][102]) {
    int NoCero, Col, C1, C2, A;
    float Pivote, V1;
    
    for(Col=1;Col<=Dim;Col++) {
        NoCero=0;A=Col;
        while(NoCero==0) {
            if(Sist[A][Col]!=0) {
                NoCero=1;
            } else 
                A++;
        }
        Pivote=Sist[A][Col];
        
        for(C1=1;C1<=(Dim+1);C1++) {
            V1=Sist[A][C1];
            Sist[A][C1]=Sist[Col][C1];
            Sist[Col][C1]=V1/Pivote;
        }
        
        for(C2=Col+1;C2<=Dim;C2++) {
            V1=Sist[C2][Col];
            for(C1=Col;C1<=(Dim+1);C1++) {
                Sist[C2][C1]=Sist[C2][C1]-V1*Sist[Col][C1];
            }
        }
        
    }
    
    for(Col=Dim;Col>=1;Col--) 
        for(C1=(Col-1);C1>=1;C1--) {
            Sist[C1][Dim+1]=Sist[C1][Dim+1]-Sist[C1][Col]*Sist[Col][Dim+1];
            Sist[C1][Col]=0;
        }
}

//funcion que imprime el sistema de ecuaciones solucionado
void write_data(int Dim,  float Sist[][102]) {
    int A, B;
    printf("\n");
    for(A=1;A<=Dim;A++) {
        for(B=1;B<=(Dim+1);B++){
            printf("%7.2f", Sist[A][B]);
            if(B==Dim) printf("   |");}
        printf("\n");
    }
    printf("\n");
}
