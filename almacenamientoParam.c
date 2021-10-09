#include <stdlib.h>

#include "almacenamientoParam.h"

void constructor(tArgumentos1* registro){
    registro->argN = NULL;
    registro->argS = NULL;
    registro->argD = NULL;
    registro->argV = 0;
    registro->argH = 0;
}


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
