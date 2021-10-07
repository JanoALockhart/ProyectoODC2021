#ifndef VERIFICADORARGUMENTOS_H_INCLUDED
#define VERIFICADORARGUMENTOS_H_INCLUDED

#define ERROR_BASE 200
#define VALOR_ARGN_NO_INGRESADO 202
#define ERROR_ARGN_INVALIDO 203
#define LIMITES_NUM_INCUMPLIDOS 204
#define NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN 205

int* soloNumeros(char* cadena);

int limitesEnteroYFracc(char* strNum);

void verificarArgN(char* strNumero, int baseOrigen);

int* verificarBase(char* strBase);

void verificarValores(tArgumentos1* regArgs);

#endif // VERIFICADORARGUMENTOS_H_INCLUDED
