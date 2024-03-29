#include <math.h>
#include <stdlib.h>
#include <float.h>

#include "../util/Util.h"
#include "../util/impresion.h"

/**
Funci�n que devuelve el resultado de transformar el numero decimal desde su base de origen a base 10.
Parametros:
    -n(char*): Puntero al primer elemento de una cadena de caracteres que representara a un n�mero en base de origen.
    -OBase(int*): Puntero a un entero que representar� la base de origen en la que fue ingresada el n�mero.
    -vervose(int*): Puntero a un entero que, si el valor que apunte es:
                0. Entonces NO se imprimir� el paso a paso.
                1. Entonces se imprimir� el paso a paso.
Return(float*): Un puntero a entero que va a contener al n�mero n en base 10.
El espacio en memoria apuntado por el puntero debe liberarse con free()
*/
double * decimalOBaseT10Base(char * n, int * Obase, int * vervose){
    double * total;
    int * count;
    int * numberLength;
    int * value;
    int * exp;

    total=(double *) malloc(sizeof(double));

    if(*vervose) mostrarTitulo("PARTE ENTERA DE BASE ORIGEN A BASE 10");
    if((*Obase)!=10){
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
            (*total) += ((((double) (*value)) * (powf((double) (*Obase) , (double) (*exp) )))) ;
            if(*vervose) papDecimalOBaseT10Base(total, value, Obase, exp);
            (*count)++;
        }
        free(count);
        free(numberLength);
        free(value);
        free(exp);
    }else{ *total=(double) atoi(n); if(*vervose) directConvDouble(total, Obase); }
    return total;
}

/**
Funci�n que devuelve el resultado de transformar el numero decimal desde base 10 a una base destino.
Parametros:
    -n: Puntero a un entero que apuntara al n�mero entero en base 10 que se quiere convertir
    -DBase: Puntero a un entero que representar� la base destino
    -vervose: Puntero a un entero que, si el valor que apunte es:
                0. Entonces NO se imprimir� el paso a paso.
                1. Entonces se imprimir� el paso a paso.
Return: Un puntero a una cadena de caracteres que va a contener al n�mero n en base destino.
El espacio en memoria apuntado por el puntero debe liberarse con free()
*/
char * decimal10BaseTDBase(double * n, int * DBase, int * vervose){
    char * output;
    int * count;
    double * number;
    int * rem;

    if(*vervose) mostrarTitulo("PARTE ENTERA DE BASE 10 A BASE DESTINO");

    if((*DBase)!=10){
        output=(char *) malloc(sizeof(char));
        number=(double *) malloc(sizeof(double));
        rem=(int *) malloc(sizeof(int));
        count=(int *) malloc(sizeof(int));

        *output='\0';
        *count=0;
        *number=*n;
        while((*number)>=(*DBase)){
            *rem=((int) fmod(*number,((double)  *DBase)));
            output=agregarCaracterFinal(output, count, rem);
            *number=floor((*number)/((int) (*DBase)));
            if(*vervose) papDecimal10BaseTDBase(number, DBase, rem);
            (*count)++;
        }
        *rem=(int) *number;
        output=agregarCaracterFinal(output, count, rem);
        reverse(output, count);
        free(count);
        free(number);
        free(rem);
    }else{ output=doubleToString(n); if(*vervose) directConvDouble( n, DBase); }
    return output;
}
