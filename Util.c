#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
Funcion que simula un mapeo de claves caracteres y valores enteros.
Parametros:
    -n: caracter que es ingresado como clave
Return: Puntero a un valor entero que esta relacionado con n
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
Funcion que devuelve si una cadena de caracteres es un número en una base
Parametros:
    -n: es un puntero a la cadena de caracteres
        que es el numero.
    -baseInicial: es la base que quiere ver si n puede ser expresada
Return: Puntero a:
        -0 si es que n no puede ser expresado en la base
        -1 si es que n puede ser expresado en la base
        -10 si es que n puede ser expresado en la base ERROR
*/
int * isValid(char * n, int * base){
    int * validity;
    int * cantFrac;
    int * i;
    int * value;

    validity=(int *) malloc(sizeof(int));
    cantFrac=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));
    value=(int *) malloc(sizeof(int));

    *validity=1;
    *cantFrac=0;
    *i=0;
    for(;(*(n+*i)!='\0') && (*cantFrac)<2 && (*validity); (*i)++){
        if((*(n+*i))=='.' || (*(n+*i))==',') (*cantFrac)++;
        else{
            value=getValue((n+*i));
            if(value==NULL || (*value)>=(*base)) *validity=0;
            free(value);
        }
    }
    if(*(cantFrac)>=2) *validity=0;
    free(cantFrac);
    free(i);
    return validity;
}

/**
Funcion que simula un mapeo de claves enteras y valores en caracteres.
Parametros:
    -n: entero que es ingresado como clave
Return: Puntero a un caracter que es el valor relacionado con n
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
    -n: Puntero al primer elemento de una cadena de caracteres
Return: Puntero al entero que dice la cantidad de caracteres.
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
Luego, referenciara a las partes enteras y partes fraccional a dos parametros de entrada.
Parametros:
    -n: Puntero al primer elemento de la cadena de caracteres.
    -parteEntera: Puntero a un caracter que servirá para devolver la parte entera.
    -parteFraccionaria: Puntero a un caracter que servirá para devolver la parte fraccional.
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
    -strNum: es la cadena de caracteres que representa el numero
    -cantDig: es la cantidad de digitos que tiene el numero,
        sin contar el caracter nulo ('\0').
    -digito: es el nuevo digito que quiere agregarse al
        final de la cadena de caracteres.
Return: un nuevo puntero que indica la nueva ubicacion en
    memoria de la cadena de caracteres.
*/
char* agregarCaracterFinal(char* strNum, int * cantDig, int * digito){
    char *nuevoPunt;
    char *carac;

    carac = (char *) malloc(sizeof(char));

    nuevoPunt = (char *) realloc(strNum,((*cantDig)+1)*sizeof(char));

    carac = isValue(digito);
    *(nuevoPunt+(*cantDig))=*carac;
    *(nuevoPunt+(*cantDig)+1)='\0';

    free(carac);

    return nuevoPunt;
}

/**
Procedimiento que transforma a una cadena de caracteres en su reverso.
Parametros:
    -string: Puntero al primer elemento de la cadena de caracteres.
    -stringLength: Puntero a un entero que dirá la longitud de string.
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
Procedimiento que transforma a un entero a una cadena de caracteres
Parametros:
    -n: Puntero al numero a convertir en cadena de caracteres.
Return: Puntero a una cadena de caracteres la cual contiene al número n.
*/
char * integerToString(int * n){
    char * string;
    int * number;
    int * count;
    int * digit;
    string=(char *) malloc(sizeof(char)*10);
    number=(int *) malloc(sizeof(int));
    count=(int *) malloc(sizeof(int));
    digit=(int *) malloc(sizeof(int));
    *number=*n;
    *count=0;
    while(!((-9<=(*number)) && ((*number)<=9))){
        *digit=(*number)%10;
        string=agregarCaracterFinal(string, count, digit);
        *number=((*number)/10);
        (*count)++;
    }
    string=agregarCaracterFinal(string, count, number);
    reverse(string, count);
    free(number);
    free(count);
    free(digit);
    return string;
}

/**
Procedimiento que verifica si una cadena esta compuesta únicamente por 0.
Parametros:
    -n: Puntero a una cadena de caracteres.
Return: 0 si n NO es puramente 0.
        1 si n es puramente 0.
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

//#define TEST_UTIL
#ifdef TEST_UTIL
int main(){
    int base, bingChilling;
    int * tres;
    int * bingus;
    tres=(int *) malloc(sizeof(int));
    bingus=(int *) malloc(sizeof(int));
    *tres=1;
    *bingus=11;
    char * string[3];
    *string='n';
    *(string+1)=' ';
    *(string+2)='\n';
    addTerminalChar(string, tres, bingus);
    printf("%s",string);
   /* base=16;
    if(*isValid(string,base)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
    int * testIsValue;
    testIsValue=(int *) malloc(sizeof(int));
    for(int i=0;i<16;i++){
        *testIsValue=i;
        printf("1 a %c \n",*isValue(testIsValue));
    }
    bingChilling=
    printf("Length of string %i \n",*stringLength(string));
    char entera[4];
    char fraccionaria[4];
    separateComma(string,entera,fraccionaria);
    printf("Parte entera %s \n",entera);
    printf("Parte fraccionaria %s",fraccionaria);*/
    return 0;
}
#endif // TEST_UTIL
