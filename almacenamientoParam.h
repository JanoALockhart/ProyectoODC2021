#ifndef ALMACENAMIENTOPARAM_H_INCLUDED
#define ALMACENAMIENTOPARAM_H_INCLUDED


typedef struct argumentos{
    char *argN;     //Almacena el numero que será cambiado de base
    char *argS;     //Almacena la base de origen del numero
    char *argD;     //Almacena la base de destino del numero
    int argV;       //Indica si se deben mostrar pasos intermedios o no
    int argH;       //Indica si el parametro ayuda fue ingresado
} tArgumentos1;

void constructor(tArgumentos1* registro);
void destructor(tArgumentos1* registro);

#endif // ALMACENAMIENTOPARAM_H_INCLUDED
