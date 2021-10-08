#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"
#include "lectorArgumentos.h"
#include "conversionNumero.h"
#include "verificadorArgumentos.h"


#define TESTER
int main(int argc, char** argv)
{

    #ifdef TESTER
    ejecutarTest();
    #endif // TESTER
    tArgumentos1 *registroParam = malloc(sizeof(tArgumentos1));
    registroParam = almacenarValores(argc, argv); //REVISAR

    #ifdef TESTER
    ejecutarTest();
    printf("Bing chilling \n");
    printf("Campos del registro: \n");
    printf("%s \n",registroParam->argN);
    printf("%s \n",registroParam->argS);
    printf("%s \n",registroParam->argD);
    printf("%i \n",registroParam->argV);
    printf("%i \n",registroParam->argH);
    #endif // TESTER

    ejecuccion(registroParam);
    exit(EXIT_SUCCESS);
    return 0;
}
