#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "verificadorArgumentos.h"
#include "lectorArgumentos.h"

/**
Procedimiento que imprime un paso de la conversi�n de la parte entera de una base de origen a la base 10.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo despu�s de hacer las operaciones aritmeticas.
    -digit: Puntero a un entero que es el valor del d�gito.
    -OBase: Puntero a un entero que es la base de origen.
    -exp: Puntero a un entero que es el exponente el cu�l se eleva la base.
*/
void papDecimalOBaseT10Base(float * total, int * digit, int * OBase, int * exp){
    printf("total=total+%i*(%i^%i)\n",*digit,*OBase,*exp);
    printf("total=%f\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversi�n de la parte entera de una base 10 a una base destino.
Parametros:
    -c: Puntero a un entero que es el cociente
    -b: Puntero a un entero que es la base destino
    -r: Puntero a un entero que es el resto
*/
void papDecimal10BaseTDBase(float * c, int * b, int * r){
    int * i;
    int * numberLength;
    int * d; // Puntero a un entero que es el dividendo

    numberLength=(int *) malloc(sizeof(int));
    d=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));

    *d=(int) (*c)* *(b);
    *i=0;

    *numberLength=floor(log10(abs( (*d) ))) + 1;
    printf("%i |%i\n", *d, *b);

    for(;(*i)<=(*numberLength);(*i)++){
        printf(" ");
    }

    *numberLength=floor(log10(abs(*b))) + 1;
    *i=0;

    for(;(*i)<(*numberLength);(*i)++){
        printf("*");
    }
    printf("\n %i \n", *r);
    printf("div(%i,%i)=%f\n", *d, *b, *c);
    printf("------\n");

    free(numberLength);
    free(d);
    free(i);
}

/**
Procedimiento que imprime un paso de la conversi�n de la parte fraccional de una base de origen a la base 10.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo despu�s de hacer las operaciones aritmeticas.
    -n: Puntero a un entero que es el valor del d�gito.
    -OBase: Puntero a un entero que es la base de origen.
    -exp: Puntero a un entero que es el exponente el cu�l se eleva la base.
*/
void papFractionaryOBaseT10Base(float * total, int * n, int * OBase, int * exp){
    printf("total=total+%i*(%i^-%i)\n",*n,*OBase,*exp);
    printf("total=%f\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversi�n de la parte fraccional de una base 10 a una base de destino.
Parametros:
    -DBase: Puntero a un entero que es la base de destino.
    -n: Puntero al numero a multiplicarse por la base de destino.
    -digit: Puntero al d�gito entero que resulta de multiplicar la base de destino con n.
*/
void papFractionary10BaseTDBase(int * DBase, float * n, int * digit){
    printf("%i * %f = %f // %i \n",*DBase, *n, (*n)*(*DBase), *digit);
}

/**
Procedimiento que imprime el resultado final de la conversi�n.
Parametros:
    -resultadoEntero: Puntero al primer caracter de la parte entera.
    -resultadoFraccional: Puntero al primer caracter de la parte fraccionaria.
*/
void mostrarResultadoFinal(char * resultadoEntero, char * resultadoFraccional){
    printf("El numero es %s.%s", resultadoEntero, resultadoFraccional);
}

/**
Procedimiento que dado un n�mero de error, imprime el error correspondiente.
    nroError: Puntero al entero que servira como clave del error.
*/
void mostrarError(int nroError){
    switch(nroError){
        case ERROR_ARGUMENTOS_REPETIDOS: printf("ERROR %i: Se han introducido m�s de una vez un argumento v�lido",ERROR_ARGUMENTOS_REPETIDOS); break;
        case ERROR_ARGUMENTO_NO_EXISTENTE: printf("ERROR %i: Se han introducido argumento inv�lido",ERROR_ARGUMENTO_NO_EXISTENTE); break;
        case ERROR_EN_EL_INGRESO_DE_ARGUMENTO: printf("ERROR %i: Se han introducido erroneamente valores de argumentos.",ERROR_EN_EL_INGRESO_DE_ARGUMENTO); break;
        case ERROR_BASE: printf("ERROR %i: Se han introducido erroneamente alguna base.",ERROR_BASE);break;
        case VALOR_ARGN_NO_INGRESADO: printf("ERROR %i: No se ha introducido el numero.",VALOR_ARGN_NO_INGRESADO);break;
        case LIMITES_NUM_INCUMPLIDOS: printf("ERROR %i: El n�mero o bien tiene m�s de 10 d�gitos decimales o m�s de 5 d�gitos fraccionales.",LIMITES_NUM_INCUMPLIDOS);break;
        case ERROR_ARGN_INVALIDO: printf("ERROR %i: El n�mero no es posible de expresar en la base.",NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN);break;
    }
    exit(EXIT_FAILURE);
}

void mostrarAyuda(){
    printf("Conversor de bases es un simple programa que convierte un n�mero en base X a base Y.\n\n");
    printf("Opciones:\n");
    printf("-n <number>     OBLIGATORIO. N�mero se quiere convertir\n");
    printf("-s <source_base>    Base de partida que ser� expresado el n�mero\n");
    printf("-d <dest_base>     Base de destino que ser� expresado el resultado\n");
    printf("-v      Imprime el paso a paso de cada operaci�n\n");
    printf("-h      Imprime un texto auxiliar\n");
}

void directConv(int * n, int * base){
    printf("Conversi�n directa. %i en base %i es %i\n",*n, *base, *n);
}

