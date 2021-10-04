#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"
#include "lectorArgumentos.h"

/**
Metodo que verifica que el parametro que esta leyendo sea el nombre de
un argumento existente. En caso de que no sea valido, el programa
termina con un error. Si el argumento es correcto, se devuelve la
direccion de memoria del campo del registro en el que haya que almacenar
el valor del argumento.
Parametros:
    -param: es un puntero al primer caracter del nombre del argumento
*/
char** identificarParametro(char *param, tArgumentos1 *registro){

    char** dirDevolver;

    dirDevolver = malloc(sizeof(char*));

    if(*param!='-'){
        exit(ERROR_EN_EL_INGRESO_DE_PARAMETROS);
    }else if(*(param+1)=='\0' || (*(param+2)!='\0')){
        exit(ERROR_EN_EL_INGRESO_DE_PARAMETROS);
    }else{
        switch(*(param+1)){
            case 'n' :{
                if((registro->argN) == NULL){
                    *dirDevolver = &(registro->argN);
                }
            }


        }


    }
}





/**
Este metodo verifica si la cadena de caracteres indicada es "-h"
Parametros:
    -param: es un puntero al primer caracter de la cadena de caracteres
Return: 1 si el parametro leido es -h, 0 en caso contrario.
*/
int* esParamH(char *param){
    return ((*param=='-') && (*(param+1)!='\0') && (*(param+1)=='h') && (*(param+2)=='\0'));
}


/**
Este metodo se encarga de leer los parametros ingresados dentro del main
Parametros:
    -cantParam: es la cantidad de parametros que ingreso el usuario
    -arrParam: es el arreglo que contiene todos los parametros que el usuario ingreso
Return: un registro con los valores de los parametros ingresados
*/
tArgumentos1 *verificarEntrada(int cantParam, char arrParam[]){
    //Declaraciones
    int *numParam;
    char **argAIngresar; //Almacena la direccion de memoria al primer caracter del parametro
    int *estaH;//booleans
    tArgumentos1 *regArgs;

    //Asignaciones de memoria
    numParam = malloc(sizeof(int));
    estaH = malloc(sizeof(int));
    regArgs = malloc(sizeof(tArgumentos1));
    argAIngresar = malloc(sizeof(char*));

    //Inicializar registro
    regArgs->argN=NULL;
    regArgs->argD=NULL;
    regArgs->argS=NULL;
    regArgs->argV=0;
    regArgs->argH=0;


    //Algoritmo
    //Buscar el parametro -h
    for(*numParam=0; *numParam<cantParam && !(*estaH); (*numParam)++){
       *estaH = esParamH(arrParam[*numParam]);
    }

    if(*estaH){
        (regArgs->argH)=1;
    }else{
        //Si no hay parametro -h leer el resto de los parametros y guardar sus valores
        argAIngresar = NULL;
        for(*numParam=0; *numParam<cantParam; (*numParam)++){
            if(argAIngresar==NULL){
                *argAIngresar = identificarParametro(arrParam[*numParam],regArgs);
            }else{
                guardarValorParametro(arrParam[*numParam],*argAIngresar);
                argAIngresar=NULL;
            }
        }

    }

    //Liberamos memoria


    return regArgs;
}
