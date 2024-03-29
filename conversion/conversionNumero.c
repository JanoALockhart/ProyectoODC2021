#include<stdlib.h>

#include "conversionNumero.h"
#include "convertirEntero.h"
#include "convertirFraccionario.h"
#include "../util/impresion.h"
#include "../almacenamientoDatos/almacenamientoParam.h"
#include "../util/Util.h"

/**
Procedimiento que, dada una estructura de tipo tArgumentos1,
separa por un lado la parte entera y por otro la parte fraccionaria.
Luego transforma estos desde la base de origen a base 10 con
las funciones correspondiente. Los n�meros obtenidos son pasados
de la base 10 a la base destino con las funciones correspondientes.
Por �ltimo, se muestra por pantalla el numero resultante de
concatenar la parte entera y la parte fraccionaria en la base de destino
Par�metro:
    -p(tArgumentos1*): Puntero a una estructura con todos los par�metros necesarios.
        Se asume que todos fueron verificados previamente.
*/
void cambioDeBaseNumero(tArgumentos1* p){
    double * decimalB10;
    float * fractionaryB10;
    char * decimalPartNumber;
    char * fractionaryPartNumber;
    char * decimalBF;
    char * fractionaryBF;
    int * vervose;
    int * originBase;
    int * destinationBase;

    decimalB10=(double *) malloc(sizeof(double));
    fractionaryB10=(float *) malloc(sizeof(float));
    vervose = (int *) malloc(sizeof(int));
    originBase = (int *) malloc(sizeof(int));
    destinationBase = (int *) malloc(sizeof(int));
    decimalPartNumber=(char *) malloc(sizeof(char)*(10+1));
    fractionaryPartNumber=(char *) malloc(sizeof(char)*(5+1));

    *vervose = p->argV;
    *originBase=atoi(p->argS);
    *destinationBase=atoi(p->argD);

    separateComma(p->argN, decimalPartNumber, fractionaryPartNumber);
    decimalB10=decimalOBaseT10Base(decimalPartNumber, originBase, vervose);
    fractionaryB10=transformarFraccionarioAB10(fractionaryPartNumber, *originBase, p->argV);

    decimalBF=decimal10BaseTDBase(decimalB10, destinationBase, vervose);
    fractionaryBF=transformarFraccionarioABaseDestino(*fractionaryB10, *destinationBase, p->argV);

    if(p->signo && p->argV) mostrarTitulo("Ya que se ingreso un numero negativo, se multiplica por -1 el resultado obtenido.");

    mostrarResultadoFinal(p->argN,p->argS,p->argD,decimalBF, fractionaryBF, p->signo);

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
