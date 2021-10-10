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
    verificarValores(registroParam);
    cambioDeBaseNumero(registroParam);

    destructor(registroParam);
    exit(EXIT_SUCCESS);
    #else
    ejecutarTest();
    #endif // TESTER2
    return 0;
}
