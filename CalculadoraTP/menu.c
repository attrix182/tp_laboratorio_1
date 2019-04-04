#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int pedirOpcionMenu(float valorActual1, float valorActual2)
{
    int opcion;
    printf(" 1. Ingresar 1er operando %.2f \n 2. Ingresar 2do operando %.2f \n 3. Calcular todas las operaciones\n 4. Informar resultados\n 5. Salir\n", valorActual1, valorActual2);
    scanf("%d", &opcion);

    return opcion;

}
