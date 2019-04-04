#include <stdio.h>
#include <stdlib.h>
#include "funciones_calculadora.h"

float sumar (float numero1, float numero2)
{
    return numero1 + numero2;

}

float restar (float numero1, float numero2)
{
    return numero1 - numero2;
}

float dividir (float numero1, float numero2)
{
    return numero1 / numero2;
}

float multiplicar (float numero1, float numero2)
{
    return numero1 * numero2;
}

double factorial (double numero)
{
    double acumulador = 1;
    for (double i=numero; i>0; i--)
    {
        acumulador *= i;

    }
    return acumulador;
}
