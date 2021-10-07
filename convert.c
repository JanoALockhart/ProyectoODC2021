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
    ejecuccion(registroParam);

    exit(EXIT_SUCCESS);
    return 0;
}
