#include <stdlib.h>

#include "almacenamientoParam.h"

/**
Procedimiento que inicializa los campos del registro
indicado por par�metro con valores por defecto.
Los campos correspondientes a los argumentos n, s y
d son inicializados como NULL.
Los campos correspondientes a los argumentos v y h
son inicializados como 0.
*/
void constructor(tArgumentos1* registro){
    registro->argN = NULL;
    registro->argS = NULL;
    registro->argD = NULL;
    registro->argV = 0;
    registro->argH = 0;
}

/**
Procedimiento que libera la memoria a la que apuntan
el registro ingresado por par�mtetro y sus campos.
Par�metro:
    -registro: es el registro cuya memoria ser� liberada.
*/
void destructor(tArgumentos1* registro){
    if(registro->argN!=NULL){
        free(registro->argN);
    }
    if(registro->argS!=NULL){
        free(registro->argS);
    }
    if(registro->argD!=NULL){
        free(registro->argD);
    }
    free(registro);
}
