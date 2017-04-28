#include"Epersona.h"


/** \brief carga todos los campos de una estructura tipo ePersona con datos pasados
 *
 * \param auxNombre Es el dato que corresponde al nombre.
 * \param personas Es el array que se cargara.
 * \param auxEdad  Es el dato que corresposnde a la edad.
 * \param auxdni Es el dato que corrsponde con un D.N.I.
 * \param indice Es la subindice o[posicion] en el array donde queremos cargar los datos.
 * \return (void).
 *
 */
void swapPersonas(char auxNombre[],EPersona personas[],int auxEdad,int auxDni,int indice)
{
    strcpy(personas[indice].nombre,auxNombre);
    personas[indice].edad =auxEdad;
    personas[indice].dni  =auxDni;
    personas[indice].estado=0;
}

/** \brief Produce la baja logica de una estructura en el array de tipo Epersona.
 *
 * \param Personas Es el array de tipo Epersona donde dara de baja la estructura.
 * \param length Es el tamaño o (longitud) del array.
 * \param search Es el dato
 * \return 0 en caso de baja exitosa de lo contrario EOF (-1).
 *
 */
int unsubscribePersonas(EPersona Personas[],int length,int search)
{
    int indice,datosCargados=EOF;

    indice= buscarPorDni(Personas,length,search);
    if(indice== EOF||Personas[indice].estado== EOF)errorMensaje("\t\t[ERROR]:D.N.I INEXISTENTE!!");
    else{Personas[indice].estado= EOF;SuccessMessage(" BAJA EXITOSA",1500);}


    /*indice= buscarPrimerOcurrenciaEpersona(Personas,length,0);
    if(indice==EOF)datosCargados= EOF;
    else*/ datosCargados=0;

    return datosCargados;
}

/** \brief Encuentra un lugar libre en un array de tipo Epersona y lo retorna.
 *
 * \param personas Es el array donde se genera la busqueda.
 * \param length Es el tamaño o (longitud) del array.
 * \param Emessage Es el mensaje que se le presenta al usuario en caso de no encontrar lugar libre.
 * \return en caso de encontrar un lugar libre retorna su subindice, de no encontrarlo retorna EOF.
 *
 */
int findFPlacePersonas(EPersona personas[],int length,char Emessage[])
{
    int flag,indice=EOF;
    flag= buscarPrimerOcurrenciaEpersona(personas,length,EOF);
    if(flag!=EOF)indice=flag;
    else errorMensaje(Emessage);

    return indice;
}

