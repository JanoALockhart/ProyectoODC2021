#include<stdlib.h>

#include "convertirEntero.h"
#include "convertirFraccionario.h"
#include "impresion.h"
#include "almacenamientoParam.h"
#include "Util.h"

/**
Procedimiento que, dada una estructura de registroParametros con parametros v�lidos, o bien realiza las conversiones e imprime el resultado o bien imprime la ayuda de ser necesaria.
Atributo:
    -p: Puntero a una estructura con todos los parametros necesarios. Se consideran que est�n todos correctos.
*/
void ejecuccion(tArgumentos1* p){
    int * decimalB10;
    float * fractionaryB10;
    char * decimalPartNumber;
    char * fractionaryPartNumber;
    char * decimalBF;
    char * fractionaryBF;
    int * vervose;
    int * originBase;
    int * destinationBase;

    decimalB10=(int *) malloc(sizeof(int));
    fractionaryB10=(float *) malloc(sizeof(float));
    decimalBF=(char *) malloc(sizeof(char)*10);
    fractionaryBF=(char *) malloc(sizeof(char)*5);
    vervose = (int *) malloc(sizeof(int));
    originBase = (int *) malloc(sizeof(int));
    destinationBase = (int *) malloc(sizeof(int));
    decimalPartNumber=(char *) malloc(sizeof(char));
    fractionaryPartNumber=(char *) malloc(sizeof(char));

    *vervose = p->argV;
    if(p->argH) mostrarAyuda();
    else{
        *originBase=atoi(p->argS);
        *destinationBase=atoi(p->argD);
        separateComma(p->argN, decimalPartNumber, fractionaryPartNumber);
        decimalB10=decimalOBaseT10Base(decimalPartNumber, originBase, vervose);
        fractionaryB10=transformarFraccionarioAB10(fractionaryPartNumber, *originBase, p->argV);

        decimalBF=decimal10BaseTDBase(decimalB10, destinationBase, vervose);
        fractionaryBF=transformarFraccionarioABaseDestino(*fractionaryB10, *destinationBase, p->argV);

        mostrarResultadoFinal(p->argN,p->argS,p->argD,decimalBF, fractionaryBF);
    }

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
