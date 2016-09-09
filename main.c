#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "funciones.h"

/** \brief Inicializa el menú y pide una opción para evaluar.
 *
 * \param Evalúa que el usuario quiera continuar en el programa, hasta que ingrese la opción 9.
 * \param Toma la opción ingresada por el usuario e ingresa a uno de los casilleros del switch.
 * \return
 *
 */

int main()
{
    char seguir='s';
    int opcion=0;
    float num1 = 0, num2 = 0;
    char flag1 = 's';
    char flag2 = 's';
    menu(num1, num2, flag1, flag2);
    do
       {
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                printf("Ingrese A = ");
                num1 = ingrese();
                flag1 = 'n';
                menu(num1, num2, flag1, flag2);
                break;
            case 2:
                printf("Ingrese B = ");
                num2 = ingrese();
                flag2 = 'n';
                menu(num1, num2, flag1, flag2);
                break;
            case 3:
                menu(num1, num2, flag1, flag2);
                printf("\nEl resultado de la Suma es %f\n\n\n", suma(num1,num2));
                break;
            case 4:
                menu(num1, num2, flag1, flag2);
                printf("\nEl resultado de la Resta es %f\n\n\n", resta(num1,num2));
                break;
            case 5:
                menu(num1, num2, flag1, flag2);
                num2 = vDiv(num2);
                flag2 = 'n';
                printf("\nEl resultado de la División es %f\n\n\n", division(num1,num2));
                break;
            case 6:
                menu(num1, num2, flag1, flag2);
                printf("\nEl resultado de la Multiplicación es %f\n\n\n", multiplicacion(num1,num2));
                break;
            case 7:
                menu(num1, num2, flag1, flag2);
                num1 = vFact(num1);
                printf("\nEl resultado del Factorial de A es %llu\n\n\n", factorial(num1));
                break;
            case 8:
                menu(num1, num2, flag1, flag2);
                todas(num1, num2);
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                menu(num1, num2, flag1, flag2);
                printf("No es una opción válida\n\n\n");
                break;
        }
    }
    while(seguir=='s');

    return 0;
}
