#ifndef IMPRESION_H_INCLUDED
#define IMPRESION_H_INCLUDED

void papDecimalOBaseT10Base(double * total, int * digit, int * OBase, int * exp);

void papDecimal10BaseTDBase(double * c, int * b, int * r);

void papFractionaryOBaseT10Base(float* total, int * n, int * OBase, int * exp);

void papFractionary10BaseTDBase(int * TBase, float * n, int * digit);

void mostrarResultadoFinal(char * numOriginal, char * bOrigen, char * bDestino, char * resultadoEntero, char * resultadoFraccional);

void mostrarError(int nroError);

void mostrarAyuda();

void directConvFloat(float * n, int * base);

void directConvDouble(double* n, int * base);

void imprimirRaya(int largo,char carac);

void mostrarTitulo(char * titulo);

void msgConversionDirecta();

#endif // IMPRESION_H_INCLUDED
