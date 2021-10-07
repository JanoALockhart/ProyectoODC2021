void papDecimalOBaseT10Base(int * total, int * n, int * OBase, int * exp){
    printf("total=total+%i*(%i^%i)\n",*n,*OBase,*exp);
    printf("total=%i\n",*total);
    printf("------\n");
}

void papDecimal10BaseTDBase(int * n, int * b, int * r){
    int * i;
    int * numberLength;
    int * c;

    numberLength=(int *) malloc(sizeof(int));
    c=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));

    *c=(*n)* *(b);
    *i=0;

    *numberLength=floor(log10(abs( (*c) ))) + 1;
    printf("%i |%i\n", *c, *b);

    for(;(*i)<=(*numberLength);(*i)++){
        printf(" ");
    }

    *numberLength=floor(log10(abs(b))) + 1;
    *i=0;

    for(;(*i)<(*numberLength);(*i)++){
        printf("*");
    }
    printf("\n %i \n", *r);
    printf("div(%i,%i)=%i\n", *c, *b, *n);
    printf("------\n");

    free(numberLength);
    free(c);
    free(i);
}

void papFractionaryOBaseT10Base(int * total, int * n, int * OBase, int * exp){
    printf("total=total+%i*(%i^-%i)\n",*n,*OBase,*exp);
    printf("total=%i\n",*total);
    printf("------\n");
}

void papFractionary10BaseTDBase(int * TBase, int * n, int * digit){
    printf("%i * %i = %i // %i",*TBase, *n, (*n)*(*TBase), *digit);
}

void mostrarResultadoFinal(char * resultadoEntero, char * resultadoFraccional){
    printf(“El numero es %s.%s”, resultadoEntero, resultadoFraccional);
}

void mostrarError(int * nroError){
    switch(*nroError){
        case 1: printf("ERROR %i: ",*nroError); break;
    }
}


