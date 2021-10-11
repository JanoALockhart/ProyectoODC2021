#include <math.h>
#include <stdlib.h>

#include "convertirFraccionario.h"
#include "Util.h"
#include "impresion.h"

/**
Función devuelve el resultado de transformar el numero
fraccionario desde su base de origen a base 10. Si la
parte fraccionaria es 0, se imprime un mensaje indicando
que la conversión es directa.
Parámetros:
    -fraccionario(char*): es un puntero a la cadena de caracteres
        que es el numero fraccionario. No debe ser NULL
    -baseInicial(int): es la base en la que encuentra el numero fraccionario
    -pasoAPaso(int): indica si cada paso de la resolucion debe imprimirse por pantalla.
        Si se ingresa 0, no imprime por panralla, con cualquier otro numero se imprime.
Return(float*): un puntero a float que almacena el numero fraccionario en base 10.
    El espacio en memoria al que apunta el puntero debe liberarse con un free()
*/
float* transformarFraccionarioAB10(char *fraccionario, int baseInicial, int pasoAPaso){
    float *total;      //puntero a float que almacena el fraccionario en base 10
    int *pos;          //puntero a int auxiliar para la posicion de la cadena
    int *valor;        //puntero a int auxiliar que almacena el valor en base 10 del caracter
    char *pCarac;      //puntero a char auxiliar que almacena un caracter
    int *exponente;
    int *only0;

    total = (float *) malloc(sizeof(float));
    only0=only0Verification(fraccionario);

    *total=0.0;
    if(pasoAPaso){
        mostrarTitulo("PARTE FRACCIONARIA DE BASE ORIGEN A BASE 10");
    }
    if(!(*only0)){
        pos = (int *) malloc(sizeof(int));
        valor = (int *) malloc(sizeof(int));
        pCarac = (char *) malloc(sizeof(char));
        exponente = (int *) malloc(sizeof(int));

        *pos=0;
        *valor=0;
        *pCarac = *(fraccionario+(*pos));

        while(*pCarac!='\0'){
            valor = getValue(pCarac);
            *exponente = (*pos)+1;
            *total += (*valor)*(1/pow(baseInicial,*exponente));
            if(pasoAPaso){
                papFractionaryOBaseT10Base(total, valor, &baseInicial, exponente); // here
            }
            (*pos)++;
            *pCarac = *(fraccionario+(*pos));
        }

        free(pos);
        free(valor);
        free(pCarac);

    }else if(pasoAPaso){
        msgConversionDirecta();
    }

    free(only0);
    return total;
}

/**
Esta funcion calcula la parte fraccionaria de la base
10 a la base de destino, armando una cadena. Si no hay
parte fraccionaria que convertir, es decir, que fraccionario
es igual a 0, se imprime un mensaje que indica que la conversión
es directa.
Parametros:
    -fraccionario(float): es el numero fraccionario en base 10
        que será llevado a la base destino.
    -baseDestino(int): es la base a la que será pasado el
        número fraccionario.
    -pasoAPaso(int): Si es 0, no muestra por pantalla los
        pasos realizados para obtener el resultado.
        Caso contrario si lo hace.
Return(char*): un puntero a una cadena de caracteres que representa
    el numero fraccionario sin el "0." al principio.
    El espacio de memoria apuntado por el puntero debe
    liberarse con un free().
*/
char* transformarFraccionarioABaseDestino(float fraccionario, int baseDestino, int pasoAPaso){
    float *numIntermedio, *fraccImprimir;
    int *cantDigitos, *digitoEntero;
    char *result;
    result = (char *) malloc(sizeof(char));
    *result = '\0';

    if(pasoAPaso){
        mostrarTitulo("PARTE FRACCIONARIA DE BASE 10 A BASE DESTINO");
    }
    if(fraccionario!=0){
        numIntermedio = (float *) malloc(sizeof(float));
        cantDigitos = (int *) malloc(sizeof(int));
        digitoEntero = (int *) malloc(sizeof(int));
        fraccImprimir = (float *) malloc(sizeof(float));

        *cantDigitos=0;
        *numIntermedio = fraccionario;

        while((*cantDigitos)<MAX_PARTE_FRACC_OUTPUT){
            *fraccImprimir = *numIntermedio;
            (*numIntermedio) = (*numIntermedio)*baseDestino;
            *digitoEntero = (int)floor(*(numIntermedio));
            result = agregarCaracterFinal(result, cantDigitos, digitoEntero);
            if(pasoAPaso){
                papFractionary10BaseTDBase(&baseDestino, fraccImprimir, digitoEntero);
            }
            (*cantDigitos)++;
            *numIntermedio = (*numIntermedio)-floor(*numIntermedio);
        }
        free(numIntermedio);
        free(cantDigitos);
        free(digitoEntero);
        free(fraccImprimir);
    }else if(pasoAPaso){
        msgConversionDirecta();
    }
    return result;
}

