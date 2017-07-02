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
 * \return -1 en caso no ser solo alfanumericos 0 encaso de que si.
 *
 */
int soloAlfanumericos(char str[])
{
    int i = 0;
    int result = 0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ')&& (str[i]< 'a' || str[i]> 'z')&&(str[i]< 'A' || str[i]> 'Z')&&(str[i]< '0'|| str[i]> '9')){result = -1;}
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


/** \brief Toma una dato referente a una edad,lo verifica y lo retorna.
 *
 * \param message Es el mensaje que presenta al usuario para pedir el dato.
 * \return si toma el dato exitosamente retorna este , en caso de error retorna EOF.
 *
 */
int getEdad(char message[],int min,int max)//FUNCIONA OK.
{
    int  auxEdad=EOF,flag;
    char auxEdadStr[256];

    flag= getStringNumeros(message,auxEdadStr);
    if(flag==EOF){errorMensaje("\n\n\n[ERROR]:La edad debe componerso solo por numeros!");return auxEdad;}
    flag= atoi(auxEdadStr);
    auxEdad= validLimitsInt(flag,min,max);
    if(auxEdad==EOF){errorMensaje("[ERROR]:Edad fuera del rango");goSleep(1500);return auxEdad;}

    return auxEdad;
}

/** \brief Toma un dato referente a un D.N.I(documento nacional de identidad) y lo retorna.
 *
 * \param message Es el mensaje que presenta al usuario para pedir el dato.
 * \return si toma el dato exitosamente retorna este , en caso de error retorna EOF.
 *
 */
int getDni(char menssage[])//FUNCIONA OK.
{
    int flag;
    int auxDni,dni= EOF;
    char AuxDniStr[256];

        flag= getStringNumeros(menssage,AuxDniStr);
        if(flag==EOF){errorMensaje("\n\n\n[ERROR]:D.N.I debe componerse solo por numeros!");return dni;}
        auxDni=atoi(AuxDniStr);
        flag= validLimitsInt(auxDni,1000000,90000000);
        if(flag==EOF){errorMensaje("[ERROR]:D.N.I INVALIDO!");return dni;}
        else{dni= auxDni;}

        return dni;
}

/** \brief Pide un nobre y lo retorna.
 *
 * \param message Es el mansaje a mostrar al usuario.
 * \param input Es es la cadena donde se almacena.
 * \return 0 en caso de tener exito de lo contrrio EOF.(-1)
 *
 */
int GetTheName(char message[],char input[])//FUNCIONA OK.
{
    int obtained= EOF,flag,i;
    char auxName[40],character;//califica para guardar el nombre mas largo del mundo con 36 letras en el.

    flag= getStringLetras(message,auxName);
    if(flag== EOF){errorMensaje("[ERROR]:El nombre debe componerse solo por letras!!!");obtained= EOF;}

    flag= strlen(auxName);
    if(flag> 39||flag<= 1){errorMensaje("[ERROR]:Nombre invalido.");obtained= EOF;}
    else{obtained= 0;}
    character=auxName[0];character= toupper(character);auxName[0]=character;
                                 // pregunta si el caracer es[32 ACCI"ESPACIO"] en caso del serlo lo modifica a mayuscula.
    for(i=0;i<flag;i++)
        {
            if(auxName[i]==' '){character=auxName[i+1];character= toupper(character);auxName[i+1]=character;}
        }

    strcpy(input,auxName);

    return obtained;
}

/** \brief Pide un Apelllido y lo retorna.
 *
 * \param message Es el mansaje a mostrar al usuario.
 * \param lastName Es es la cadena donde se almacena.
 * \return 0 en caso de tener exito de lo contrrio EOF.(-1)
 *
 */
int GetTheLastName(char message[],char lastName[])//FUNCIONA OK.
{
    int obtained= EOF,flag,i;
    char auxLName[40],character;//califica para guardar el nombre mas largo del mundo con 36 letras en el.

    flag= getStringLetras(message,auxLName);
    if(flag== EOF){errorMensaje("[ERROR]:El Apellido debe componerse solo por letras!!!");obtained= EOF;}

    flag= strlen(auxLName);
    if(flag> 39||flag<= 1){errorMensaje("[ERROR]:Apellido invalido.");obtained= EOF;}
    else{obtained= 0;}
    character=auxLName[0];character= toupper(character);auxLName[0]=character;
                                 // pregunta si el caracer es[32 ACCI"ESPACIO"] en caso del serlo lo modifica a mayuscula.
    for(i=0;i<flag;i++)
        {
            if(auxLName[i]==' '){character=auxLName[i+1];character= toupper(character);auxLName[i+1]=character;}
        }

    strcpy(lastName,auxLName);

    return obtained;
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
int validoOpcion(int option,int min,int max)
{
    int tomado= -1;///valor de confiracion usado para determinar el resultado de la operacion..
    int Valor;

    fflush(stdin);///limpio el flujo de entrada de daos estandard
    if(scanf("%d",&Valor)!= 1 ||(Valor < min||Valor > max)){option= EOF;printf("\t\tOPCION INVALIDA.");goSleep(600);return tomado;}

    option= tomado= 0;
    return tomado;
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

/** \brief Verifica que el valor entero asignado se encuentre entre los parametros dispuestos.
 *
 * \param number Es el valor a ser verificado.
 * \param min Es el valor minimo permitido.
 * \param max Es el valor maximo permitido.
 * \return en caso de estar entre los valores permitidos retorna 0, en caso de estar fuera de estoas retorna -1.
 *
 */
int validLimitsInt(int number,int min,int max)//FUNCIONA OK.
{
    int rtn= -1;
    if(number>min&&number<max)rtn=0;
    return rtn;
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


 void goSleep(int mSecond)
{
    #ifdef __unix__
    usleep(msecond*1000);
    #else
    Sleep(mSecond);
    #endif // __unix__
}



/** \brief Limpia la pantalla y muestra un mensje de error por un tiempo determinado
 *
 * \param message Es el mensaje a ser mostrado en pantalla.
 * \return (void)
 */
void errorMssgeAndTime(char message[],int t)
{
    clearScreen();
    system("color f4");
    printf(message);
    goSleep(t);
}

/** \brief Limpia la pantalla y muestra un mensje de error por un tiempo determinado
 *
 * \param message Es el mensaje a ser mostrado en pantalla.
 * \param t Es el tiempo dterminado que se muestra el mensaje.
 * \return (void)
 */
void warningMessageWtime(char message[],int t)
{
    clearScreen();
    system("color F6");
    puts(message);
    goSleep(t);
}


/** \brief Pide una cadena de  y lo devuelve.
 *
 * \param message es el mensaje a mostrar al usuario.
 * \param Pinput es el puntero a la cadena de caracteres (string) que devuelve.
 * \return retorna en caso de ser (SOLO ALFANUMERICOS) 0 y -1 en caso de que NO.
 *
 */
int getStringAlpha(char message[],char input[])
{
    char auxAlpha[4096];
    int complite = -1,flag;

    getString(message,auxAlpha);
     flag= soloAlfanumericos(auxAlpha);

    if(flag== 0)
    {strcpy(input,auxAlpha);complite =flag;}

    return complite;
}


/** \brief toma una cadena de texto y verifica tamaño maximo y que posea solo alfanumericos.
 *
 * \param Pdescription Es puntero a array de tipo char pasado;
 * \param ETamMessage Es el mansaje a ser mostrado en caso de exeso de de caracteres.
 * \param EDatMessage Es el mansaje s a ser mostrasdo en caso de  error de ingreso de datatos .
 * \return En caso de un nigreso exitoso 0, sino -1;
 *
 */
int getAlpha(char* Pdescription,char mesage[],char EtamMssage[],char EDatMeseagge[],int Maxleng,int MinLeng)
{
    int leng=0;
    int complited= -1;
   char auxString[4096];

   puts(mesage);
   fflush(stdin);
   scanf("%4095[^\n]",auxString);
   leng= strlen(Pdescription);///tomo el largo de la cadena a ingresar.
   //if(leng< MinLeng || leng> Maxleng){errorMssgeAndTime(EtamMssage,1500);return complited;}

   complited= soloAlfanumericos(auxString);///Pregunto si el texto el alfanumerico.
   if(complited== -1){return complited;errorMssgeAndTime(EDatMeseagge,500);}

   strcpy(Pdescription,auxString);                     ///Paso la cadena el stringpasado por puntero.
   complited= 0;

   return complited;
}

/** \brief Pide un Nombre alfanumerico y lo devuelve y lo retorna.
 *
 * \param message Es el mansaje a mostrar al usuario.
 * \param AlphaName Es es la cadena donde se almacena.
 * \return 0 en caso de tener exito de lo contrrio -1.
 *
 */
int GetAlphaName(char message[],char AlphaName[],int leng)//FUNCIONA OK.
{
    int obtained= -1,flag,i;
    char auxAlpaName[196],character; //califica para guardar el nombre de pelicula mas largo del mundo con 196  letras en el.


    flag= getStringAlpha(message,auxAlpaName);
    if(flag== -1){errorMssgeAndTime("[ERROR]:Igrese solo alfanumericos.",500);obtained= -1;}

    flag= strlen(auxAlpaName);
    if(flag> 196||flag<= 1){errorMssgeAndTime("Nombre invalido",500);obtained= -1;}
    else{obtained= 0;}

    character= auxAlpaName[0];character= toupper(character);auxAlpaName[0]=character;
                                 // pregunta si el caracer es[32 ACCI"ESPACIO"] en caso del serlo lo modifica a mayuscula.
    for(i=0;i<flag;i++)
        {
            if(auxAlpaName[i]==' '){character=auxAlpaName[i+1];character= toupper(character);auxAlpaName[i+1]=character;}
        }

    strcpy(AlphaName,auxAlpaName);

    return obtained;
}
