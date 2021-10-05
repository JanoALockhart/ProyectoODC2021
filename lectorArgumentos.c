#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "almacenamientoParam.h"
#include "lectorArgumentos.h"


/**
Metodo que compia el valor del argumento pasado por parametro
en el campo correspondiente del registro.
Parametros:
    -param: es el valor del argumento ingresado a copiar
    -dirCampo: es la direccion de memoria del campo del
        registro en el que se quiere guardar el valor.
*/
void guardarValorParametro(char *param, char** dirCampo){
    *dirCampo = malloc((strlen(param)+1)*sizeof(char));
    strcpy(*dirCampo,param);
}

/**
Metodo que verifica que el parametro que esta leyendo sea el nombre de
un argumento existente. En caso de que no sea valido, el programa
termina con un error. Si el argumento es correcto, se devuelve la
direccion de memoria del campo del registro en el que haya que almacenar
el valor del argumento.
Parametros:
    -param: es un puntero al primer caracter del nombre del argumento
*/
char*** identificarParametro(char *param, tArgumentos1 *registro){

    char*** dirDevolver;

    dirDevolver = malloc(sizeof(char*));


    if(*param!='-'){
        exit(ERROR_EN_EL_INGRESO_DE_ARGUMENTO);
    }else if(*(param+1)=='\0' || (*(param+2)!='\0')){
        exit(ERROR_EN_EL_INGRESO_DE_ARGUMENTO);
    }else{
        switch(*(param+1)){
            case 'n' :{
                if((registro->argN) == NULL){
                    *dirDevolver = &(registro->argN);
                }else{
                    exit(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            case 's' :{
                if((registro->argS) == NULL){
                    *dirDevolver = &(registro->argS);
                }else{
                    exit(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            case 'd' :{
                if((registro->argD) == NULL){
                    *dirDevolver = &(registro->argD);
                }else{
                    exit(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            case 'v':{
                if((registro->argV)!=1){
                    registro->argV=1;
                    free(dirDevolver);
                    dirDevolver = NULL;
                }else{
                    exit(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            default:{
                exit(ERROR_ARGUMENTO_NO_EXISTENTE);
            }
        }
    }
    return dirDevolver;
}

/**
Metodo que verifica si la palabra pasada por par�metro
es de la forma "-h"
Parametro:
    -palabra: es el puntero a la cadena de caracteres que se quiere analizar
Return: 0 si el parametro ingresado no es "-h", cualquier otro numero en caso contrario
*/
int esElArgH(char *palabra){
   return ((*palabra=='-') && (*(palabra+1)!='\0') && (*(palabra+1)=='h') && (*(palabra+2)=='\0'));
}

/**
Este metodo verifica si en el arreglo de argumentos ingresados
se encuentra el parametro "-h".
Parametros:
    -arrParam: es el arreglo de argumentos ingresado
    -cantParam: es la cantidad de argumentos ingresados
Return: 1 si el parametro leido es -h, 0 en caso contrario.
*/
int* estaParamH(int cantParam, char* arrParam[]){
    int *estaH;
    int *numParam;

    numParam = malloc(sizeof(int));
    estaH = malloc(sizeof(int));

    *estaH = 0;
    for(*numParam=0; *numParam<cantParam && !(*estaH); (*numParam)++){
        *estaH = esElArgH(arrParam[*numParam]);
    }

    free(numParam);

    return estaH;
}

/**
Metodo que se encarga de asignar el valor por defecto
al campo del registro indicado por parametro
Parametro:
    -campoRegistro: es la direccion de memoria del campo
        al que se le quiere asignar el valor por defecto.
*/
void asignarDefault(char **campoRegistro){
    *campoRegistro = malloc((strlen(BASE_DEFAULT)+1)*sizeof(char));
    **campoRegistro = '1';
    *(*campoRegistro+1) ='0';
    *(*campoRegistro+2) ='\0';
}

/**
Este metodo se encarga de leer los parametros ingresados dentro del main
Parametros:
    -cantParam: es la cantidad de parametros que ingreso el usuario
    -arrParam: es el arreglo que contiene todos los parametros que el usuario ingreso
Return: un registro con los valores de los parametros ingresados
*/
tArgumentos1 *verificarEntrada(int cantParam, char* arrParam[]){
    //Declaraciones
    int *numParam;
    char ***argAGuardar; //Almacena la direccion de memoria de un campo del registro
    int *estaH;//booleans
    tArgumentos1 *regArgs;

    //Asignaciones de memoria
    numParam = malloc(sizeof(int));
    regArgs = malloc(sizeof(tArgumentos1));

    //Inicializar registro
    (regArgs->argN)=NULL;
    (regArgs->argD)=NULL;
    (regArgs->argS)=NULL;
    (regArgs->argV)=0;
    (regArgs->argH)=0;


    //Algoritmo
    //Buscar el parametro -h
    estaH = estaParamH(cantParam,arrParam);
    if(*estaH){
        (regArgs->argH)=1;
    }else{
        //Si no hay parametro -h leer el resto de los parametros y guardar sus valores
        argAGuardar = NULL;
        for(*numParam=0; (*numParam)<cantParam; (*numParam)++){
            if(argAGuardar==NULL){
                argAGuardar = identificarParametro(arrParam[*numParam],regArgs);
            }else{
                guardarValorParametro(arrParam[*numParam],*argAGuardar);
                free(argAGuardar); //libero memoria asignada en la funcion identificarParametro
                argAGuardar=NULL;
            }
        }

    }

    //Si no se ingresaron las bases, asignar las que est�n por default
    if((regArgs->argS)==NULL){
        asignarDefault(&(regArgs->argS));
    }

    if((regArgs->argD)==NULL){
        asignarDefault(&(regArgs->argD));
    }

    //Liberamos memoria

    free(numParam);
    free(estaH);

    return regArgs;
}
