#ifndef VERIFICADORARGUMENTOS_H_INCLUDED
#define VERIFICADORARGUMENTOS_H_INCLUDED


#include "almacenamientoParam.h"
#define ERROR_BASE 200
#define VALOR_ARGN_NO_INGRESADO 202
#define ERROR_ARGN_INVALIDO 203
#define LIMITES_NUM_INCUMPLIDOS 204
#define NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN 205

#define BASE_MENOR 2
#define BASE_MAYOR 16

#define MAX_PARTE_ENTERA_INPUT 10
#define MAX_PARTE_FRACC_INPUT 5


int* soloNumeros(char* cadena);

int * limitesEnteroYFracc(char* strNum);

void verificarArgN(char* strNumero, int baseOrigen);

int* verificarBase(char* strBase);

void verificarValores(tArgumentos1* regArgs);

#endif // VERIFICADORARGUMENTOS_H_INCLUDED
