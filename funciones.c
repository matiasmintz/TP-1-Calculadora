#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "funciones.h"

/** \brief Limpia la pantalla e imprime el menú.
 *
 * \param Recibe el Primer Operando, ingresado en el Main.
 * \param Recibe el Segundo Operando, ingresado en el Main.
 * \param Recibe el Flag del Primer Operando para determinar si muestra el Dato.
 * \param Recibe el Flag del Segundo Operando para determinar si muestra el Dato.
 * \return
 *
 */

void menu (float num1, float num2, char flag1, char flag2){
system("cls");
if (flag1 != 's'){
            printf("1- Ingresar 1er operando (%f)\n",num1);
        }
        else{
            printf("1- Ingresar 1er operando A = x\n");
        }
        if (flag2 != 's'){
            printf("2- Ingresar 2do operando (%f)\n",num2);
        }
        else{
            printf("2- Ingresar 2do operando B = y\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");
}

/** \brief Toma un número, valida que sea número y lo devuelve.
 *
 * \param Corrobora que lo que se ingresó en el scanf sea un Flotante.
 * \return Número validado
 *
 */

float ingrese (void){
    int check;
    float num;
    fflush(stdin);
    check = scanf("%f", &num);

    while (check == 0){
        printf("Ingrese un dato válido.\n");
        fflush(stdin);
        check = scanf("%f", &num);
    }

    return num;
}

/** \brief Valida que el operando no sea cero.
 *
 * \param Toma el segundo operando y pide que se reingrese hasta que sea distinto de cero.
 * \return Numero validado.
 *
 */

float vDiv (float y){
    while (y == 0){
        printf("\n0 no puede ser divisor. Reingrese\n");
        y = ingrese();
    }
    return y;
}

/** \brief Valida que el operando no sea flotante, ni menor a 0, ni mayor a 65 (desborda).
 *
 * \param Toma el segundo operando y pide que se reingrese.
  * \return Número validado.
 *
 */

float vFact(float x){

    while (x < 0 || ceilf(x) != x || x > 65){
        printf("\nEl número debe ser entero, positivo y menor a 65.\n");
        x = ingrese();
    }
return x;
}

/** \brief Suma dos operandos.
 *
 * \param Primer Operando
 * \param Segundo Operando.
 * \return Resultado de la suma.
 *
 */

float suma (float x, float y){
    return x + y;
}
/** \brief Resta dos operandos.
 *
 * \param Primer Operando
 * \param Segundo Operando.
 * \return Resultado de la resta.
 *
 */
float resta (float x, float y){
    return x - y;
}

/** \brief Divide dos operandos.
 *
 * \param Primer Operando
 * \param Segundo Operando (Validado).
 * \return Resultado de la división.
 *
 */
float division (float x, float y){
    return x / y;
}

/** \brief Multiplica dos operandos.
 *
 * \param Primer Operando
 * \param Segundo Operando.
 * \return Resultado de la multiplicación.
 *
 */
float multiplicacion (float x, float y){
    return x * y;
}

/** \brief Factorial de un operando (validado).
 *
 * \param La función se ejecuta sobre sí misma hasta que el operando es 1.
 * \return Resultado de la función recursiva.
 *
 */
unsigned long long factorial (int x){

    if (x>= 1){
    return x*= factorial(x-1);
    }
    else{
       return 1;
    }

}

/** \brief Muestra el resultado de todas las operaciones. En caso de que haya un error, lo explica.
 *
 * \param Primer Operando (sin validar).
 * \param Segundo Operando (sin validar).
 * \return
 *
 */

float todas (float x, float y){
                printf("\n\n\nEl resultado de la Suma es %f\n", suma(x,y));
                printf("El resultado de la Resta es %f\n", resta(x,y));
                printf("El resultado de la Multiplicación es %f\n", multiplicacion(x,y));
                if (y == 0){
                    printf ("Como el segundo operando es 0 no se puede realizar división.\n");
                }
                else{
                printf("El resultado de la División es %f\n", division(x,y));
                }
                if (x <0 || x != ceilf(x)){
                    printf ("Como el primer operando es negativo, flotante o mayor a 65 no se puede realizar el factorial.\n");
                }
                else{
                printf("El resultado del Factorial de A es %llu\n\n\n", factorial(x));
                }
return 0;
}
