#include <stdlib.h>
#include <string.h>

#include "almacenamientoParam.h"
#include "Util.h"
#include "impresion.h"
#include "verificadorArgumentos.h"

/**
Funcion que verifica si una cadena de caracteres es un número coherente
con la base especificada.
Parametros:
    -n(char*): es un puntero a la cadena de caracteres
        que es el numero.
    -baseInicial(int*): es la base que quiere ver si n puede ser expresada
Return(int*): un puntero a entero que almacena
        -0 si es que n no puede ser expresado en la base
        -1 si es que n puede ser expresado en la base
*/
int * isValid(char * n, int * base){
    int * validity;
    int * cantFrac;
    int * i;
    int * value;

    validity=(int *) malloc(sizeof(int));
    cantFrac=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));
    value=(int *) malloc(sizeof(int));

    *validity=1;
    *cantFrac=0;
    *i=0;
    for(;(*(n+*i)!='\0') && (*cantFrac)<2 && (*validity); (*i)++){
        if((*(n+*i))=='.' || (*(n+*i))==',') (*cantFrac)++;
        else{
            value=getValue((n+*i));
            if(value==NULL || (*value)>=(*base)) *validity=0;
            free(value);
        }
    }
    if(*(cantFrac)>=2) *validity=0;
    free(cantFrac);
    free(i);
    return validity;
}

/**
Función que verifica que el numero ingresado
no sobrepase los limites para la cantidad de digitos
enteros y de digitos fraccionarios, 10 y 5 respectivamente.
Parámetro:
    -strNum(char*): es la cadena de caracteres que representa
        el número a verificar.
Return(int*): un puntero a int que almacena
    1 si el numero cumple las restricciones, 0 en caso contrario.
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
    }

    //contar caracteres fraccionarios si encontro una coma
    if(*(strNum+(*pos))=='.' || *(strNum+(*pos))){
        (*pos)++;
        while(*(strNum+(*pos))!='\0'){
            (*cantFracc)++;
            (*pos)++;
        }
    }

    *verify=((*cantInt <= MAX_PARTE_ENTERA_INPUT) && (*cantFracc <= MAX_PARTE_FRACC_INPUT));

    free(cantFracc);
    free(cantInt);
    free(pos);

    return (verify);
}


/**
Procedimiento que se encarga de verificar que el valor
del argumento -n sean correctos. Es decir, que cada
dígito que lo conforma sea válido y esté entre 0 y la baseOrigen-1,
incluidos. (0<=digito<=baseOrigen-1). Si no se
cumple esto, el programa finaliza con un error.
Parametros:
    -strNumero(char*): es la cadena ingresada que representa el
        número que se va a verificar
    -baseOrigen(int*): es un puntero a int que almacena
        la base en la que el numero fue ingresada
*/
void verificarArgN(char* strNumero, int * baseOrigen){
    int *valido;
    char* pCarac;

    pCarac = (char*) malloc(sizeof(char));

    valido=isValid(strNumero, baseOrigen);
    if(!(*valido)){
        mostrarError(ERROR_ARGN_INVALIDO);
    }
    free(valido);
    //Verificar que tenga como maximo 10 digitos enteros y 5 fraccionarios
    valido=limitesEnteroYFracc(strNumero);
    if(!(*valido)){
        mostrarError(LIMITES_NUM_INCUMPLIDOS);
    }
    free(valido);

    //Verificar que el ultimo caracter no sea una coma
    *pCarac = *(strNumero+strlen(strNumero)-1);
    if( *pCarac == '.' || *pCarac == ','){
        mostrarError(ERROR_ARGN_INVALIDO);
    }
    //Verificar que el primer caracter no sea una coma
    *pCarac = *(strNumero);
    if( *pCarac == '.' || *pCarac == ','){
        mostrarError(ERROR_ARGN_INVALIDO);
    }
    free(pCarac);
}

/**
Función que se encarga de verificar que la base
sea un valor válido, es decir, que sea una cadena
formada sólo por números y se encuentre entre
2 y 16 incluidos. En caso de que no se verifiquen
estas condiciones, el programa finaliza con un error.
Parámetro:
    -strBase(char*): es el valor de la base en formato
        cadena. Debe ser distinto de NULL.
Return(int*): un puntero a entero que almacena el valor
    de la base.
    El espacio en memoria al que apunta el
    puntero debe liberarse con un free()
*/
int* verificarBase(char* strBase){
    int *esNum;
    int *base;

    base = (int*) malloc(sizeof(int));

    esNum = soloNumeros(strBase);
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
Procedimientos que se encarga de verificar que los valores
de los campos del registro pasado por parametro
sean correctos. En caso de que alguno de los campos
sea NULL o alguno de los valores sea inválido,
el programa termina con un error.
Parametro:
    -regArgs: es el registro con los argumentos a verificar
*/
void verificarValores(tArgumentos1* regArgs){

    int* baseOrigen;

    if((regArgs->argS)!=NULL){
        baseOrigen = verificarBase(regArgs->argS);
    }else{
        mostrarError(ERROR_BASE); //argumento base origen es nulo (para hacer mas robusto)
    }

    if((regArgs->argN)!=NULL){
        verificarArgN(regArgs->argN, baseOrigen);
        free(baseOrigen);
    }else{
        mostrarError(VALOR_ARGN_NO_INGRESADO);
    }

    if((regArgs->argD)!=NULL){
        baseOrigen = verificarBase(regArgs->argD);//guardamos el valor, para luego liberar la memoria
        free(baseOrigen);
    }

}
