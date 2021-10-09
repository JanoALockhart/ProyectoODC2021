#include<stdlib.h>

#include "convertirEntero.h"
#include "convertirFraccionario.h"
#include "impresion.h"
#include "almacenamientoParam.h"
#include "Util.h"

/**
Procedimiento que, dada una estructura de tipo tArgumentos1,
separa por un lado la parte entera y por otro la parte fraccionaria.
Luego transforma estos desde la base de origen a base 10 con
el m�todo correspondiente. Los numeros obtenidos son pasados
de la base 10 a la base destino con los m�todos correspondientes.
Por �ltimo, se muestra el numero obtenido por pantalla.
Par�metro:
    -p: Puntero a una estructura con todos los par�metros necesarios.
        Se asume que todos fueron verificados previamente.
*/
void cambioDeBaseNumero(tArgumentos1* p){
    long int * decimalB10;
    float * fractionaryB10;
    char * decimalPartNumber;
    char * fractionaryPartNumber;
    char * decimalBF;
    char * fractionaryBF;
    int * vervose;
    int * originBase;
    int * destinationBase;

    decimalB10=(long int *) malloc(sizeof(long int));
    fractionaryB10=(float *) malloc(sizeof(float));
    decimalBF=(char *) malloc(sizeof(char)*10);
    fractionaryBF=(char *) malloc(sizeof(char)*5);
    vervose = (int *) malloc(sizeof(int));
    originBase = (int *) malloc(sizeof(int));
    destinationBase = (int *) malloc(sizeof(int));
    decimalPartNumber=(char *) malloc(sizeof(char));
    fractionaryPartNumber=(char *) malloc(sizeof(char));

    *vervose = p->argV;
    *originBase=atoi(p->argS);
    *destinationBase=atoi(p->argD);

    separateComma(p->argN, decimalPartNumber, fractionaryPartNumber);
    decimalB10=decimalOBaseT10Base(decimalPartNumber, originBase, vervose);
    fractionaryB10=transformarFraccionarioAB10(fractionaryPartNumber, *originBase, p->argV);

    decimalBF=decimal10BaseTDBase(decimalB10, destinationBase, vervose);
    fractionaryBF=transformarFraccionarioABaseDestino(*fractionaryB10, *destinationBase, p->argV);

    mostrarResultadoFinal(p->argN,p->argS,p->argD,decimalBF, fractionaryBF);

    free(decimalB10);
    free(fractionaryB10);
    free(decimalBF);
    free(fractionaryBF);
    free(vervose);
    free(destinationBase);
    free(decimalPartNumber);
    free(fractionaryPartNumber);
    free(originBase);
}
