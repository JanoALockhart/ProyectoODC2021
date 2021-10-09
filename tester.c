#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "almacenamientoParam.h"
#include "lectorArgumentos.h"
#include "convertirFraccionario.h"
#include "verificadorArgumentos.h"
#include "Util.h"

//#define TEST_ESH
//#define TEST_IDENTIFPARAM
//#define TEST_ENTERO
#define TEST_FRACC
//#define TEST_FRACC_2
//#define TEST_BASE
//#define TEST_REALLOC
void ejecutarTest(){

    //printf("%d \n",sizeof(tArgumentos1));
    //printf("%d \n",sizeof(tArgumentos2));
    //printf("%d \n",sizeof(tParam));

    #ifdef TEST_REALLOC
    char *string;
    int cantDig;
    int dig = 1;

    string = (char*)malloc(sizeof(char));
    *string = '\0';
    printf("%s",string);
    cantDig=0;
    while(cantDig<5){
        string = agregarCaracterFinal(string,&cantDig,&dig);
        printf("%s\n",string);
        cantDig++;
    }
    #endif // TEST_REALLOC
    #ifdef TEST_BASE
    char *base;
    int *cumple, *solNum;

    solNum = soloNumeros(base);
    cumple = verificarBase(base);
    printf("base %s soloNum: %i \n",base,*solNum);
    printf("base %s cumple: %i\n",base,*cumple);
    #endif // TEST_BASE

    #ifdef TEST_FRACC
    float* pNum;
    char* num = "de";
    pNum = transformarFraccionarioAB10(num,16,1);
    printf("%f\n",*pNum);
    int cant=0;
    while(cant<10){
        char* strNum = transformarFraccionarioABaseDestino(0.6789, 16, 1);
        printf("%s \n",strNum);
        cant++;
    }
    #endif // TEST_FRACC

    #ifdef TEST_ESH
    char* arg[3]= {"-hh","-","-h0"};
    printf("Es H: %i\n",esElArgH(arg[0]));
    printf("Es H: %i\n",esElArgH(arg[1]));
    printf("Es H: %i\n",esElArgH(arg[2]));
    printf("Tiene H: %i \n",*(estaParamH(3,arg)));

    #endif // TEST_ESH //FUNCIONA

    #ifdef TEST_IDENTIFPARAM
    char* arg[5]= {"-n","12367","-s","hola","-ne"};

    tArgumentos1 *pruebaParam = malloc(sizeof(tArgumentos1));
    pruebaParam->argD=NULL;
    pruebaParam->argS=NULL;
    pruebaParam->argN=NULL;
    pruebaParam->argV=0;
    pruebaParam->argH=0;

    char ***dirCampo = identificarParametro(arg[0],pruebaParam);

    //printf("dirObtenida: %p \n",dirCampo);
    //printf("%i \n",strlen(""));
    /*
    **dirCampo = malloc(4*sizeof(char));
    (***dirCampo)='a';
    (*(**dirCampo+1))='b';
    (*(**dirCampo+2))='c';
    (*(**dirCampo+3))='\0';

    /*/
    guardarValorParametro(arg[1],*dirCampo);
    dirCampo = identificarParametro(arg[2],pruebaParam);
    guardarValorParametro(arg[3],*dirCampo);

    printf("primCaract %c: \n",***dirCampo);
    printf("stringAlmacenado: %s \n",**dirCampo);
    printf("stringAlmacenado: %s \n",pruebaParam->argD);
    printf("stringAlmacenado: %s \n",pruebaParam->argS);
    printf("stringAlmacenado: %s \n",pruebaParam->argN);
    #endif // TEST_IDENTIFPARAM

    #ifdef TEST_ALMACENAR


    tArgumentos1 *registroParam = malloc(sizeof(tArgumentos1));

    char* argv[7]={"-s","123546","-d","4","-n","6","-v"};
    registroParam = almacenarValores(7, argv);
    //char *argv[2]={"-n","12354"};
    //registroParam = verificarEntrada(2, argv);



    printf("Registro: \n");
    printf("argN: %s \n", registroParam->argN);
    printf("argS: %s \n", registroParam->argS);
    printf("argD: %s \n", registroParam->argD);
    printf("argV: %i \n", registroParam->argV);
    printf("argH: %i \n", registroParam->argH);


    #endif // TEST_GUARDAR

}

