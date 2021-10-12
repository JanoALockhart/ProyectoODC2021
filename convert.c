#include <stdlib.h>
#include "almacenamientoDatos/almacenamientoParam.h"
#include "input/lectorArgumentos.h"
#include "conversion/conversionNumero.h"
#include "input/verificadorArgumentos.h"

/**
Función principal del programa
Parametros:
    -argc(int): es la cantidad de argumentos ingresados por el usuario.
    -argv(char**): es un puntero a los argumentos que fueron ingresados
        por el usuario a través de la consola.
*/
int main(int argc, char** argv)
{
    tArgumentos1 *registroParam;

    registroParam = almacenarValores(argc, argv);
    verificarValoresYSignar(registroParam);
    cambioDeBaseNumero(registroParam);

    destructor(registroParam);
    exit(EXIT_SUCCESS);
    return 0;
}
