#include <stdlib.h>

#include "verificadorArgumentos.h"
#include "lectorArgumentos.h"

/**
Procedimiento que imprime un paso de la conversión de la parte entera de una base de origen a la base 10.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo después de hacer las operaciones aritmeticas.
    -digit: Puntero a un entero que es el valor del dígito.
    -OBase: Puntero a un entero que es la base de origen.
    -exp: Puntero a un entero que es el exponente el cuál se eleva la base.
*/
void papDecimalOBaseT10Base(int * total, int * digit, int * OBase, int * exp){
    printf("total=total+%i*(%i^%i)\n",*digit,*OBase,*exp);
    printf("total=%i\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversión de la parte entera de una base 10 a una base destino.
Parametros:
    -c: Puntero a un entero que es el cociente
    -b: Puntero a un entero que es la base destino
    -r: Puntero a un entero que es el resto
*/
void papDecimal10BaseTDBase(int * c, int * b, int * r){
    int * i;
    int * numberLength;
    int * d; // Puntero a un entero que es el dividendo

    numberLength=(int *) malloc(sizeof(int));
    d=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));

    *d=(*c)* *(b);
    *i=0;

    *numberLength=floor(log10(abs( (*d) ))) + 1;
    printf("%i |%i\n", *d, *b);

    for(;(*i)<=(*numberLength);(*i)++){
        printf(" ");
    }

    *numberLength=floor(log10(abs(b))) + 1;
    *i=0;

    for(;(*i)<(*numberLength);(*i)++){
        printf("*");
    }
    printf("\n %i \n", *r);
    printf("div(%i,%i)=%i\n", *d, *b, *c);
    printf("------\n");

    free(numberLength);
    free(d);
    free(i);
}

/**
Procedimiento que imprime un paso de la conversión de la parte fraccional de una base de origen a la base 10.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo después de hacer las operaciones aritmeticas.
    -n: Puntero a un entero que es el valor del dígito.
    -OBase: Puntero a un entero que es la base de origen.
    -exp: Puntero a un entero que es el exponente el cuál se eleva la base.
*/
void papFractionaryOBaseT10Base(float * total, int * n, int * OBase, int * exp){
    printf("total=total+%i*(%i^-%i)\n",*n,*OBase,*exp);
    printf("total=%f\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversión de la parte fraccional de una base 10 a una base de destino.
Parametros:
    -DBase: Puntero a un entero que es la base de destino.
    -n: Puntero al numero a multiplicarse por la base de destino.
    -digit: Puntero al dígito entero que resulta de multiplicar la base de destino con n.
*/
void papFractionary10BaseTDBase(int * DBase, float * n, int * digit){
    printf("%i * %f = %f // %i \n",*DBase, *n, (*n)*(*DBase), *digit);
}

/**
Procedimiento que imprime el resultado final de la conversión.
Parametros:
    -resultadoEntero: Puntero al primer caracter de la parte entera.
    -resultadoFraccional: Puntero al primer caracter de la parte fraccionaria.
*/
void mostrarResultadoFinal(char * resultadoEntero, char * resultadoFraccional){
    printf("El numero es %s.%s", resultadoEntero, resultadoFraccional);
}

/**
Procedimiento que dado un número de error, imprime el error correspondiente.
    nroError: Puntero al entero que servira como clave del error.
*/
void mostrarError(int * nroError){
    switch(*nroError){
        case ERROR_ARGUMENTOS_REPETIDOS: printf("ERROR %i: Se han introducido más de una vez un argumento válido",ERROR_ARGUMENTOS_REPETIDOS); break;
        case ERROR_ARGUMENTO_NO_EXISTENTE: printf("ERROR %i: Se han introducido argumento inválido",ERROR_ARGUMENTO_NO_EXISTENTE); break;
        case ERROR_EN_EL_INGRESO_DE_ARGUMENTO: printf("ERROR %i: Se han introducido erroneamente valores de argumentos.",ERROR_EN_EL_INGRESO_DE_ARGUMENTO); break;
        case ERROR_BASE: printf("ERROR %i: Se han introducido erroneamente alguna base.",ERROR_BASE);
        case VALOR_ARGN_NO_INGRESADO: printf("ERROR %i: No se ha introducido el numero.",VALOR_ARGN_NO_INGRESADO);
        case LIMITES_NUM_INCUMPLIDOS: printf("ERROR %i: El número o bien tiene más de 10 dígitos decimales o más de 5 dígitos fraccionales.",LIMITES_NUM_INCUMPLIDOS);
        case NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN: printf("ERROR %i: El número no es posible de expresar en la base.",NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN);

    }
    exit(EXIT_FAILURE);
}

void mostrarAyuda(){
    printf("Conversor de bases es un simple programa que convierte un número en base X a base Y.\n\n");
    printf("Opciones:\n");
    printf("-n <number>     OBLIGATORIO. Número se quiere convertir\n");
    printf("-s <source_base>    Base de partida que será expresado el número\n");
    printf("-d <dest_base>     Base de destino que será expresado el resultado\n");
    printf("-v      Imprime el paso a paso de cada operación\n");
    printf("-h      Imprime un texto auxiliar\n");
}


