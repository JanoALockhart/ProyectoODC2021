#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

int * isValid(char * n, int * base);

int * getValue(char * value);

char * isValue(int * n);

int * stringLength(char * string);

void separateComma(char * n, char * parteEntera, char * parteFraccionaria);

char* agregarCaracterFinal(char * string, int * stringLength, int * n);

void reverse(char * string, int * stringLength);

#endif // UTIL_H_INCLUDED
