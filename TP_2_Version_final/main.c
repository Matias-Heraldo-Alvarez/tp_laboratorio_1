#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "ouputInputTP2.h"
#include "Epersona.h"
//DEFINICIONES________________________
#define QTY_PEOPLE 20

int existenciaDeDatos(int datos,EPersona[],int);

int main()
{
    ///variables varias___________
    int flag,opcion = EOF,datoasCargados= EOF;
    char seguir='s';
    ///array_____________________
    EPersona personas[QTY_PEOPLE];
    /// auxiliares de array______
    char auxNombre[60];
    int auxDni,auxEdad;
    ///punteros auxiliares
    int*pDni=     &auxDni;
    int*pEdad=    &auxEdad;
    char*pNombre= auxNombre;

    iniciaArrayEpersona(personas,QTY_PEOPLE,EOF);//inicializacion de array.
    while(seguir=='s')
    {
        showPanel();
        opcion= validoOpcion(1,5);
        switch(opcion)
        {
            case 1://ALTAS FUNACIONA .OK
                flag= incomeOfPersons(personas,QTY_PEOPLE,pDni,pEdad,pNombre);
                if(flag==EOF)break;
                else datoasCargados=1;
                break;

            case 2://BAJAS FUNCIONA ok;
                flag= deleteAperson(personas,QTY_PEOPLE,datoasCargados);
                datoasCargados= existenciaDeDatos(datoasCargados,personas,QTY_PEOPLE);
                if(flag==EOF)break;

                break;

            case 3://LISTADO FUNCIONA OK.
                if(datoasCargados==EOF){warningMessage("\n\nDATOS INEXIXTENTES\n-Se requiere el ingreso previo de datos\n\n\nDIRIJASE !ALTAS!");break;}
                listOfPeople(personas,QTY_PEOPLE);
                break;

            case 4:
                if(datoasCargados==EOF){warningMessage("\n\nDATOS INEXIXTENTES\n-Se requiere el ingreso previo de datos\n\n\nDIRIJASE !ALTAS!");break;}

                showGrapicBars(personas,QTY_PEOPLE);
                break;

            case 5://SALIDA FUNCIONA OK.
                seguir = 'n';
                printf("\n\n\n\n-----------HASTA LA PROXIMA---------------");goSleep(1500);
                break;
        }
    }
    return 0;
}

int existenciaDeDatos(int datosCargados,EPersona array[],int length)
{
    int i;
    int hayDatos= EOF;

    for(i=0;i<length;i++)if(array[i].estado== 0)hayDatos= 0;

    return hayDatos;
}
