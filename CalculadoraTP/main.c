#include <stdio.h>
#include <stdlib.h>
#include "funciones_calculadora.h"
#include "menu.h"

int main()
{
    int opcion;
    int flagIngreso = 0;
    int flagCalcular = 0;
    int flagCalculosListos = 0;
    float a = 0;
    float b = 0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    double factorialA;
    double factorialB;
    char seguir = 's';

    do
    {

        printf("\n         ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
        printf("\n         บ               :: C A L C U L A D O R A EN C ::            บ");
        printf("\n         ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน \n");
        printf("\n");

        opcion = pedirOpcionMenu(a, b);
        switch(opcion)
        {
        case 1:
            printf("\n         -> Ingrese Primer operando A: ");
            scanf("%f", &a);
            fflush(stdin);
            flagIngreso = 1;
            break;
        case 2:
            if(flagIngreso == 1)
            {
                printf("\n         -> Ingrese Segundo operando B: ");
                scanf("%f", &b);
                fflush(stdin);
                flagCalcular = 1;
                break;
            }
            else
            {
                printf("Primero ingrese el primer operando...\n");
                break;
            }
        case 3:
            if (flagCalcular == 1)
            {
                suma = sumar(a, b);
                resta = restar(a, b);
                multiplicacion = multiplicar(a, b);
                division = dividir(a, b);
                factorialA = factorial(a);
                factorialB = factorial(b);
                flagCalculosListos = 1;
                printf("Operaciones calculadas, digite 4 para ver los resultados...\n");
                break;
            }
            else
            {
                printf("Error, ingrese primero los operandos...\n");
                break;
            }
        case 4:
            if (flagCalculosListos == 1)
            {
                printf("\n La suma de %.2f + %.2f = %.2f \n ", a, b, suma);
                printf("\n La resta de %.2f - %.2f = %.2f \n ", a, b, resta);

                if (b == 0)
                {
                    printf("\n La division de %.2f / %.2f = %s \n ", a, b, "No es posible dividir por 0");
                }
                else
                {
                    printf("\n La division de %.2f / %.2f = %.2f \n ", a, b, division);
                }

                printf("\n La multiplicacion de %.2f * %.2f = %.2f \n ", a, b, multiplicacion);

                if(a < 0)
                {
                    printf("\n El factorial de %2.f es : %s \n ", a, "No existe el factorial de un numero negativo");
                }
                else
                {
                    printf("\n El factorial de %2.f es : %.2f \n ", a, factorialA);


                }

                if(b < 0)
                {
                    printf("\n El factorial de %2.f es : %s \n ", b, "No existe el factorial de un numero negativo");
                }
                else
                {
                    printf("\n El factorial de %2.f es : %.2f \n ", b, factorialB);
                }

                break;
            }
            else
            {
                printf("Error. Nada para mostrar. Verifique los pasos anteriores \n");
                break;
            }
        case 5:
            seguir = 'n';
            break;

        default:
            printf("Opcion incorrecta\n");
            break;
        }

        system("pause");
        system("cls");

    }
    while(seguir == 's');

    return 0;
}


