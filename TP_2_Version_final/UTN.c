#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

///Salidas y Entradas___________________________________________________________________________________________________


/** \brief Limpia la pantalla
 *
 * \return (void)
 */
void clearScreen()
{
    #ifdef __unix__
    system("clear");
    #else
    system("cls");
    #endif
}

/** \brief Limpia la pantalla y muestra un mensje de error por un tiempo determinado
 *
 * \param message Es el mensaje a ser mostrado en pantalla.
 * \return (void)
 */
void errorMensaje(char message[])
{
    clearScreen();
    system("color f4");
    printf(message);
    goSleep(3000);
}

/** \brief Limpia la pantalla y muestra un mensje de Advertencia por un tiempo determinado
 *
 * \param message Es el mensaje a ser mostrado en pantalla.
 * \return (void)
 */
void warningMessage(char message[])
{
    clearScreen();
    system("color F6");
    printf(message);
    goSleep(3000);
}

/** \brief Limpia la pantalla y muestra un mensaje de ejecucion exitosa.
 *
 * \param message Es el mensaje a ser mostrado.
 * \param time Es el tiempo de permanencia del mensaje.
 * \return (void).
 */
void SuccessMessage(char message[],int time)
{
    clearScreen();
    system("color F2");
    printf(message);
    goSleep(time);
}

/** \brief Solicita un numero y devuelve el resultado.
 *
 * \param message es el mensaje que se le brinda al usuario.
 * \return el numero ingresado.
 *  El valor guardado esta en formato entero.
 */
int getInt(char message[])
{
    int auxliar;
    printf(message);
    scanf("%d",&auxliar);
    return auxliar;
}


/** \brief Solicita un caracter y devuelve el resultado.
 *
 * \param message es el mensaje que se le brinda al usuario.
 * \return el caracter ingresado.
 *
 */
char getCharacter(char message[])
{
    char auxliar;
    printf(message);

    fflush(stdin); //fpurge(stdin) para sistemas distintos a windows.
    scanf("%c",&auxliar);
    return auxliar;
}


/** \brief Solicita un numero y devuelve el resultado.
*
* \param message el el mensaje que se le brinda al usuario.
* \return el numero ingresado.
* El valor guardado esta en formato flotante.
*/
float getFloat(char message[])
{
    float auxiliar;

    printf(message);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/** \brief imprime un panel principal con opciones de ingreso numricos y calculos matematicos.
 *
 * \param operando1 guarda el primer valor a calcular.
 * \param operando2 guarda el segundo valor a calcular.
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

///__________Entradas Selectivas____________________________________________________________________________________________



/** \brief verifica que el valor recibido posea solo numeros.
 *
 * \param srt Array trae la cadena a ser aalizada.
 * \return 0 si es numerico elguna de sus posiciones sino = EOF.
 *
 */
int soloNumeros(char str[])
{
    int i=0;
    int result = 0;
    while(str[i] != '\0')
    {
        if(str[i]< '0' || str[i] > '9'){result = EOF;}
        i++;
    }
    return result;
}

/** \brief verifica que el valor recivido contenga solo letras.
 *
 * \param str Array trae la cadena a ser avaluada.
 *
 * \return 0 en caso de ser(SOLO LETRAS) y EOF en caso de que NO.
 *
 */
int soloLetras(char str[])
{
    int i = 0;
    int result = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')&& (str[i]< 'a' || str[i]> 'z')&&(str[i]< 'A' || str[i]> 'Z')){result = EOF;}
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
    int i,contadorGuion = 0,result = 0;

    while(str[i] != '\0')
    {
        if((str[i] !=' ' )&&(str[i]< '0' || str[i]> '9')){result = 1;}
        if(str[i] != '-'){contadorGuion ++;}
        i++;

    }
    if(contadorGuion >1){result = 1;}
    return result;
}



///______ARRAYS___________________________________________________________________________



/** \brief Pide un texto al usuario y lo devuelve.
 *
 * \param message es el mensaje a mostrar al usuario.
 * \param input es la cadena de caracteres (string) que devuelve.
 * \return retorna en caso de ser (SOLO LTRAS) 0 y EOF en caso de que NO.
 *
 */
int getStringLetras(char message[],char input[])
{
    char aux[256];
    int retorno = EOF,flag;

    getString(message,aux);
     flag= soloLetras(aux);

    if(flag== 0)
    {strcpy(input,aux);retorno =flag;}

    return retorno;
}


/** \brief Pide una cadena de numeros al usuario y lo devuelve
 *
 * \param message es el mensaje que se muestra al usuario.
 * \param input guarda la cedeana que se devolvera.
 * \return en caso de ser solo numeros 0 de lo contrario EOF.
 */
int getStringNumeros(char message[],char input[])
{
    char aux[256];
    int result = EOF;

    getString(message,aux);
    if(soloNumeros(aux)==0)
    {
        strcpy(input,aux);
        result = 0;
    }
    return result;
}


/** \brief Busca el maximo o el minimo de un array int segun criterio asignado.
 *
 * \param vec[]  Es el array de eneteros asignado para evaluar.
 * \param tam    Es el tamaño o (longitud) del array a evaluar.
 * \param maxMin Es el valor que defina el criterio de busqueda 1:buscar maximo 2: buscar minimo
 * \return retorno El valor buscado.
 *
 */
int MaxoMinArrayInt(int vec[],int tam,int maxMin)
{
    int i,retorno=0;
    if(maxMin == 1)
    {
        for(i=0 ;i<tam ;i++)
        {
            if(vec[i] > retorno ){retorno = vec[i];}
        }
    }
    else if(maxMin == 2)
    {
        for(i=0 ;i<tam ;i++)
        {
            if(vec[i] < retorno){retorno = vec[i];}
        }
    }

    return retorno;
}


/** \brief Busca la primera ocurrencia de un valor en un array de elementos.
 * \param  array es el array donde sera buscado.
 * \param  cantidad_de_elementos indica la longitud de array.
 * \param  valor indica el valor a ser buscado
 * \return si no hay  ocurrencia (-1) y si la hay la posicion de la misma.
 *
 */
int buscarPrimeraOcurrencia(int array[],int cantidad_de_elementos,int valor)
{
    int i;
    int indice = -1;
    for(i=0;i<cantidad_de_elementos;i++)
    {
        if (array[i] == valor ){indice = i;}
    }
    return indice;
}


/** \brief  Imprime el contenido de un array.
 *
 * \param vec[] Es el array designado para imprimir.
 * \param tam Es el tamaño del array (podemos tambien delimitar hasta donde mostrar el array).
 * \param criterio Es el criterio d orden en que mostrar el array 1 para mostrar desde el 0 y 2 para mostrar desde el final.
 *
 */
void printArrayInt(int vec[],int tam,int criterio,char message[])
{
    int i;
    if(criterio == 1)
    {
        for(i=0;i<tam;i++)
        {printf(message);printf("%d",vec[i]);}
    }
    else if(criterio == 2)
    {
        for(i=tam-1;i>=0;i--)
        {printf(message);printf("%d",vec[i]);}
    }

}


/** \brief Ordena un array entero segun el criterio selecionado acendente o decendente .
 *
 * \param vec[] Es el vector que se signa para ordenar.
 * \param tam Es el tamaño del vector a ordenar.
 * \param criterio Es el tipo de ordenamiento 1 = acendente 2 = decendente.
 */
void ordenoArrayInt(int vec[],int tam,int criterio)//OK.
{
    int i,j;
    int auxInt;
    if(criterio==1)
    {
        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(vec[i] < vec[j]){auxInt = vec[i];vec[i] = vec[j];vec[j] = auxInt;}

            }
        }
    }
    else if(criterio == 2)
    {
        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(vec[i] > vec[j]){auxInt =vec[i];vec[i]=vec[j];vec[j]= auxInt;}

            }
        }

    }
}


/** \brief Inicializa un array con el valor recibiso.
 *
 * \param array es el array a ser inicializado.
 * \param cantidad_de_elementos indica la longitud del array.
 * \param valor es el valor que sera cargado en las posiciones.
 * \return _
 *
 */
void inicializaArray(int array[],int cantidad_de_elementos,int valor)
{
    int i;
    for(i = 0; i < cantidad_de_elementos; i ++)
    {
        array[i] = valor;
    }
}


/** \brief toma un dato tipo string (cadena de caracteres) y lo almacena en la direccion que le pasamos
 *
 * \param imput es la dirreccion de memoria que le bridamos para almacenar el string.
 * \param message es el mensaje a mostrar al susuario.
 * \return retorna a la dirreccion de imput el string.
 *
 */
void getString(char message[],char input[])
{
    printf(message);
    fflush(stdin);
    scanf("%[^\n]",input);
}


/** \brief Carga un array o (VECTOR) secuencialmente.
 *
 * \param vec[] Es el array asignado a cargar.
 * \param tam   Es el tamaño o (LONGITUD) del array asignado.
 * \param message Es el mensaje mostrado al usuario para la carga.
 * \param Emessage Es el mensaje mostrado en caso de ingreso erroneo.
 *
 */
void chargeSecuenceArrayInt(int vec[],int tam,char message[],char Emessage[])
{
    int i;
    int *positionVec;

    for(i=0;i< tam;i++)
    {
        positionVec = &vec[i];
        getInts(positionVec,message,Emessage,0,INT_MAX);
    }
}



///__validaciones____________________________________________________________________________________________________________________



/** \brief valida el numero pasado por el programa para utilizarlo en dicho calculo.
 *
 * \param entero toma el valor de number para validar si genera perdida de datos y
 *        en caso de tenerla toma valor =0.
 * \param number guarda el valor ásado por el programa para una pasarlo a entero.
 * \return entero
 *
 */
int validaFacorial(float number)
{
  int entero;

  entero = number;
  if(number != entero || number<= -1){entero=0;FACTORIAL_ERROR}
  return entero;
}


/** \brief pide un numero al usuario lo analisa y devuelve el valor ingrsado
 *
 * \param min Es el rango minimo valido.
 * \param max Es el rango maximo valido.
 * \return option guarda el valor ingresado por usuario.

 *         Ademas se tiene en cuenta lacaracteristica de scanf() de tener diferente retornso
 *         dependiendo de s pudo leer un  valor a no osilando entre 0 y 1 .
 */
int validoOpcion(int min,int max)
{
    int option;

    fflush(stdin);
    if(scanf("%d",&option)!= 1 ||(option < min||option > max)){option=EOF;printf("\t\tOPCION INVALIDA.");goSleep(1000);}
    return option;
}


/** \brief Valida en ingreso de numeros unicamente .
 *
 * \param number guarda el valor pasado por el programa.
 * \param valid toma el valor de number  mas 1 y en caso de ingresar correctamente un valor
 *        por scanf()a number vuelve a tomar el valor actualizado de number.
 * \return valid.
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



///___Aritmeticas___________________________________________________________________________________________________



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



///__________POR REFERENCIA______________________________________________________________________________



/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no EOF.
*
*/
int getInts(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int auxInt;
    int retorno = EOF ;

    printf(message);
    fflush(stdin);
    retorno = scanf("%d",&auxInt);
    if((retorno ==-1)&&(auxInt < lowLimit || auxInt > hiLimit)){printf(eMessage);return retorno;}
    else{*input = auxInt;retorno= 0;}
    return retorno;
}


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int getFloats(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int retorno = -1;
    float auxInt;
    printf(message);
    fflush(stdin);
    if((scanf("%f",&auxInt)!= 1 )&& (auxInt< lowLimit || auxInt > hiLimit)){retorno = -1;printf(eMessage);}
    else{*input = auxInt;retorno = 0;}
    return retorno;
}


/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int getChars(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int retorno = -1;
    char auxChar;

    printf(message);
    fflush(stdin);
    scanf("%c",&auxChar);
    if(auxChar < lowLimit||auxChar > hiLimit){printf(eMessage);retorno = -1;}
    else{*input =auxChar; retorno =0;}
    return retorno;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int getStrings(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int retorno = -1,zise;
    char auxStr[256];
    printf(message);
    fflush(stdin);
    scanf("%s",auxStr);
    zise = strlen(auxStr);
    if(zise < lowLimit || zise >hiLimit){retorno = -1;printf(eMessage);}
    else{retorno = 0;strcpy(input,auxStr);}
    return retorno;
}

///_____________tipo persona_________________________________

/** \brief  Inicializa el array tipo persona con el valor designado.
 *
 * \param arrayPersona[] Es el array de tipo persona que recive.
 * \param cantDePersona  Es el tamaño o (LONGITUD) del array.
 * \param valor Es el valor designado a todas las posiciones.
 * \return void.
 *
 */
void inicilizarArrrayPersonas(Persona arrayPersona[],int cantDeElementos,int valor)
{
    int i;
    for(i=0;i<cantDeElementos;i++)
    {arrayPersona[i].legajo = valor;}
}

/** \brief busca la primera ocurrencia de un valor designado en un array de Personas
 *
 * \param arrayPersona[] es el array de tipo persona donde se buscara la ocurrencia.
 * \param cantDeElementos es el tamaño o (LONGUITUD) del arrayPersona.
 * \param buscado Es el valor buscado en la variable arrayPersona[].leajo.
 * \return En caso de una busqueda exitosa retorna la posicion donde se encontro y en caso de no encontrar retorna EOF.
 *
 */
int  buscPrimerOcurrenciaPersonas(Persona arrayPersona[],int CantDeElementos,int buscado)
{
    int i,retorno = EOF;

    for (i=0;i < CantDeElementos ;i++)
    {
        if(arrayPersona[i].legajo == buscado){retorno = i;}
    }
    return retorno;
}


///_______________tipo Epersona_________________________________________________

/** \brief Inicializa un array tipo Epersona en el vaor pasado.
 *
 * \param array[] Es el array designado a sr inicializado.
 * \param cantDeElementos Es la cantidad o (Longitud) del array.
 * \param valor Es el valor a inicializar en cada posicion del array.
 * \return
 *
 */
void iniciaArrayEpersona(EPersona array[],int cantElementos,int valor)
{
    int i;
    for(i=0;i<cantElementos;i++){array[i].estado=valor;}
}
/** \brief Busca una la primera ocurrencia en un array de tipo Epersona.
 *
 * \param array[] Es el array donde se buscara la ocurrencia.
 * \param cantDeElementos Es el tamaño o (longitud) del array a analizar.
 * \param buscado Es el valor a ser buscado en los distintos elementos del array.
 * \return retorna la posicion del subindice donde se encontro el valor  y en caso de no encontrarlo EOF.
 */
int buscarPrimerOcurrenciaEpersona(EPersona array[],int cantDeElementos,int buscado)
{
    int i;
    int index= EOF;
    for(i=0;i<cantDeElementos;i++){if(array[i].estado == buscado)index= i;}

    return index;
}

/** \brief Ordena un array tipo Epersona segun orden y criterio pasado.
 *
 * \param lista[] Es el array designado para ordenar
 * \param cantDeElementos Es el tamaño o (longitud) del array a ordenar.
 * \param criterio Es criterio de ordenamiento elejir 1= por dni 2= por edad 3= por nombre.
 * \param tipoDeOrden Es la forma de orden a elejir 1= acendente 0= decendente.
 * \return void
 */
void ordenoPersonasPor(EPersona lista[],int cantDeElementos,int criterio, int tipoDeOrden)
{
    EPersona auxStruct;
    int i,j;

    if(tipoDeOrden == 1)//orden ACENDENTE.
    {
            switch(criterio)
        {
            case 1:///POR D.N.I
                for(i=0;i<cantDeElementos-1;i++)
                {
                    for(j=i+1;j<cantDeElementos;j++)
                    {
                        if(lista[i].dni > lista[j].dni)
                        {
                            auxStruct = lista[i];
                            lista[i]  = lista[j];
                            lista[j]  = auxStruct;
                        }
                    }
                }
                break;

            case 2:///POR EDAD
                for(i=0;i<cantDeElementos-1;i++)
                {
                    for(j=i+1;j<cantDeElementos;j++)
                    {
                        if(lista[i].edad > lista[j].edad)
                        {
                            auxStruct = lista[i];
                            lista[i]  = lista[j];
                            lista[j]  = auxStruct;
                        }
                    }
                }
                break;

            case 3:///POR NOMBRE
                for(i=0;i<cantDeElementos-1;i++)
                {
                    for(j=i+1;j<cantDeElementos-1;j++)
                    {
                        if(strcmp(lista[i].nombre,lista[j].nombre) <0)//si la compraracon da menor a cero el string derecho en el menor.
                        {
                            auxStruct = lista[i];
                            lista[i]  = lista[j];
                            lista[j]  = auxStruct;
                        }
                    }
                }
                break;
            default:
                errorMensaje("[ERROR]: criterio u tipo de ordenamiento erroneo.");
                break;
        }

    }
    else if(tipoDeOrden ==0)//orden DECENDENTE
    {
           switch(criterio)
        {
            case 1:///POR D.N.I
                for(i=0;i<cantDeElementos-1;i++)
                {
                    for(j=i+1;j<cantDeElementos;j++)
                    {
                        if(lista[i].dni > lista[j].dni)
                        {
                            auxStruct = lista[i];
                            lista[i]  = lista[j];
                            lista[j]  = auxStruct;
                        }
                    }
                }
                break;

            case 2:///POR EDAD
                for(i=0;i<cantDeElementos-1;i++)
                {
                    for(j=i+1;j<cantDeElementos;j++)
                    {
                        if(lista[i].edad > lista[j].edad)
                        {
                           auxStruct = lista[i];
                            lista[i]  = lista[j];
                            lista[j]  = auxStruct;

                        }
                    }
                }
                break;

            case 3://POR NOMBRE
                for(i=0;i<cantDeElementos-1;i++)
                {
                    for(j=i+1;j<cantDeElementos;j++)
                    {
                        if(strcmp(lista[i].nombre,lista[j].nombre) >0)//si la compraracon da menor a cero el string derecho en el menor.
                        {
                            auxStruct = lista[i];
                            lista[i]  = lista[j];
                            lista[j]  = auxStruct;
                        }
                    }
                }
                break;
            default:
                errorMensaje("[ERROR]: criterio u tipo de ordenamiento erroneo.");
                break;
        }
    }
}

/** \brief Imprime pos pantalla el contenido de la estructura tipo Epersona.
 *
 * \param lista Es la estrctura que se designa para ser  impresa en pantalla.
 * \param mensaje Es un mensaje de apoyo para la impresion de la estructura. ej:"\n"
 * \return (void).
 */
void mostrarPersona(EPersona lista,char mensaje[],char message2[])
{
  printf("Nombre:%s %sEdad:%d %sD.N.I:%d%s",lista.nombre,mensaje,lista.edad,mensaje,lista.dni,message2);
}

/** \brief Imprime por pantalla el contenido del array de tipo Epersona.
 *
 * \param  listas Es el array de tipo Epersona designado apara imprimir en pantalla.
 * \param  length Es el tamaño o (longitud )del array.
 * \param  mensaje Es un mensaje de apoyo a la impresion de las estructuras que
 *         componen el array EJ:"\n".
 * \return(void)
 */
void mostrarPersonas(EPersona listas[],int length,char message[],char message2[])
{
    int i;
    for(i=0;i<length;i++)
    {
        if(listas[i].estado ==0){mostrarPersona(listas[i],message,message2);}
    }
}

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible,en caso de no encontrarlo devuelde EOF.
 */
int obtenerEspacioLibre(EPersona lista[],int tamArray)
{
    int i;

    for (i= 0;i< tamArray;i++)
        {if(lista[i].estado == EOF)return i; }
    return EOF;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista Es array se pasa como parametro.
 * @param dni Es el D.N.I a buscar en el array.
 * @param tamArray Es el tmaño o (longitud) del array.
 * @return El indice donde lo enconto,en caso de no tener exito devuelve EOF.
 */
int buscarPorDni(EPersona lista[],int tamArray,int dni)
{
    int i,index= EOF;

    for(i= 0;i< tamArray;i++){if(lista[i].dni == dni) {index= i;break;}}
    return index;
}


/** \brief Registra los rangos que se encuentran en el array de personas.
 *
 * \param array Es el array de Persona asignado para analizar.
 * \param length Es el tamaño o(longitud del array)
 * \param rank1 Es puntero al rango1 designado.
 * \param rank2 Es puntero al rango2 designado.
 * \param rank3 Es puntero al rango 3 designado.
 * \return (void);
 *
 */
void scanRangesEpersonas(EPersona array[],int length,int* rank1,int* rank2,int* rank3)//FUNCIONA OK.
{
    int i,cont1=0,cont2=0,cont3=0;
    for(i=0;i<length;i++)
    {
        if(array[i].estado==0)
        {
            if(array[i].edad<=18){cont1++;}
            if(array[i].edad>=19 && array[i].edad<=35){cont2++;}
            else if(array[i].edad>35){cont3++;}
        }
    }
    *rank1= cont1;
    *rank2= cont2;
    *rank3= cont3;
}

///__________TIEMPO______________

/** \brief Detiene la ejecucion del programa por un tiempo determinado.
 *
 * \param mSecond Es tiempo expresado milisegundos que se dentendra la ejecucion.
 * \return (void);
 */
 void goSleep(int mSecond)
{
    #ifdef __unix__
    usleep(msecond*1000);
    #else
    Sleep(mSecond);
    #endif // __unix__
}
