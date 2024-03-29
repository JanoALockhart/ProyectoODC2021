#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <String.h>

#include "../input/verificadorArgumentos.h"
#include "../input/lectorArgumentos.h"

/**
Procedimiento que imprime un paso de la conversi�n de la parte entera de una base de origen a la base 10.
Muestra el total que se va obteniendo a medida que se multiplica cada digito del numero
por la base elevada a la posicion.
Par�metros:
    -total(double*): Puntero a double que es el resultado que quedo despu�s de hacer las operaciones aritmeticas.
    -digit(int*): Puntero a un entero que es el valor del d�gito.
    -OBase(int*): Puntero a un entero que es la base de origen.
    -exp(int*): Puntero a un entero que es el exponente el cu�l se eleva la base.
*/
void papDecimalOBaseT10Base(double * total, int * digit, int * OBase, int * exp){
    printf("total=total+%i*(%i^%i)\n",*digit,*OBase,*exp);
    printf("total=%f\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversi�n de la parte entera de una base 10 a una base destino.
Imprime en consola el siguiente formato:
    dividendo | baseDestino
              **************
    resto
    div(dividendo,baseDestino)=siguienteDividendo

Parametros:
    -c(double*): Puntero a double que es el resultado de la division.
    -b(int*): Puntero a un entero que es la base destino.
    -r(int*): Puntero a un entero que es el resto.
*/
void papDecimal10BaseTDBase(double * c, int * b, int * r){
    int * i;
    int * numberLength;
    double * d; // Puntero a un entero que es el dividendo

    numberLength=(int *) malloc(sizeof(int));
    d=(double *) malloc(sizeof(double));
    i=(int *) malloc(sizeof(int));

    *d=(*c)*(*b)+(*r);
    *i=0;

    *numberLength= (int) floor(log10(*d)) + 1;
    printf("%.0f |%i\n", *d, *b);

    for(;(*i)<=(*numberLength);(*i)++){
        printf(" ");
    }

    *numberLength=floor(log10(*b)) + 1;
    *i=0;

    for(;(*i)<(*numberLength)+2;(*i)++){
        printf("*");
    }
    printf("\n %i \n", *r);
    printf("div(%.0f,%i)=%.0f\n", *d, *b, *c);
    printf("------\n");

    free(numberLength);
    free(d);
    free(i);
}

/**
Procedimiento que imprime un paso de la conversi�n de la parte fraccional de una base de origen a la base 10.
Muestra el total que se va obteniendo a medida que se multiplica cada digito del numero
por la base elevada a la posicion.
Parametros:
    -total(float*): Puntero a float que es el resultado que quedo despu�s de hacer las operaciones aritmeticas.
    -n(int*): Puntero a un entero que es el valor del d�gito del numero fraccionario que se esta multiplicando.
    -OBase(int*): Puntero a un entero que es la base de origen.
    -exp(int*): Puntero a un entero que es el exponente el cu�l se eleva la base.
*/
void papFractionaryOBaseT10Base(float * total, int * n, int * OBase, int * exp){
    printf("total=total+%i*(%i^-%i)\n",*n,*OBase,*exp);
    printf("total=%f\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversi�n de la parte fraccional de una base 10 a una base de destino.
Parametros:
    -DBase(int*): Puntero a un entero que es la base de destino.
    -n(float*): Puntero al numero a multiplicarse por la base de destino.
    -digit(int*): Puntero a la parte entera que resulta de multiplicar la base de destino con n.
*/
void papFractionary10BaseTDBase(int * DBase, float * n, int * digit){
    printf("%i * %f = %f // %i \n",*DBase, *n, (*n)*(*DBase), *digit);
}

/**
Procedimiento que imprime el resultado final de la conversi�n.
Parametros:
    -numOriginal(char*): es el n�mero ingresado para ser transformado.
    -bOrigen(char*): es la base en la que estaba expresado el numeroOriginal.
    -bDestino(char*): es la base a la que se transform� el numero.
    -resultadoEntero(char*): Puntero al primer caracter de la parte entera.
    -resultadoFraccional(char*): Puntero al primer caracter de la parte fraccionaria.
*/
void mostrarResultadoFinal(char * numOriginal, char * bOrigen, char * bDestino, char * resultadoEntero, char * resultadoFraccional, int sign){
    char * minus;
    minus=(char *) malloc(sizeof(char));
    *minus=sign?'-':' ';
    printf("El numero %c%s en base %s es %c%s.%s en base %s", *minus, numOriginal, bOrigen, *minus, resultadoEntero, resultadoFraccional, bDestino);
    free(minus);
}

/**
Procedimiento que dado un n�mero de error, imprime el mensaje de error correspondiente.
Luego, finaliza el programa con un EXIT_FAILURE
Par�metro:
    -nroError(int): Puntero al entero que servira como clave del error.
*/
void mostrarError(int nroError){
    switch(nroError){
        case ERROR_ARGUMENTOS_REPETIDOS: printf("ERROR %i: Se han introducido mas de una vez un argumento valido",ERROR_ARGUMENTOS_REPETIDOS); break;
        case ERROR_ARGUMENTO_NO_EXISTENTE:  printf("ERROR %i: Se han introducido argumento invalido. Utilize el\n",ERROR_ARGUMENTO_NO_EXISTENTE);
                                            printf("argumento -h para ver los argumentos disponibles.\n");
                                            break;
        case ERROR_EN_EL_INGRESO_DE_ARGUMENTO: printf("ERROR %i: No se encontro un argumento de la forma '-x'. Verifique que el numero de argumentos y el orden en el que los ha ingresado es correcto.",ERROR_EN_EL_INGRESO_DE_ARGUMENTO); break;
        case ERROR_BASE: printf("ERROR %i: Se han introducido erroneamente alguna base.",ERROR_BASE);break;
        case VALOR_ARGN_NO_INGRESADO: printf("ERROR %i: No se ha introducido el argumento -n <numero>.",VALOR_ARGN_NO_INGRESADO);break;
        case LIMITES_NUM_INCUMPLIDOS: printf("ERROR %i: El numero tiene mas de 10 digitos decimales o mas de 5 digitos fraccionales.",LIMITES_NUM_INCUMPLIDOS);break;
        case NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN: printf("ERROR %i: El numero no es posible de expresar en la base. \n Verifique que los digitos sean menores o iguales a la base de origen.",NUM_Y_BASE_ORIGEN_NO_CORRESPONDEN);break;
        case ERROR_ARGN_INVALIDO:   printf("ERROR %i: el valor ingresado en el argumento -n no cumple las restricciones. Recuerde \n",ERROR_ARGN_INVALIDO);
                                    printf("que el numero puede tener como maximo %i digitos en la parte entera y %i en la parte \n",MAX_PARTE_ENTERA_INPUT,MAX_PARTE_FRACC_INPUT);
                                    printf("fraccionaria. El numero no debe tener mas de un punto (.) o coma (,) y esta no puede \n");
                                    printf("estar al final ni al inicio del mismo. Los digitos que los componen deben ser menores \n");
                                    printf("o iguales a la base de origen.");
                                    break;
    }
    exit(EXIT_FAILURE);
}

/**
Procedimiento que muestra el mensaje de ayuda mostrando la sintaxis
y el significado de cada uno de los parametros que pueden ser ingresados al programa.
Luego de esto, el programa termina con EXIT_SUCCESS.
*/
void mostrarAyuda(){
    printf("SINTAXIS: convert -n <number> [-s <source_base>] [-d <dest_base>] [-v] [-h] \n\n");

    printf("convert es un programa que convierte el numero <number> expresado en la\n");
    printf("base de origen <source_base> a la base destino <dest_base>.\n\n");

    printf("ARGUMENTOS:\n");
    printf("-n <number>         OBLIGATORIO. Es el numero se quiere convertir. Debe ser\n");
    printf("                    coherente con la base indicada como <source_base>. Puede\n");
    printf("                    tener como maximo 10 digitos en la parte entera y 5 en\n");
    printf("                    parte fraccionaria. Puede ser tanto positivo como negativo.\n");
    printf("                    La coma no debe estar adelante ni al final del numero.\n\n");
    printf("-s <source_base>    Base de origen en la que esta expresado el numero \n");
    printf("                    ingresado en <number>. Debe estar entre 2 y 16 en base\n");
    printf("                    decimal. Si el argumento no es ingresado, se asume base 10\n\n");
    printf("-d <dest_base>      Base de destino en la que sera expresado el resultado de\n");
    printf("                    la conversion. Debe estar entre 2 y 16 en base decimal \n");
    printf("                    Si el argumento no es ingresado se asume base 10.\n\n");
    printf("-v                  Imprime el paso a paso de cada computacion de la conversion.\n\n");
    printf("-h                  Imprime este texto de ayuda.\n\n");
    exit(EXIT_SUCCESS);
}

/**
Procedimiento que muestra un mensaje cuando la conversi�n es trivial.
    -Par�metros:
        -n(double*): es un puntero a int que almacena el numero a transformar.
        -base(int*): es un puntero a la base que se quiere transformar.
*/
void directConvDouble(double* n, int * base){
    printf("Conversion directa. %f en base %i es %f\n",*n, *base, *n);
}

/**
Procedimiento que imprime una raya con el caracter y longitud especificados.
Par�metros:
    -largo: es la longitud de la raya.
    -carac: es el caracter con el que se formar� la raya.
*/
void imprimirRaya(int largo, char carac){
    int *contador;
    contador = (int *) malloc(sizeof(int));

    for(*contador=0;*contador<largo;(*contador)++){
        printf("%c",carac);
    }
    printf("\n");
}

/**
Procedimiento que muestra el titulo como par�metro indicado entre
dos rayas.
    -titulo: es un puntero a la cadena de caracteres
        que ser� mostrada.
*/
void mostrarTitulo(char* titulo){
    imprimirRaya(strlen(titulo),'-');
    printf("%s\n",titulo);
    imprimirRaya(strlen(titulo),'-');
}

/**
Procedimiento que muestra un mensaje cuando
la transformacion de la parte fraccionaria es trivial.
*/
void msgConversionDirecta(){
    printf("Conversion directa. No hay parte fraccional que convertir.\n");
}
