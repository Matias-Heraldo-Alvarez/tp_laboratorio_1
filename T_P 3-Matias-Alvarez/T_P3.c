#include <stdio.h>
#include <stdlib.h>
#include "T_P3.h"


/** \brief Toma los datos para cagar una pelicula y los guarda en el punaro a struct pasado.
 *
 * \param Mlst Array dinamico.
 * \param index Es el indice o posicion del array.
 * \return retorna 0 si tuvo exito ,sino -1.
 *
 */
int  GetDataToMovie(EMovie* Mlst,int index)//FUNCIONA OK.
{
    int  ok= -1;
    int flagDate= -1;//variables de operacion.

    char AlphaNameMovie [200],Genero[30],Description[200],LinkImage[200];
    int Clasification,HoursMovie;//Variables para toma de datos.

        flagDate= GetAlphaName("Ingrese nomre de pelicula:\n ",AlphaNameMovie,45);///pido el nombre de la pilicula.
        if(flagDate== -1)return ok;///en caso de no conseguirlo retorna al menu de opciones.

        flagDate= GetTheName("Genero de la pelicula:\n",Genero);///pido el genero de la pelicula.
        if(flagDate== -1)return ok;///En caso de no conseguirlo retorna el menu de opciones.

        fflush(stdin);printf("Horas de duracion de pelicula:");///Pido duracion de la pelicula.
        scanf("%d",&HoursMovie);
        flagDate= validLimitsInt(HoursMovie,0,11);
        if(flagDate!= 0){errorMssgeAndTime("Fuera de rando",1000);return ok;}

        flagDate= getAlpha(Description,"Ingrese una breve descripcion de la pelicula [maximo 195 caracteres]:\n","ERROR: MAximo de caracteres alcanzado.","ERROR: tipo de datos incompatibles [solo alfanumericos]",195,2);
        if(flagDate== -1)return ok; ///En caso de ingraso  falldo retorna al mrnu de opciones.

        fflush(stdin);printf("Ingrese el puntaje de la pelicula:");///Pido el puntaje de la pelicula en valor entero.
        scanf("%d",&Clasification);flagDate=validLimitsInt(Clasification,0,11);
        if(flagDate!= 0){errorMssgeAndTime("Fuera de rando",1000);return ok;}

        getString("Ingrese link de imagen promocional: ",LinkImage);///Tomo el link de la imagen.
        flagDate= strlen(LinkImage);///mido el tamaño de la cadena para evitar overflow.
        if(flagDate>200){errorMssgeAndTime("La diraccion es demacioado larga para ser aceptada.",1200);return ok;}///retorno -1 y aviso del arror.
        SuccessMessage("DATOS TOMADOS:",120);///en caso de tomas los datos correctamente  aviso del evento exitoso.
        //_____________________________________________________________________________________________________________________________________________________________________________________________________
        Mlst[index].status= 0;///paso los datos nuevos a la estructura contenida en el array dinamico de eMovie.
        Mlst[index].duracion= HoursMovie; Mlst[index].puntaje= Clasification;

        strcpy(Mlst[index].descripcion,Description); strcpy(Mlst[index].titulo,AlphaNameMovie);
        strcpy(Mlst[index].genero,Genero); strcpy(Mlst[index].linkImagen,LinkImage);
        printf("DATOS Nuevos:\n\n\n");goSleep(1000);

        printf("NOMBRE:%s  GENERO:%s\n\nDESCRIPCION:%s\n\nDURACION:%d\nCLASIFICACION:%d\nlink:%s",Mlst[index].titulo,Mlst[index].genero,Mlst[index].descripcion,Mlst[index].duracion,Mlst[index].puntaje,Mlst[index].linkImagen);
        goSleep(3000);

        if(Mlst[index].status== 0){ok= 0;}

    return ok;
}



