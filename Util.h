#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

int * isValid(char * n, int * base);

int * getValue(char * value);

char * isValue(int * n);

int * stringLength(char * str);

void separateComma(char * n, char * parteEntera, char * parteFraccionaria);

char* agregarCaracterFinal(char * strNum, int * stringLength, int * n);

void revertir(char * str, int * stringLength);

char * floatToString(float * n);

int * only0Verification(char * n);

#endif // UTIL_H_INCLUDED
