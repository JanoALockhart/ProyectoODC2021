#ifndef LECTORARGUMENTOS_H_INCLUDED
#define LECTORARGUMENTOS_H_INCLUDED
#include "almacenamientoParam.h"

#define BASE_DEFAULT "10"

#define ERROR_EN_EL_INGRESO_DE_ARGUMENTO 100
#define ERROR_ARGUMENTOS_REPETIDOS 101
#define ERROR_ARGUMENTO_NO_EXISTENTE 102



tArgumentos1 *verificarEntrada(int cantParam, char* arrParam[]);


#define TESTER
#ifdef TESTER
int esElArgH(char* palabra);
int* estaParamH(int cantParam, char *param[]);
char*** identificarParametro(char *param, tArgumentos1 *registro);
void guardarValorParametro(char *param, char** argAIngresar);
#endif // TESTER

#endif // LECTORARGUMENTOS_H_INCLUDED
