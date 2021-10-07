int ejecuccion(){
    int * decimalB10;
    float * fractionaryB10;
    decimalB10=(int *) malloc(sizeof(int));
    fractionaryB10=(float *) malloc(sizeof(float));
    if(p->argH) printf("AYUDA");
    else{
        separateComma(p->argN, decimalB10, fractionaryB10);
        *decimalB10=decimalOBaseT10Base(decimalB10, p->argS, *(p->argV));
        *fractionaryB10=transformarFraccionarioAB10(fractionaryB10, p->argS, *(p->argV));
        mostrarResultadoFinal(decimal10BaseTDBase(decimalB10, p->argD, *(p->argV)), transformarFraccionarioABaseDestino(fractionaryB10, p->argD, *(p->argV));
    }
}
