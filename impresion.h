#ifndef IMPRESION_H_INCLUDED
#define IMPRESION_H_INCLUDED

void papDecimalOBaseT10Base(int * total, int * n, int * OBase, int * exp);

void papDecimal10BaseTDBase(int * n, int * b, int * r);

void papFractionaryOBaseT10Base(float* total, int * n, int * OBase, int * exp);

void papFractionary10BaseTDBase(int * TBase, float * n, int * digit);

void mostrarResultadoFinal(char * resultadoEntero, char * resultadoFraccional);

void mostrarError(int nroError);

void mostrarAyuda();

void directConv(int * n, int * base);

#endif // IMPRESION_H_INCLUDED
