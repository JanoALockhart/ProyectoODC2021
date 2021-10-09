#ifndef IMPRESION_H_INCLUDED
#define IMPRESION_H_INCLUDED

<<<<<<< HEAD
void papDecimalOBaseT10Base(float * total, int * n, int * OBase, int * exp);
=======
void papDecimalOBaseT10Base(long int * total, int * n, int * OBase, int * exp);
>>>>>>> f1fbfabbf2f77f95028a7ae047c2605babf64914

void papDecimal10BaseTDBase(long int * n, int * b, int * r);

void papFractionaryOBaseT10Base(float* total, int * n, int * OBase, int * exp);

void papFractionary10BaseTDBase(int * TBase, float * n, int * digit);

void mostrarResultadoFinal(char * numOriginal, char * bOrigen, char * bDestino, char * resultadoEntero, char * resultadoFraccional);

void mostrarError(int nroError);

void mostrarAyuda();

void directConv(long int * n, int * base);

void imprimirRaya(int largo,char carac);

void mostrarTitulo(char * titulo);

void msgConversionDirecta();

#endif // IMPRESION_H_INCLUDED
