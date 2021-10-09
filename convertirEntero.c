#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Util.h"
#include "impresion.h"

/**
Funcion que devuelve el resultado de transformar el numero decimal desde su base de origen a base 10.
Parametros:
    -n: Puntero al primer elemento de una cadena de caracteres que representara a un número en base de origen.
    -OBase: Puntero a un entero que representará la base de origen en la que fue ingresada el número.
    -vervose: Puntero a un entero que, si el valor que apunte es:
                0. Entonces NO se imprimirá el paso a paso.
                1. Entonces se imprimirá el paso a paso.
Return: Un puntero a entero que va a contener al número n en base 10.
El espacio en memoria apuntado por el puntero debe liberarse con free()
*/
float * decimalOBaseT10Base(char * n, int * Obase, int * vervose){
    float * total;
    int * count;
    int * numberLength;
    int * value;
    int * exp;
    total=(float *) malloc(sizeof(float));

    if(*vervose) mostrarTitulo("PARTE ENTERA DE BASE ORIGEN A BASE 10");
    if((*Obase)!=10){
       // if((*n!='0' || *n!='1') && *(n+1)){ //REVISAR ESTE IF
            count=(int *) malloc(sizeof(int));
            numberLength=(int *) malloc(sizeof(int));
            value=(int *) malloc(sizeof(int));
            exp=(int *) malloc(sizeof(int));
            *total=0.0;
            *count=1;
            numberLength=stringLength(n);

            while((*count)<=(*numberLength)){
                value=(getValue((n+(*count)-1)));
                *exp=((*numberLength)-(*count));
                (*total) += ((float) *value) * (powf((float) (*Obase) , (float) (*exp) ));
                if(*vervose) papDecimalOBaseT10Base(total, value, Obase, exp);
                (*count)++;
            }
            free(count);
            free(numberLength);
            free(value);
            free(exp);
        //} else *total=(*n=='0')?0:1;
    }else{ *total=(float) atoi(n); if(*vervose) directConv(total, Obase); }
    return total;
}

/**
Funcion que devuelve el resultado de transformar el numero decimal desde base 10 a una base destino.
Parametros:
    -n: Puntero a un entero que apuntara al número entero en base 10 que se quiere convertir
    -DBase: Puntero a un entero que representará la base destino
    -vervose: Puntero a un entero que, si el valor que apunte es:
                0. Entonces NO se imprimirá el paso a paso.
                1. Entonces se imprimirá el paso a paso.
Return: Un puntero a una cadena de caracteres que va a contener al número n en base destino.
El espacio en memoria apuntado por el puntero debe liberarse con free()
*/
char * decimal10BaseTDBase(float * n, int * DBase, int * vervose){
    char * output;
    int * count;
    float * number;
    int * rem;

    if(*vervose) mostrarTitulo("PARTE ENTERA DE BASE 10 A BASE DESTINO");
    if((*DBase)!=10){
        output=(char *) malloc(sizeof(char)*43);
        if((*n!='0' || *n!='1') && *(n+1)){
            number=(float *) malloc(sizeof(float));
            rem=(int *) malloc(sizeof(int));
            count=(int *) malloc(sizeof(int));

            *output='\0';
            *count=0;
            *number=*n;
            while((*number)>=(*DBase)){
                *rem=(int) (*number)%(*DBase);
                output=agregarCaracterFinal(output, count, rem);
                *number=floorf((*number)/(*DBase));
                if(*vervose) papDecimal10BaseTDBase(number, DBase, rem);
                (*count)++;
            }
            *rem=(float) *number;
            output=agregarCaracterFinal(output, count, rem);
            reverse(output, count);
            free(count);
            free(number);
            free(rem);
        }else *output=(*n=='0')?0:1;
    }else{ output=floatToString(n); if(*vervose) directConv( n, DBase); }
    return output;
}
