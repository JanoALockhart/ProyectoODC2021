#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"

#define TESTER

int main(int argc, char** argv)
{
    #ifndef TESTER
    char *numTransformado;
    tArgumentos1 *registroParam = malloc(sizeof(tArgumentos1));

    registroParam = verificarEntrada(argc, argv); //REVISAR
    numTransformado = cambiarNumDeBase(registroParam);
    mostrarResultFinal(numTransformado);
    exit(EXIT_SUCCESS);
    #else
    ejecutarTest();
    #endif // TESTER
    return 0;
}
