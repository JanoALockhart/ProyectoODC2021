/**
Procedimiento que imprime un paso de la conversi�n de la parte entera de una base de origen a la base 10.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo despu�s de hacer las operaciones aritmeticas.
    -digit: Puntero a un entero que es el valor del d�gito.
    -OBase: Puntero a un entero que es la base de origen.
    -exp: Puntero a un entero que es el exponente el cu�l se eleva la base.
*/
void papDecimalOBaseT10Base(int * total, int * digit, int * OBase, int * exp){
    printf("total=total+%i*(%i^%i)\n",*digit,*OBase,*exp);
    printf("total=%i\n",*total);
    printf("------\n");
}

/**
Procedimiento que imprime un paso de la conversi�n de la parte entera de una base 10 a una base destino.
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
Procedimiento que imprime un paso de la conversi�n de la parte fraccional de una base de origen a la base 10.
Parametros:
    -total: Puntero a un entero que es el resultado que quedo despu�s de hacer las operaciones aritmeticas.
    -n: Puntero a un entero que es el valor del d�gito.
    -OBase: Puntero a un entero que es la base de origen.
    -exp: Puntero a un entero que es el exponente el cu�l se eleva la base.
*/
void papFractionaryOBaseT10Base(int * total, int * n, int * OBase, int * exp){
    printf("total=total+%i*(%i^-%i)\n",*n,*OBase,*exp);
    printf("total=%i\n",*total);
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
void mostrarError(int * nroError){
    switch(*nroError){
        case 1: printf("ERROR %i: ",*nroError); break;
    }
}


