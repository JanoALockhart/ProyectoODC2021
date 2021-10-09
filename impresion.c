#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <String.h>

#include "verificadorArgumentos.h"
#include "lectorArgumentos.h"

/**
Procedimiento que imprime un paso de la conversión de la parte entera de una base de origen a la base 10.
Muestra el total que se va obteniendo a medida que se multiplica cada digito del numero
por la base elevada a la posicion.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo después de hacer las operaciones aritmeticas.
    -digit: Puntero a un entero que es el valor del dígito.
    -OBase: Puntero a un entero que es la base de origen.
    -exp: Puntero a un entero que es el exponente el cuál se eleva la base.
*/
void papDecimalOBaseT10Base(float * total, int * digit, int * OBase, int * exp){
    printf("total=total+%i*(%i^%i)\n",*digit,*OBase,*exp);
    printf("total=%f\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversión de la parte entera de una base 10 a una base destino.
Imprime en consola el siguiente formato:
    dividendo | baseDestino
              **************
    resto
    div(dividendo,baseDestino)=siguienteDividendo

Parametros:
    -c: Puntero a un entero que es el resultado de la division.
    -b: Puntero a un entero que es la base destino.
    -r: Puntero a un entero que es el resto.
*/
void papDecimal10BaseTDBase(float * c, int * b, int * r){
    int * i;
    int * numberLength;
    long int * d; // Puntero a un entero que es el dividendo

    numberLength=(int *) malloc(sizeof(int));
    d=(long int *) malloc(sizeof(long int));
    i=(int *) malloc(sizeof(int));

    *d=(int) (*c)* *(b);
    *i=0;

    *numberLength=floor(log10(abs( (*d) ))) + 1;
    printf("%li |%i\n", *d, *b);

    for(;(*i)<=(*numberLength);(*i)++){
        printf(" ");
    }

    *numberLength=floor(log10(abs(*b))) + 1;
    *i=0;

    for(;(*i)<(*numberLength)+2;(*i)++){
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
Procedimiento que imprime un paso de la conversión de la parte fraccional de una base de origen a la base 10.
Muestra el total que se va obteniendo a medida que se multiplica cada digito del numero
por la base elevada a la posicion.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo después de hacer las operaciones aritmeticas.
    -n: Puntero a un entero que es el valor del dígito del numero fraccionario que se esta multiplicando.
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
    -digit: Puntero a la parte entera que resulta de multiplicar la base de destino con n.
*/
void papFractionary10BaseTDBase(int * DBase, float * n, int * digit){
    printf("%i * %f = %f // %i \n",*DBase, *n, (*n)*(*DBase), *digit);
}

/**
Procedimiento que imprime el resultado final de la conversión.
Parametros:
    -numOriginal: es el número ingresado para ser transformado.
    -bOrigen: es la base en la que estaba expresado el numeroOriginal.
    -bDestino: es la base a la que se transformó el numero.
    -resultadoEntero: Puntero al primer caracter de la parte entera.
    -resultadoFraccional: Puntero al primer caracter de la parte fraccionaria.
*/
void mostrarResultadoFinal(char * numOriginal, char * bOrigen, char * bDestino, char * resultadoEntero, char * resultadoFraccional){
    printf("El numero %s en base %s es %s.%s en base %s", numOriginal, bOrigen, resultadoEntero, resultadoFraccional, bDestino);
}

/**
Procedimiento que dado un número de error, imprime el mensaje de error correspondiente.
Luego, finaliza el programa con un EXIT_FAILURE
Parámetro:
    -nroError: Puntero al entero que servira como clave del error.
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
y el significado de cada uno de los parametros que pueden ser.
Luego de esto, el programa termina con EXIT_SUCCESS.
ingresados al programa.
*/
void mostrarAyuda(){
    printf("SINTAXIS: convert -n <number> [-s <source_base>] [-d <dest_base>] [-v] [-h] \n\n");

    printf("convert es un programa que convierte el numero <number> expresado en la\n");
    printf("base de origen <source_base> a la base destino <dest_base>.\n\n");

    printf("ARGUMENTOS:\n");
    printf("-n <number>         OBLIGATORIO. Es el numero se quiere convertir. Debe ser\n");
    printf("                    coherente con la base indicada como <source_base>. Puede\n");
    printf("                    tener como maximo 10 digitos en la parte entera y 5 en\n");
    printf("                    parte fraccionaria.\n\n");
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
Procedimiento que muestra un mensaje cuando
la conversión es trivial.
    -Parámetros:
        -n: es un puntero a int que almacena el numero a transformar.
        -base: es un puntero a la base que se quiere transformar.
*/
void directConv(float* n, int * base){
    printf("Conversion directa. %li en base %i es %li\n",*n, *base, *n);
}

/**
Procedimiento que imprime una raya con el caracter
y longitud especificados.
Parámetros:
    -largo: es la longitud de la raya.
    -carac: es el caracter con el que se formará la raya.
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
Procedimiento que muestra el titulo indicado entre
dos rayas.
    -titulo: es un puntero a la cadena de caracteres
        que será mostrada.
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
