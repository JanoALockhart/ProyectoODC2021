#include "convertirEntero.h";
#include "convertirFraccionario.h";
#include "impresion.h";
#include "almacenamientoParam.h"

/**
Procedimiento que, dada una estructura de registroParametros con parametros válidos, o bien realiza las conversiones e imprime el resultado o bien imprime la ayuda de ser necesaria.
Atributo:
    -p: Puntero a una estructura con todos los parametros necesarios. Se consideran que están todos correctos.
*/
int ejecuccion(tArgumentos1* p){
    int * decimalB10;
    float * fractionaryB10;
    char * decimalPartNumber;
    char * fractionaryPartNumber;
    char * decimalBF;
    char * fractionaryBF;
    int * vervose;


    decimalB10=(int *) malloc(sizeof(int));
    fractionaryB10=(float *) malloc(sizeof(float));
    decimalBF=(char *) malloc(sizeof(char));
    fractionaryBF=(char *) malloc(sizeof(char));
    vervose = (int *) malloc(sizeof(int));
    decimalPartNumber=(char *) malloc(sizeof(char));
    fractionaryPartNumber=(char *) malloc(sizeof(char));

    *vervose = p->argV;
    if(p->argH) mostrarAyuda();
    else{
        separateComma(p->argN, decimalPartNumber, fractionaryPartNumber);

        decimalB10=decimalOBaseT10Base(decimalPartNumber, p->argS, vervose);
        fractionaryB10=transformarFraccionarioAB10(fractionaryPartNumber, p->argS, p->argV);

        decimalBF=decimal10BaseTDBase(decimalB10, p->argD, vervose);
        fractionaryBF=transformarFraccionarioABaseDestino(*fractionaryB10, p->argD, p->argV);

        mostrarResultadoFinal(decimalBF, fractionaryBF);
    }
    free(decimalB10);
    free(fractionaryB10);
    free(decimalBF);
    free(fractionaryBF);
    free(decimalPartNumber);
    free(fractionaryPartNumber);
}
