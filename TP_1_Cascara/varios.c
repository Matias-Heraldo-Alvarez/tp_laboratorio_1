#include <stdio.h>
#include <stdlib.h>
#include "varios.h"


/** \brief imprime un panel principal con opciones de ingreso numricos y calculos matematicos.
 *
 * \param  operando1 guarda el primer valor a calcular.
 * \param  operando2 guarda el segundo valor a calcular.
 * \param number1 guardan valores que validan la carga del primer valor a calcular.
 * \param number2 guardan valores que validan la carga del segundo valor a calcular.
 *
 * \return (void).
 *        En caso de que los valores de que vlidan las cargas de nuevos datos sean
 *        negativos los imprimira reemplazando los numeros por X e Y .
 */
void chargePanel(float number1,float number2,int oprando1,int operando2)//OK
{
    char A = 'A',B = 'B';

    system("color f0");
    if(oprando1!= 0 ) {printf("\t\t|1- Ingresar 1er operando (%c=%.3f)\t\t\t|\n\n",A,number1);}
    else              {printf("\t\t|1- Ingresar 1er operando (%c=X)\t\t\t|\n\n",A);}

    if(operando2!= 0 ){printf("\t\t|2- Ingresar 2do operando (%c=%.3f)\t\t\t|\n\n",B,number2);}
    else              {printf("\t\t|2- Ingresar 2do operando (%c=Y)\t\t\t|\n\n",B);}

    printf("\t\t|3- Calcular la  suma (%c+%c)\t\t\t|\n\n",A,B);
    printf("\t\t|4- Calcular la resta (%c-%c)\t\t\t|\n\n",A,B);
    printf("\t\t|5- Calcular la division (%c%%%c)\t\t\t|\n\n",A,B);
    printf("\t\t|6- Calcular la multiplicacion (%c*%c)\t\t|\n\n",A,B);
    printf("\t\t|7- Calcular el factorial (%c!)\t\t\t|\n\n",A);
    printf("\t\t|8- Calcular todas las operacione\t\t|\n\n");
    printf("\t\t|9- Salir\t\t\t\t\t|\n");
}
