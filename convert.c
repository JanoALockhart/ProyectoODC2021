#include <stdio.h>
#include <stdlib.h>
#include "almacenamientoParam.h"

int main(int argc, char** argv)
{
    char *numTransformado;
    tArgumentos1 *registroParam = malloc(sizeof(tArgumentos1));

    registroParam = almacenarValores(argc, argv); //REVISAR
    numTransformado = cambiarNumDeBase(registroParam);
    mostrarResultFinal(numTransformado);
    exit(EXIT_SUCCESS);
    return 0;
}
