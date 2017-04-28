#include"ouputInputTP2.h"


/** \brief Solicita el numero de D.N.I que funciona como di de las estructura Epersona
 *         analiza el ingreso en busqueda de errores y luego lo busca en un array de
 *         estructuras Epersona para producir una baja logica.
 *
 * \param arraylist Es el array tipo Epersona asignado para la opracion.
 * \param length Es el tamaño o (longitud) del array asignado.
 * \return 0 en caso de una baja logica exitosa de lo contrario EOF (-1).
 *
 */
int deleteAperson(EPersona arrayList[],int length,int datosCargados)
{
    int stop= 0;
    int flag= EOF,chargedDate= EOF;

    int auxDni;

    while(stop== 0)
    {
        clearScreen();
        printf("_BAJAS DE PERSONAS________________________________\n\n\n");
        if(datosCargados == EOF){warningMessage("\n\nDATOS INEXIXTENTES\n-Se requiere el ingreso previo de datos\n\n\nDIRIJASE !ALTAS!");break;}

        auxDni= getDni("-Ingrese Documento Nacional de Identidad-D.N.I:");
        if(auxDni==EOF)break;
        else
        {
            flag= unsubscribePersonas(arrayList,length,auxDni);
            if(flag==EOF)break;
            else{chargedDate= 1;stop= 1;}
        }
    }
    return chargedDate;
}

/** \brief Solicita los datos de una persona,evalua posibles errores de ingreso y
           los guarda en posicion disponible de un array de personas.
 *
 * \param arrayList Es el array de tipo Epersona donde se guardan los datos vinculantes.
 * \param length Es el tamaño o (longitud)del array designado.
 * \param pDni Es un puntero a la direccion de memoria de la variable auxdni.
 * \param pEdad Es un puntero a la direccion de memoria de la variable auxEdad.
 * \param pAuxName Es un puntero a la direccion de memoria de la variable pAuxName.
 * \return 0 en caso de una carga exitosa de lo contrario EOF (-1).
 *
 */
int incomeOfPersons(EPersona arrayList[],int length,int *pDni,int *pEdad,char *pAuxName)
{
    int stop= 0;
    int chargeComplited= EOF;
    int flag=EOF;

    int indice= EOF;
    int auxEdad;
    int auxDni;
    char auxName[50];

    while(stop==0)
    {
        clearScreen();
        system("color F1");
        printf("-ALTAS DE PERSONAS___________________.\n\n\n");
        indice= findFPlacePersonas(arrayList,length,"LISTADO LLENO IMPOSIBLE AGRAGAR MAS PERSONAS");
        if(indice==EOF){chargeComplited= 0;break;}

        auxDni =getDni("-Ingrese el documento nacional de identidad D.N.I: ");
                if(auxDni==EOF){chargeComplited= EOF;break;}


                flag= buscarPorDni(arrayList,length,auxDni);
                if(flag!=EOF){warningMessage("[ALERTA]:EL D.N.I YA EXIXTE!");arrayList[flag].estado=0,chargeComplited=0,SuccessMessage("DATOS REABILITADOS EXITOSAMENSTE!",1000);break;}

        flag= GetTheName("-Ingrese el nombre: ",auxName);
                if(flag== EOF){chargeComplited =0;break;}

        auxEdad= getEdad("-Ingrese la edad de la persona: ",1,100);
                if(auxEdad==EOF){break;}
                else{SuccessMessage("CARGA EXITOSA!",1000);chargeComplited=0;}

                swapPersonas(auxName,arrayList,auxEdad,auxDni,indice);break;

    }

    return chargeComplited;
}

/** \brief Muestra por pantalla una lista de datos de las estructuras que componen el array de
 *         Epersona que se le fue asignado en orden alfabetico.
 *
 * \param arraylist Es el array de tipo Epersona  designado para la operacion.
 * \param length Es el tamaño o(Longitud) del arrray designado.
 * \return (void).
 *
 */
void listOfPeople(EPersona arraylist[],int length)
{
    clearScreen();
    printf("________LISTADO DE PERSONAS______________.\n\n\n");
    ordenoPersonasPor(arraylist,length,3,0);
    mostrarPersonas(arraylist,length,"--","\n");
    printf("\n\n\n\n__________________________________________(ordenado por noombre)\n\n");
    system("pause");

}

/** \brief Muestra el panel de opciones disponibles en el TP nro:2.
 *
 * \return (void)
 *
 */
void showPanel()
{
        clearScreen();
        system("color F1");

        printf("___TRABAJO___PRACTICO__NRO_(2___(laboratorio[1])\n\n\n");
        printf("1- Agregar persona\n\n");
        printf("2- Borrar persona\n\n");
        printf("3- Imprimir lista ordenada por  nombre\n\n");
        printf("4- Imprimir grafico de edades\n\n\n");
        printf("5- Salir :");
}

/** \brief Muestra por pantalla ungrafico de barras de 3 rangos
 *
 * \param personas Es el array de estructuras a ser analizado
 * \param length   Es el tamaño o (longitud) del array.
 * \return (void).
 *
 */
void showGrapicBars(EPersona personas[],int length)//FUNCIONA OK.
{
    //Variables para rango
    int menor18=0,de19A35=0,mayor35=0;
    //punteros para escaneo de rango.
    int* Pmeor18 = &menor18;
    int* Pde19A35= &de19A35;
    int* Pmayor35= &mayor35;
    scanRangesEpersonas(personas,length,Pmeor18,Pde19A35,Pmayor35);
    graficosDeBarras(menor18,de19A35,mayor35);
}


/** \brief imprime un grafico estadistico de barras en pantallla
 *         el mismo esta asociado a las estadisticas de edades de un arrayde tipo Epersona.
 * \param rango1 primer valor entre 0 y 18(inclusive).
 * \param rango2 segundo valor entre 19 y 35(inclusive)
 * \param rango3 tercer valor por encima de  35.
 * \return (void)
 *
 */
void graficosDeBarras(int rango1,int rango2,int rango3)//FUNCIONANANDO OK.
{
    int i;
    int longitud;
    char crango1=' ',crango2=' ',crango3=' ',ch='*';           //carga los rangos por defecto.

    if(rango1> rango2 && rango1> rango3)longitud= rango1;     //comparacion para el calculo de el mayor  rango.
    else if(rango2> rango1 && rango2> rango3)longitud= rango2;
    else if(rango3> rango2 && rango3> rango1)longitud= rango3;

        printf("GRAFICO_DE__EDADES\n");
        printf("------------------\n");
    for(i=longitud;i>0;i--)
    {
      if(rango1>=i){crango1=ch;}       //si el rango es mayor o igual al tamaño del grafico asigno '*'
      if(rango2>=i){crango2=ch;}
      if(rango3>=i){crango3=ch;}

        printf("| %c || %c || %c |\n",crango1,crango2,crango3); //imprimo los valores de los rangos.
    }
        printf("|<18 ||19-35||>35|\n");
        printf("|________________|\n");
        system("pause");
}


/** \brief Imprime por pantalla un grafico de barras verificado de rangos provenientes de un
 *         Array de tipo Epersona .
 * \param  bar1 Es el valor corrspondiente al primer rango.
 * \param  bar2 Es el valor correspondiente al segundo rango.
 * \param  bar3 Es el valor correspondiente al tercer rango.
 * \return (void)
 *
 */
void printGraficBars(int bar1,int bar2,int bar3)//FUNCIONA OK.
{
    int i,j,y,tamDeArray;
    int bars[]={bar1,bar2,bar3};

    if(bar1>=bar2&&bar1>=bar3)tamDeArray=bar1;
    else if(bar2>=bar1&&bar2>=bar3)tamDeArray=bar2;
    else if(bar3>=bar2&&bar3>=bar1)tamDeArray=bar3;

    char grapicBras[tamDeArray][3];

        printf("_GRAFICO_DE_EDADES_\n");
        printf("------------------\n");

    for(i=0;i<tamDeArray;i++)
    {
        for(j=0;j<3;j++)
        {
            if(bars[j]==tamDeArray){grapicBras[i][j]='*';}
            else{grapicBras[i][j]=' ';}
        }
    }
    for(y=tamDeArray -1;y==0;y--)
    {

        printf(" |%c  || %c || %c |\n",grapicBras[j][0],grapicBras[j][1],grapicBras[j][2]);


    }
         printf("|<18 ||19-35||>35|\n");
        printf("%c---------------%c\n",212,217);
        system("pause");
}

/** \brief Verifica que el valor entero asignado se encuentre entre los parametros dispuestos.
 *
 * \param number Es el valor a ser verificado.
 * \param min Es el valor minimo permitido.
 * \param max Es el valor maximo permitido.
 * \return en caso de estar entre los valores permitidos retorna 0, en caso de estar fuera de estoas retorna EOF.
 *
 */
int validLimitsInt(int number,int min,int max)//FUNCIONA OK.
{
    int rtn= EOF;
    if(number>min&&number<max)rtn=number;
    return rtn;
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
