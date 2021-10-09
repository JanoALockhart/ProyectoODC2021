#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "Util.h"
#include "impresion.h"

/**
Funcion devuelve el resultado de transformar el numero decimal desde su base de origen a base 10.
Parametros:
    -n: Puntero al primer elemento de una cadena de caracteres que representara a un n�mero en base de origen
    -OBase: Puntero a un entero que representar� la base de origen
    -vervose: Puntero a un entero que, si el valor que apunte es:
                0. Entonces NO se imprimir� el paso a paso.
                1. Entonces se imprimir� el paso a paso.
Return: Un puntero a entero que va a contener al n�mero n en base 10.
*/
int * decimalOBaseT10Base(char * n, int * Obase, int * vervose){
    int * total;
    int * count;
    int * numberLength;
    int * value;
    int * exp;

    total=(int *) malloc(sizeof(int));

    if(*vervose) mostrarTitulo("PARTE ENTERA DE BASE ORIGEN A BASE 10");
    if((*Obase)!=10){
       // if((*n!='0' || *n!='1') && *(n+1)){ //REVISAR ESTE IF
            count=(int *) malloc(sizeof(int));
            numberLength=(int *) malloc(sizeof(int));
            value=(int *) malloc(sizeof(int));
            exp=(int *) malloc(sizeof(int));
            *total=0;
            *count=1;
            numberLength=stringLength(n);

            while((*count)<=(*numberLength)){
                value=(getValue((n+(*count)-1)));
                *exp=((*numberLength)-(*count));
                (*total) += (*value) * (int) pow( (double)(*Obase) , (double) (*exp) );
                if(*vervose) papDecimalOBaseT10Base(total, value, Obase, exp);
                (*count)++;
            }
            free(count);
            free(numberLength);
            free(value);
            free(exp);
        //} else *total=(*n=='0')?0:1;
    }else{ *total=atoi(n); if(*vervose) directConv(total, Obase); }
    return total;
}

/**
Funcion devuelve el resultado de transformar el numero decimal desde base 10 a una base destino.
Parametros:
    -n: Puntero a un entero que apuntara al n�mero entero en base 10 que se quiere convertir
    -DBase: Puntero a un entero que representar� la base destino
    -vervose: Puntero a un entero que, si el valor que apunte es:
                0. Entonces NO se imprimir� el paso a paso.
                1. Entonces se imprimir� el paso a paso.
Return: Un puntero a una cadena de caracteres que va a contener al n�mero n en base destino.
*/
char * decimal10BaseTDBase(int * n, int * DBase, int * vervose){
    char * output;
    int * count;
    int * number;
    int * rem;

    if(*vervose) mostrarTitulo("PARTE ENTERA DE BASE 10 A BASE DESTINO");
    if((*DBase)!=10){
        output=(char *) malloc(sizeof(char));
        //if((*n!='0' || *n!='1') && *(n+1)){ //REVISAR IF
            number=(int *) malloc(sizeof(int));
            rem=(int *) malloc(sizeof(int));
            count=(int *) malloc(sizeof(int));
            *count=0;
            *number=*n;

            while((*number)>=(*DBase)){
                *rem=(*number)%(*DBase);
                output=agregarCaracterFinal(output, count, rem);
                *number=(*number)/(*DBase);
                if(*vervose) papDecimal10BaseTDBase(number, DBase, rem);
                (*count)++;
            }
            output=agregarCaracterFinal(output, count, number);
            reverse(output, count);
            free(count);
            free(number);
            free(rem);
        //}else *output=(*n=='0')?0:1;
    }else{ output=integerToString(n); if(*vervose) directConv(n, DBase); }
    return output;
}
