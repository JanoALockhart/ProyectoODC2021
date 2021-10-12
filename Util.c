#include <stdlib.h>
#include <String.h>
#include <ctype.h>
#include <math.h>


/**
Esta funcion se encarga de verificar que una cadena de
caracteres este formada solo por digitos del 0 al 9.
Parametro:
    -cadena(char*): es un puntero a la cadena de caracteres
        que se quiere verificar
Return(int*): un puntero a int que almacena 1 si la cadena
    esta compuesta solo de numeros, 0 en caso contrario
    El espacio en memoria al que apunta el
    puntero debe liberarse con un free()
*/
int* soloNumeros(char* cadena){
    char *pCarac;
    int *numCarac;
    int *soloCar;

    pCarac = (char*) malloc(sizeof(char));
    numCarac = (int*) malloc(sizeof(int));
    soloCar = (int*) malloc(sizeof(int));

    *numCarac = 0;
    do{
        *pCarac = *(cadena+(*numCarac));
        *soloCar = ('0'<=*pCarac && *pCarac<='9')||(*pCarac=='\0');
        (*numCarac)++;
    }while(*pCarac!='\0' && *soloCar);

    free(pCarac);
    free(numCarac);

    return soloCar;
}

/**
Funcion que simula un mapeo de claves caracteres y valores enteros.
Parametros:
    -n(char*): caracter que es ingresado como clave
Return(int*): Puntero a un valor entero que esta relacionado con n
*/
int * getValue(char * value){
    int * output;
    output=(int *) malloc(sizeof(int));
    switch(tolower(*value)){
        case 'a':{ *output=10; break; }
        case 'b':{ *output=11; break; }
        case 'c':{ *output=12; break; }
        case 'd':{ *output=13; break; }
        case 'e':{ *output=14; break; }
        case 'f':{ *output=15; break; }
        case '0':{ *output=0; break; }
        case '1':{ *output=1; break; }
        case '2':{ *output=2; break; }
        case '3':{ *output=3; break; }
        case '4':{ *output=4; break; }
        case '5':{ *output=5; break; }
        case '6':{ *output=6; break; }
        case '7':{ *output=7; break; }
        case '8':{ *output=8; break; }
        case '9':{ *output=9; break; }
        default:{ output=NULL; break; }
    }
    return output;
}



/**
Funcion que simula un mapeo de claves enteras y valores en caracteres.
Parametros:
    -n(int*): entero que es ingresado como clave
Return(char*): Puntero a un caracter que es el valor relacionado con n
*/
char * isValue(int * n){
    char * output;
    output=(char *) malloc(sizeof(char));
    switch(*n){
        case 10:{ *output='a'; break; }
        case 11:{ *output='b'; break; }
        case 12:{ *output='c'; break; }
        case 13:{ *output='d'; break; }
        case 14:{ *output='e'; break; }
        case 15:{ *output='f'; break; }
        case 0:{ *output='0'; break; }
        case 1:{ *output='1'; break; }
        case 2:{ *output='2'; break; }
        case 3:{ *output='3'; break; }
        case 4:{ *output='4'; break; }
        case 5:{ *output='5'; break; }
        case 6:{ *output='6'; break; }
        case 7:{ *output='7'; break; }
        case 8:{ *output='8'; break; }
        case 9:{ *output='9'; break; }
        default: output=NULL; break;
    }
    return (output);
}

/**
Funcion que calcula la cantidad de caracteres de una cadena.
Parametros:
    -n(char*): Puntero al primer elemento de una cadena de caracteres
Return(int*): Puntero al entero que dice la cantidad de caracteres.
*/
int * stringLength(char * string){
    int * length;
    length=(int *) malloc(sizeof(int));
    *length=0;
    while(*(string+*length)) (*length)++;
    return (length);
}

/**
Procedimiento que, dado un número expresado en una cadena de caracteres, separa su parte entera de la parte fraccional.
Luego, referenciara a las partes entera y fraccional a dos parametros de entrada.
Parametros:
    -n(char*): Puntero al primer elemento de la cadena de caracteres.
    -parteEntera(char*): Puntero a un caracter que servirá para devolver la parte entera.
    -parteFraccionaria(char*): Puntero a un caracter que servirá para devolver la parte fraccional.
*/
void separateComma(char * n, char * parteEntera, char * parteFraccionaria){
    int * pos;
    int * i;
    pos=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));
    *pos=0;
    *i=0;
    *parteFraccionaria='\0';
    while(*(n+*i) && *(n+*i)!='.' && *(n+*i)!=','){
        *(parteEntera+*pos)=*(n+*i);
        (*pos)++;
        (*i)++;
    }
    *(parteEntera+*pos)='\0';
    *pos=0;
    if(*(n+*i)=='.' || *(n+*i)==','){
        (*i)++;
        while(*(n+*i)){
            *(parteFraccionaria+*pos)=*(n+*i);
            (*pos)++;
            (*i)++;
        }
        *(parteFraccionaria+*pos)='\0';
    }
    free(pos);
    free(i);
}

/**
Funcion que agrega el ultimo digito a la cadena de caracteres.
Para esto, relocaliza la memoria reservada para la cadena y
devuelve el puntero que apunta a la nueva direccion de memoria
Parametros:
    -strNum(char*): es un puntero a memoria dinamica que contiene
        la cadena de caracteres que representa el numero
    -cantDig(int*): es la cantidad de digitos que tiene el numero,
        sin contar el caracter nulo ('\0').
    -digito(int*): es el nuevo digito que quiere agregarse al
        final de la cadena de caracteres.
Return(char*): un nuevo puntero que indica la nueva ubicacion en
    memoria de la cadena de caracteres.
*/
char* agregarCaracterFinal(char* strNum, int * cantDig, int * digito){
    char *nuevoPunt;
    char *carac;

    nuevoPunt = (char *) malloc(((*cantDig)+2)*sizeof(char));
    strcpy(nuevoPunt,strNum);
    //nuevoPunt = (char *) realloc(strNum,((*cantDig)+2)*sizeof(char));

    carac = isValue(digito);

    *(nuevoPunt+(*cantDig))=*carac;
    *(nuevoPunt+(*cantDig)+1)='\0';

    free(carac);
    free(strNum);

    return nuevoPunt;
}

/**
Procedimiento que transforma a una cadena de caracteres en su reverso.
Parametros:
    -string(char*): Puntero al primer elemento de la cadena de caracteres.
    -stringLength(int*): Puntero a un entero que dirá la longitud de string.
*/
void reverse(char * string, int * stringLength){
    int * count;
    char * aux;
    count=(int *) malloc(sizeof(int));
    aux=(char *) malloc(sizeof(char));
    *count=0;
    while((*count)<=((*stringLength)/2)){
        *(aux)=*(string+*count),*(string+*count)=*(string+((*stringLength)-(*count))),*(string+((*stringLength)-(*count)))=*(aux);
        (*count)++;
    }
}

/**
Procedimiento que transforma a un double a una cadena de caracteres
Parametros:
    -n(double*): Puntero al numero a convertir en cadena de caracteres.
Return(char*): Puntero a una cadena de caracteres la cual contiene al número n.
*/
char * doubleToString(double * n){
    char * string;
    double * number;
    int * count;
    int * digit;
    string=(char *) malloc(sizeof(char)*10);
    number=(double *) malloc(sizeof(double));
    count=(int *) malloc(sizeof(int));
    digit=(int *) malloc(sizeof(int));
    *number=*n;
    *count=0;
    while(!((-9<=(*number)) && ((*number)<=9))){
        *digit=(int) fmod ((*number),10.0);
        string=agregarCaracterFinal(string, count, digit);
        *number=floor(((*number)/10.0));
        (*count)++;
    }
    *digit=(int) *number;
    string=agregarCaracterFinal(string, count, digit);
    reverse(string, count);
    free(number);
    free(count);
    free(digit);
    return string;
}

/**
Procedimiento que verifica si una cadena esta compuesta únicamente por 0.
Parametros:
    -n(char*): Puntero a una cadena de caracteres.
Return(int*): Un puntero que apunta a:
        .0 si n NO es puramente 0.
        .1 si n es puramente 0.
        El estapacio en memoria apuntado por el puntero
        debe ser liberado con un free()
*/
int * only0Verification(char * n){
    int * only0;
    int * count;
    only0=(int *) malloc(sizeof(int));
    count=(int *) malloc(sizeof(int));
    *only0=(*n)=='\0';
    if(!(*only0)){
        *only0=1;
        *count=0;
        while(*(n+(*count)) && *only0){
            if(*(n+(*count))!='0') *only0=0;
            (*count)++;
        }
    }
    return only0;
}
