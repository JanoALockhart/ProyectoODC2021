#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"
#include "lectorArgumentos.h"
#include "conversionNumero.h"
#include "verificadorArgumentos.h"


//#define TESTER
int main(int argc, char** argv)
{
    tArgumentos1 *registroParam = malloc(sizeof(tArgumentos1));
    registroParam = almacenarValores(argc, argv); //REVISAR
    printf("Campos del registro: \n");
    printf("%s ",registroParam->argN);
    printf("%s ",registroParam->argS);
    printf("%s ",registroParam->argD);
    printf("%i ",registroParam->argV);
    printf("%i \n",registroParam->argH);
    ejecuccion(registroParam);
    printf("LLego al final\n");
    exit(EXIT_SUCCESS);
    return 0;
}
