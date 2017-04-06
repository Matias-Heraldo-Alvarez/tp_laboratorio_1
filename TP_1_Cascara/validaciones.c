#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"

/** \brief Muestra por pantalla una tabla de resultados de las operaciones basicas mas factorial.
 *
 * \param ResulDivision guarda y muestra el valor pasado por division()y luego se usa para iprimirlo en pantalla.
 * \param number1 guarda el valor pasado por la funcion prncipal y se utiliza para todos los calculos.
 * \param number2 guarda el valor pasado por la funcion prncipal y se utiliza para todos los calculos.
 * \return (void).
 *
 */
void basicOperation(float number1,float number2)
{
 long int FactorialResult;
 float resultl;
 float ResultDivision;

    system("cls");
    printf("\t\t|-------------------------------------------------|\n");//ok
    printf("\t\t TABLA DE RESULTADOS:\n");

    resultl = sum(number1,number2);
    printf("\t\t Resultado:%.1f+%.1f = %.1f\n\n",number1,number2,resultl);//ok

    resultl = subtraction(number1,number2);
    printf("\t\t Resultado:%.1f-%.1f = %.1f\n\n",number1,number2,resultl);//ok

    ResultDivision = division(number1,number2);//ok
    if(ResultDivision == -1){printf("\t\t ERROR:(NO ES POSIBLE LA DIVISION ENTRE CERO(0).)\n\n");}
    else{printf("\t\t Resultado:%.1f%%%.1f = %.1f\n\n",number1,number2,ResultDivision);}

    FactorialResult = validaFacorialTable(number1);
    if(FactorialResult == number1)
    {FactorialResult = getFactorial(number1);printf("\t\t Reslutado:%0.f!      = %ld\n\n",number1,FactorialResult);}
    else{printf("\t\t Reslutado:A! =NO DISPONIBLE\n\n");}

    resultl = multiply(number1,number2);//ok
    printf("\t\t Resultado:%.1fx%.1f = %.1f\n\n",number1,number2,resultl);

    printf("\t\t|-------------------------------------------------|\n\n\n\n\n\t");
    system("pause");
}

/** \brief valida el numero para ser utilizado para dicho calculo..
 *
 * \param  number contiene el valor pasado por el programa.
 * \return el numero recivido pasado a tipo entero.
 */
int validaFacorialTable(float number)
{
  int entero;

  entero = number;
  if(number != entero || number<= -1){entero=0;}
  return entero;
}

/** \brief valida el numero pasado por el programa para utilizarlo en dicho calculo.
 * \param number guarda el valor ásado por el programa para una pasarlo a entero.
 *
 * \return entero
 */
int validaFacorial(float number)
{
  int entero;

  entero = number;
  if(number != entero || number<= -1){entero=0;FACTORIAL_ERROR}
  return entero;
}


/** \brief Valida en ingreso de numeros unicamente .
 *
 * \param number guarda el valor pasado por el programa.
 * \return valid.
 *
 * El metodo de validacion respode a la caracteristica de scanf() que
 * de no poder leer el numero nos retorna 0 y de poder hacerlo retorna 1.
 */
float validoOperando(float number)//ok
{
    float valid= number+1;

    system("cls");
    printf("\tOperando:");
    fflush(stdin);
    if(scanf("%f",&number)!= 1){printf("\n\tERRROR(caracter invlido.)");system("pause");}
    else{valid = number;}

    return valid;
}

/** \brief pide un numero al usuario lo analisa y devuelve el valor ingrsado
 *
 * \return option guarda el valor ingresado por usuario.
 *
 *         La metodologuia de validacion cosiste en la comparacion
 *         del valor asignado a los limites establecidos en un intervalo de 9 a 1.
 *         Ademas se tiene en cuenta lacaracteristica de scanf() de tener diferente retornso
 *         dependiendo de s pudo leer un  valor a no osilando entre 0 y 1 .
 */
int validoOpcion()
{
    int option;

    fflush(stdin);
    if(scanf("%d",&option)!= 1 || (option <= 0 || option >=10 )){printf("\t\tOPCION INVALIDA.");system("pause");option=0;}
    return option;
}

/** \brief verifica que el valor recibido posea solo numeros.
 *
 * \param srt Array trae la cadena a ser aalizada.
 * \return 1 si es numerico elguna de sus posiciones sino = 0.
 *
 */
int soloNumeros(char str[])
{
    int i=0;
    int result =1 ;
    while(str[i] != '\0')
    {
        if(str[i]< '0' || str[i] > '9'){result =0;}
        i++;
    }
    return result;
}


/** \brief verifica que el valor recivido contenga solo letras.
 *
 * \param str Array trae la cadena a ser avaluada.
 *
 * \return 1 en caso no poseer numeros 0 en caso de que si.
 *
 */
int soloLetras(char str[])
{
    int i = 0;
    int result = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')&& (str[i]< 'a' || str[i]> 'z')&&(str[i]< 'A' || str[i]> 'Z')){result = 1;}
        i++;
    }

    return result;
}

/** \brief verifica que el valor recivido contenga solo alfanumericos.
 *
 * \param str Array trae la cadena a ser avaluada.
 *
 * \return 1 en caso no ser solo alfanumericos 0 encaso de que si.
 *
 */
int soloAlfanumericos(char str[])
{
    int i = 0;
    int result = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')&& (str[i]< 'a' || str[i]> 'z')&&(str[i]< 'A' || str[i]> 'Z')&&(str[i]< '0'|| str[i]> '9')){result = 1;}
        i++;
    }

    return result;
}


/** \brief  verifica que la cadena recibid sea solo numero telefonico.
 *
 * \param str Array contiene la cadena a evaluar.
 *
 * \return 0 en caso de que sea un telefono 1 en caso de no serlo.
 *
 */

int esTelefono(char str[])
{
    int i,contadorGuion = 1,result = 0;

    while(str[i] != '\0')
    {
        if((str[i] !=' ' )&&(str[i]< '0' || str[i]> '9')){result = 1;}
        if(str[i] != '-'){contadorGuion ++;}
        i++;

    }
    if(contadorGuion ==1){result = 1;}
    return result;
}
