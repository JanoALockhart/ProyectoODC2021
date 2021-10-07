#include "convertirEntero.h";

#include "convertirFraccionario.h";

#include "impresion.h";

/**
Procedimiento que, dada una estructura de registroParametros con parametros válidos, o bien realiza las conversiones e imprime el resultado o bien imprime la ayuda de ser necesaria.
Atributo:
    -p: Puntero a una estructura con todos los parametros necesarios. Se consideran que están todos correctos.
*/
int ejecuccion(struc registroParametros * p){
    int * decimalB10;
    float * fractionaryB10;
    char * decimalBF;
    char * fractionaryBF;
    decimalB10=(int *) malloc(sizeof(int));
    fractionaryB10=(float *) malloc(sizeof(float));
    decimalBF=(char *) malloc(sizeof(char));
    fractionaryBF=(char *) malloc(sizeof(char));
    if(p->argH) printf("AYUDA");
    else{
        separateComma(p->argN, decimalB10, fractionaryB10);
        *decimalB10=decimalOBaseT10Base(decimalB10, p->argS, *(p->argV));
        *fractionaryB10=transformarFraccionarioAB10(fractionaryB10, p->argS, *(p->argV));
        *decimalBF=decimal10BaseTDBase(decimalB10, p->argD, *(p->argV));
        *fractionaryBF=transformarFraccionarioABaseDestino(fractionaryB10, p->argD, *(p->argV);
        mostrarResultadoFinal(decimalBF, fractionaryBF);
    }
    free(decimalB10);
    free(fractionaryB10);
    free(decimalBF);
    free(fractionaryBF);
}
