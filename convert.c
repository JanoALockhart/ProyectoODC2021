#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"

#define TESTER

int main(int argc, char argv[])
{
    #ifndef TESTER
    tArgumentos1 *registroParam = malloc(sizeof(tArgumentos1));
    registroParam = verificarEntrada(argc, argv);
    ejecucion(registroParam);
    exit(EXIT_SUCCESS);
    #else
    ejecutarTest();
    #endif // TESTER
    return 0;
}
