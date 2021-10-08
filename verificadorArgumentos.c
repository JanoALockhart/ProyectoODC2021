#include <stdio.h>
#include <stdlib.h>

#include "almacenamientoParam.h"
#include "Util.h"
#include "impresion.h"

#define ERROR_BASE 200
#define VALOR_ARGN_NO_INGRESADO 202
#define ERROR_ARGN_INVALIDO 203
#define LIMITES_NUM_INCUMPLIDOS 204
#define NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN 205

#define BASE_MENOR 2
#define BASE_MAYOR 16

#define MAX_PARTE_ENTERA_INPUT 10
#define MAX_PARTE_FRACC_INPUT 5



//Esta funcion iria en util.c
/**
Esta funcion se encarga de verificar que una cadena de
caracteres este formada solo por digitos del 0 al 9.
Parametro:
    -cadena: es un puntero a la cadena de caracteres
        que se quiere verificar
Return: un puntero a int que almacena 1 si la cadena
    esta compuesta solo de numeros, 0 en caso contrario
    El espacio en memoria al que apunta el
    puntero debe liberarse con un free()
*/
int* soloNumeros(char* cadena){
    char *pCarac;
    int *numCarac;
    int *soloCar;

    pCarac = (char*) malloc(sizeof(char));
    numCarac = (int*) malloc(sizeof(int));
    soloCar = (int*) malloc(sizeof(int));

    *numCarac = 0;
    do{
        *pCarac = *(cadena+(*numCarac));
        *soloCar = ('0'<=*pCarac && *pCarac<='9')||(*pCarac=='\0');
        (*numCarac)++;
    }while(*pCarac!='\0' && *soloCar);

    free(pCarac);
    free(numCarac);

    return soloCar;
}

/**
Funcion que verifica que el numero ingresado
no sobrepase los limites para la cantidad de digitos
enteros y de digitos fraccionarios.
Parmametro:
    -strNum: es la cadena de caracteres que representa
        el numero a verificar.
Return: 1 si el numero cumple las restricciones, 0
    en caso contrario.
*/
int * limitesEnteroYFracc(char* strNum){
    int *cantInt, *cantFracc, *pos;
    int *verify;
    cantInt = (int *) malloc(sizeof(int));
    cantFracc = (int *) malloc(sizeof(int));
    pos = (int *) malloc(sizeof(int));
    verify = (int *) malloc(sizeof(int));

    *cantInt = 0;
    *cantFracc = 0;
    *pos = 0;
    //contar caracteres enteros
    while(*(strNum+(*pos))!='\0' && *(strNum+(*pos))!='.' && *(strNum+(*pos))!=','){
        (*cantInt)++;
        (*pos)++;
        printf("sigma cant int %i \n",*cantInt);
    }

    //contar caracteres fraccionarios
    while(*(strNum+(*pos))!='\0'){
        (*cantFracc)++;
        (*pos)++;
    }

    *verify=(*cantInt <= MAX_PARTE_ENTERA_INPUT) && (*cantFracc <= MAX_PARTE_FRACC_INPUT);

    free(cantFracc);
    free(cantInt);
    free(pos);

    return (verify);
}


/**
Esta funcion se encarga de verificar que el valor
del argumento -n sean correctos. Es decir, que cada
digito que lo conforma sea valido y este entre 0 y la baseOrigen,
este ultimo sin incluir. (0<=digito<baseOrigen). Si no se
cumple esto, el programa finaliza con un error.
Parametros:
    -strNumero: es la cadena ingresada que representa el
        numero y se va a verificar
    -baseOrigen: es la base en la que el numero fue ingresada
*/
void verificarArgN(char* strNumero, int baseOrigen){
    int *valido;

    char* pCarac;

    pCarac = (char*) malloc(sizeof(char));

    valido=limitesEnteroYFracc(strNumero);

    if(!(*valido)){
        mostrarError(LIMITES_NUM_INCUMPLIDOS);
    }
    printf("Yogur \n");
    printf("string %s int %i\n",strNumero,baseOrigen);

    printf("isvalid %i",!(*isValid(strNumero, &baseOrigen)));

    free(valido);
    valido=isValid(strNumero, &baseOrigen);

    if(*valido==10){
        mostrarError(ERROR_ARGN_INVALIDO);
    }

    if(!(*valido)){
        mostrarError(NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN);
    }

    printf("Yogurisimo \n");

    free(valido);
    free(pCarac);
}

/**
Funcion que se encarga de verificar que la base
sea un valor valido. En caso de que no lo sea
finaliza el programa con error.
Parametro:
    -strBase: es el valor de la base en formato
        cadena y distinto de NULL.
Return: un puntero a entero que almacena el valor
    de la base.
    El espacio en memoria al que apunta el
    puntero debe liberarse con un free()
*/
int* verificarBase(char* strBase){
    int *esNum;
    int *base;

    base = (int*) malloc(sizeof(int));

    esNum = soloNumeros(strBase);

    printf("epa %s\n", strBase);

    if(*esNum){
        *base = atoi(strBase);
        if(!(BASE_MENOR<=*base && *base<=BASE_MAYOR)){
            mostrarError(ERROR_BASE); //No esta dentro de los rangos
        }
    }else{
        mostrarError(ERROR_BASE); //El valor ingresado no es un numero valido
    }

    free(esNum);
    return base;
}

/**
Funcion que se encarga de verificar que los valores
de los campos del registro pasado por parametro
sean correctos. En caso de que alguno de los campos
sea NULL, el programa termina con un error.
Parametro:
    -regArgs: es el registro con los argumentos a verificar
*/
void verificarValores(tArgumentos1* regArgs){

    int* baseOrigen;

    if((regArgs->argS)!=NULL){
        baseOrigen = verificarBase(regArgs->argS);
        printf("Salsa\n");
    }else{
        mostrarError(ERROR_BASE); //argumento base origen es nulo (para hacer mas robusto)
    }

    if((regArgs->argN)!=NULL){
        verificarArgN(regArgs->argN,*baseOrigen);
        printf("Origen\n");
        free(baseOrigen);
    }else{
        mostrarError(VALOR_ARGN_NO_INGRESADO);
    }

    if((regArgs->argD)!=NULL){
        baseOrigen = verificarBase(regArgs->argD);//guardamos el valor, para luego liberar la memoria
        free(baseOrigen);
    }

}
