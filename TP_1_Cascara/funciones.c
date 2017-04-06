                                             //ok
#include "funciones.h"
#include "validaciones.h"

/** \brief toma el valor pasado por  el programa y devuelve el factorial del mismo.
 *
 * \param numero es el valor que se le pasa a la funcion para ser calculado.
 * \return resultado.
 */

int getFactorial(int numero)//ok
{
    long int resultado = 0;

    if(numero >0){resultado = numero*getFactorial(numero - 1);}
    else{ resultado = 1;}

    return resultado;
}

/** \brief toma 2 valores y devuelve la suma entre ellos.
 *
 * \param num1 pasa el primar valor a calcular.
 * \param num2 pasa el segundo valor a calcular.
 * \return result.
 *
 */
float sum(float num1,float num2)//ok
{
 float result;

 result= num1+num2;
 return result;
}

/** \brief toma 2 valores y devuelve la resta entre ellos.
 *
 * \param num1 paesa el primer valor.
 * \param num2 pasa el segundo valor.
 * \return result.
 *
 */
float subtraction(float num1,float num2)//ok
{
    float result;

    result = num1 - num2;
    return result;
}

/** \brief toma 2 valores y devuelve el la mutiplicacion  entre ellos.
 *
 * \param num1 pasa  el primer valor .
 * \param num2 pasa el segundo valor.
 * \return result.
 *  en caso de que algun valor pasado sea 0 result -1.
 */
 float division(float num1,float num2)//ok
{
     float result;


     if(num1==0 || num2==0){result = -1;}
     else{result = (float) num1/num2;}
     return  result;
}

/** \brief toma 2 valores y devuelve la division entre ellos.
 *
 * \param num1 toma el primer valor .
 * \param num2 toma el segundo valor.
 * \return result.
 *  en caso de que algun valor pasado sea 0 result -1.
 */
float multiply(float num1,float num2)//ok
{
    float result;

    result = num1*num2;
    return result;
}

