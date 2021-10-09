#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"
#include "lectorArgumentos.h"
#include "conversionNumero.h"
#include "verificadorArgumentos.h"

//#define TESTER

int main(int argc, char** argv)
{
    tArgumentos1 *registroParam;

    registroParam = almacenarValores(argc, argv);
    #ifdef TESTER
    printf("ArgN: %s\n",registroParam->argN);
    printf("ArgS: %s\n",registroParam->argS);
    printf("ArgD: %s\n",registroParam->argD);
    printf("ArgV: %i\n",registroParam->argV);
    printf("ArgH: %i\n",registroParam->argH);
    #endif // TESTER
    verificarValores(registroParam);
    cambioDeBaseNumero(registroParam);

    exit(EXIT_SUCCESS);
    return 0;
}
