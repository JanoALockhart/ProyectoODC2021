#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"
#include "lectorArgumentos.h"
#include "conversionNumero.h"
#include "verificadorArgumentos.h"

//#define TESTER
//#define TESTER2
int main(int argc, char** argv)
{
    #ifndef TESTER2


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

>>>>>>> f1fbfabbf2f77f95028a7ae047c2605babf64914
    exit(EXIT_SUCCESS);
    #else
    ejecutarTest();
    #endif // TESTER2
    return 0;
}
