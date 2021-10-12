#include <stdlib.h>
#include <string.h>

#include "../almacenamientoDatos/almacenamientoParam.h"
#include "../util/impresion.h"
#include "lectorArgumentos.h"

/**
Procedimiento que copia el valor del argumento pasado por parametro,
como una cadena de caracteres, en la dirección  de memoria,
también pasada por parámetro, del campo correspondiente del registro.
Parámetros:
    -param(char*): es el valor del argumento ingresado a copiar
    -dirCampo(char**): es un puntero que almacena la direccion de memoria del campo del
        registro en el que se quiere guardar el valor.
*/
void guardarValorParametro(char *param, char** dirCampo){
    *dirCampo = malloc((strlen(param)+1)*sizeof(char));
    strcpy(*dirCampo,param);
}

/**
Función que verifica que el parámetro que esta leyendo sea el nombre de
un argumento existente. En caso de que no sea válido, el programa
termina con un error. Si el nombre del argumento es correcto, se devuelve la
dirección de memoria del campo del registro en el que haya que almacenar
el valor inmediatamente después.
Parametros:
    -param(char*): es un puntero al primer caracter del nombre del argumento.
    -registro(tArgumentos1*): es un puntero al registro que almacenará el valor del parámetro.
Return(char***): es el puntero que almacena la dirección de memoria del
    campo en el que se deberá almacenar un valor.
*/
char*** identificarParametro(char *param, tArgumentos1 *registro){
    char*** dirDevolver;

    dirDevolver = malloc(sizeof(char*));

    if((*param)!='-'){
        mostrarError(ERROR_EN_EL_INGRESO_DE_ARGUMENTO);

    }else if(*(param+1)=='\0' || (*(param+2)!='\0')){
        mostrarError(ERROR_EN_EL_INGRESO_DE_ARGUMENTO);
    }else{
        switch(*(param+1)){
            case 'n' :{
                if((registro->argN) == NULL){
                    *dirDevolver = &(registro->argN);
                }else{
                    mostrarError(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            case 's' :{
                if((registro->argS) == NULL){
                    *dirDevolver = &(registro->argS);
                }else{
                    mostrarError(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            case 'd' :{
                if((registro->argD) == NULL){
                    *dirDevolver = &(registro->argD);
                }else{
                    mostrarError(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            case 'v':{
                if((registro->argV)!=1){
                    registro->argV=1;
                    free(dirDevolver);
                    dirDevolver = NULL;
                }else{
                    mostrarError(ERROR_ARGUMENTOS_REPETIDOS);
                }
                break;
            }
            default:{
                mostrarError(ERROR_ARGUMENTO_NO_EXISTENTE);
            }
        }
    }
    return dirDevolver;
}

/**
Función que verifica si la palabra pasada por parámetro
es de la forma "-h"
Parametro:
    -palabra(char*): es el puntero a la cadena de caracteres que se quiere analizar.
Return(int): 0 si el parametro ingresado no es "-h", 1 en caso contrario.
*/
int esElArgH(char *palabra){
   return ((*palabra=='-') && (*(palabra+1)!='\0') && (*(palabra+1)=='h') && (*(palabra+2)=='\0'));
}

/**
Función que verifica si en el arreglo de argumentos ingresados
se encuentra el parametro "-h".
Parametros:
    -arrParam(char**): es el arreglo de argumentos ingresado.
    -cantParam(int): es la cantidad de argumentos ingresados.
Return(int*): puntero a entero que almacena 1 si el parametro "-h" se encuentra entre los argumentos
    ingresados, 0 en caso contrario.
*/
int* estaParamH(int cantParam, char** arrParam){
    int *estaH;
    int *numParam;

    numParam = malloc(sizeof(int));
    estaH = malloc(sizeof(int));

    *estaH = 0;
    for(*numParam=0; *numParam<cantParam && !(*estaH); (*numParam)++){
        *estaH = esElArgH(*(arrParam+(*numParam)));
    }

    free(numParam);

    return estaH;
}

/**
Procedimiento que se encarga de asignar el valor por defecto,
en este caso "10", al campo del registro indicado por parámetro
Parámetro:
    -campoRegistro(char**): es un puntero a la dirección de memoria del campo
        al que se le quiere asignar el valor por defecto.
*/
void asignarDefault(char **campoRegistro){
    *campoRegistro = malloc((strlen(BASE_DEFAULT)+1)*sizeof(char));
    **campoRegistro = '1';
    *(*campoRegistro+1) ='0';
    *(*campoRegistro+2) ='\0';
}

/**
Función que se encarga de recorrer los parámetros ingresados dentro del main
y, si no se ingresó el argumento de ayuda, guardar los valores en los campos
correspondientes en un registro de tipo argmentos tArgumentos1. Observación:
estos valores no necesariamente serán válidos ya que la verificación no es
responsabilidad de este módulo.
En caso de que el parámetro -h sea encontrado, se muestra un mensaje de ayuda por consola.
Si alguna de las bases no fue ingresada, se asigna la base 10 por defecto.
Parámetros:
    -cantParam(int): es la cantidad de parametros que ingresó el usuario.
    -arrParam(char**): es el arreglo que contiene todos los parámetros que el usuario ingresó
Return(tArgumentos*): un puntero a un registro de tipo tArgumentos1
    con los valores de los parámetros ingresados.
*/
tArgumentos1 *almacenarValores(int cantParam, char** arrParam){

    //Declaraciones
    int *numParam;
    char ***argAGuardar;    //Almacena la direccion de memoria de un campo del registro
    char **pPalabra;        //puntero que apunta a una palabra
    int *estaH;             //booleans
    tArgumentos1 *regArgs;

    //Asignaciones de memoria
    numParam = (int*) malloc(sizeof(int));
    regArgs = (tArgumentos1 *) malloc(sizeof(tArgumentos1));

    //Inicializar registro
    constructor(regArgs);

    //Buscar el parametro -h
    estaH = estaParamH(cantParam,arrParam);

    if(*estaH){
        mostrarAyuda();
    }else{
        pPalabra=NULL;

        //Si hay mas parametros de los posibles, algo se ingresó mal
        if(cantParam>9){
            mostrarError(ERROR_EN_EL_INGRESO_DE_ARGUMENTO);
        }
        //Si no hay parametro -h leer el resto de los parametros y guardar sus valores
        argAGuardar = NULL;
        for(*numParam=1; (*numParam)<cantParam; (*numParam)++){

            pPalabra = (arrParam+(*numParam));
            if(argAGuardar==NULL){
                argAGuardar = identificarParametro(*pPalabra,regArgs);
            }else{
                guardarValorParametro(*pPalabra,*argAGuardar);
                free(argAGuardar); //libero memoria asignada en la funcion identificarParametro
                argAGuardar=NULL;
            }
        }

        //Si no se ingresaron las bases, asignar las que están por default
        if((regArgs->argS)==NULL){
            asignarDefault(&(regArgs->argS));
        }

        if((regArgs->argD)==NULL){
            asignarDefault(&(regArgs->argD));
        }
    }
    //Liberamos memoria

    free(numParam);
    free(estaH);

    return regArgs;
}
