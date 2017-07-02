#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "T_P3.h"


///headers__________________________--
void showMenuMvs(FILE*,FILE*,EMovie*,EMovie*);

int main()//OK.
{
    FILE* FMov= NULL;///Archivo de peliculas del programa.
    FILE* FHtml= NULL;///Archivo de generacion de la cartelera HTML.
    EMovie* MLst= NULL;

    EMovie* AMLst= NULL; ///puntero usado como auxiliar de MovieLst para la funcion realloc.
    MLst= (EMovie*)malloc(sizeof(EMovie));

    int Cont= 0;//contador de peliculas.
    int Size= 1;//tamaño del array.

    char bajaNameMovie[50];//variables de baja

    char NameMod [50],GeneroMod[30],DescriptionMod[200],LinkImageMod[200];
    int ClasificationMod,HoursMovieMod;//Variables para modificacion de datos.

    char auxHtml[400];//Variables de generacion de archivo HTML.
    int contChar;

    int i,flag,opcion= 0,opmod= 0;//variables operacionales.
    char Seguir= 's';
    system("color f0");

    FMov= fopen("Movies.bin","rb");//OK.
    if(FMov==NULL){errorMssgeAndTime("ERROR:\n No se puede abrir el archivo",1500);}

    while(fread((MLst+Cont),sizeof(EMovie),1,FMov)== 1)//OK.
    {
        Cont++;Size++;

        AMLst= (EMovie*)realloc(MLst,Size*sizeof(EMovie));//OK.
        if(AMLst==NULL){errorMssgeAndTime("ERROR;\nNo pueden leerce los datos guardados",1500);}
    }

    flag= fclose(FMov);//OK
    if(flag== -1){errorMssgeAndTime("ERROR:\nNo se puede cerrar el archivo.",1500);}

    printf("Datos Cargados");goSleep(1500);

    while(Seguir=='s')
    {
        clearScreen();
        system("color f0");
        fflush(stdin);
        printf(PANEL);
        scanf("%d",&opcion);
        flag= validLimitsInt(opcion,0,6);if(flag== -1){errorMssgeAndTime("Opcion invalida",1000);}

        switch(opcion)
        {
            case 1:
                clearScreen();
                fflush(stdin);
                printf("Ingreso de pelicula\n");
                flag= GetDataToMovie(MLst,Cont);//OK
                if(flag== -1){errorMssgeAndTime("ERROR de carga",1000);break;}
                else{Cont++;}

                Size++;//OK
                AMLst= (EMovie*)realloc(MLst,Size*sizeof(EMovie));
                if(AMLst== NULL){errorMssgeAndTime("ERROR de realloc",1000);break;}
                else{MLst=AMLst;}
            break;

            case 2:
                clearScreen();
                fflush(stdin);//OK.
                flag= GetAlphaName("Baja de una pelicula\n\n Igrese el titulo:",bajaNameMovie,45);
                if(flag== -1){break;}

                for(i= 0;i< Cont;i++ )
                {
                    if(MLst[i].status== 0)
                    {
                        if(stricmp(MLst[i].titulo,bajaNameMovie)== 0){MLst[i].status= -1;SuccessMessage("Baja exitosa",1500);i= Cont;}

                    }
                }
            break;
            case 3:
                strcpy(auxHtml,HTML_HEADER);
                contChar= strlen(auxHtml);

                FHtml= fopen("billboard.html","w");
                if(FHtml==NULL){errorMssgeAndTime("ERROR:\nNo puede abrirce el archivo",1500);break;}

                flag= fwrite(auxHtml,sizeof(char),contChar,FHtml);
                if(flag< contChar){errorMssgeAndTime("Error de escritura del ARchivo",1500);break;}

                for(i= 0;i< Cont;i++ )
                {
                    if(MLst[i].status!= 0){continue;}

                    fprintf(FHtml,"<div class='row'     <article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='%s' alt='Error en carga de imagen'>",MLst[i].linkImagen);
                    fprintf(FHtml,"<\a>");fprintf(FHtml,"<h3>");

                    fprintf(FHtml,"<a href='#'>");
                    contChar= strlen(MLst[i].titulo);
                    fwrite(MLst[i].titulo,sizeof(char),contChar,FHtml);

                    fprintf(FHtml,"</a></h3><ul><li>Genero: ");
                    contChar= strlen(MLst[i].genero);
                    fwrite(MLst[i].genero,sizeof(char),contChar,FHtml);

                    fprintf(FHtml,"<li>Puntaje: %d",MLst[i].puntaje);
                    fprintf(FHtml,"<li>Duracion: %d",MLst[i].duracion);

                    fprintf(FHtml," min</li></ul><p> ");
                    contChar= strlen(MLst[i].descripcion);
                    fwrite(MLst[i].descripcion,sizeof(char),contChar,FHtml);
                    fprintf(FHtml,"</p></article></div>");
                }

                strcpy(auxHtml,HTML_FOOTER);
                contChar= strlen(auxHtml);

                flag= fwrite(auxHtml,sizeof(char),contChar,FHtml);
                if(flag< contChar){errorMssgeAndTime("Error de esscritura",1500);break;}

                flag= fclose(FHtml);
                if(flag== -1){errorMssgeAndTime("ERROR:\nNopuede cerrarce el archivo HTML",1500);break;}
                else{SuccessMessage("ARCHIVO HTML\n\nGENERADO EXITOSAMENTE!",1500);}
            break;

            case 4://OK
                clearScreen();
                flag= GetAlphaName("Modificacion de pelicula\n\n Igrese el titulo:",bajaNameMovie,45);
                if(flag== -1){break;}

                for(i= 0;i< Cont;i++)
                {
                    if(MLst[i].status== 0)
                    {
                        if(stricmp(MLst[i].titulo,bajaNameMovie)== 0)
                        {
                            clearScreen();
                            PANEL_MOD;
                            fflush(stdin);
                            scanf("%d",&opmod);
                            flag= validLimitsInt(opmod,0,6);if(flag== -1){errorMssgeAndTime("Opcion invalida",1000);}

                            switch(opmod)
                            {
                                case 1:
                                clearScreen();fflush(stdin);

                                flag= GetAlphaName("Ingrese titulo :\n ",NameMod,45);///Pido el nombre de la pilicula.
                                if(flag== -1){break;}///En caso de no conseguirlo retorna al menu de opciones.

                                flag= GetTheName("Genero de la pelicula:\n",GeneroMod);///pido el genero de la pelicula.
                                if(flag== -1){break;}///En caso de no conseguirlo retorna el menu de opciones.

                                fflush(stdin);printf("Horas de duracion: ");///Pido duracion de la pelicula.
                                scanf("%d",&HoursMovieMod);
                                flag= validLimitsInt(HoursMovieMod,0,11);
                                if(flag!= 0){errorMssgeAndTime("Fuera de rando",1000);break;}

                                fflush(stdin);printf("Ingrese el puntaje: ");///Pido el puntaje de la pelicula en valor entero.
                                scanf("%d",&ClasificationMod);flag=validLimitsInt(ClasificationMod,0,11);
                                if(flag!= 0){errorMssgeAndTime("Fuera de rando",1000);break;}

                                strcpy(MLst[i].titulo,NameMod);strcpy(MLst[i].genero,GeneroMod);
                                MLst[i].duracion= HoursMovieMod; MLst[i].puntaje= ClasificationMod;
                                break;

                                case 2:
                                clearScreen();

                                flag= getAlpha(DescriptionMod,"Ingrese una breve descripcion de la pelicula [maximo 195 caracteres]:\n","ERROR: MAximo de caracteres alcanzado.","ERROR: tipo de datos incompatibles [solo alfanumericos]",195,2);
                                if(flag== -1){break;} ///En caso de ingraso  falldo retorna al mrnu de opciones.

                                strcpy(MLst[i].descripcion,DescriptionMod);
                                break;

                                case 3:
                                clearScreen();

                                getString("Ingrese link de imagen: ",LinkImageMod);///Tomo el link de la imagen.
                                flag= strlen(LinkImageMod);///mido el tamaño de la cadena para evitar overflow.
                                if(flag>200){errorMssgeAndTime("Link demaciado largo para ser aceptado.",1200);break;}///retorno -1 y aviso del arror.

                                strcpy(MLst[i].linkImagen,LinkImageMod);
                                break;

                                case 4:
                                clearScreen();

                                flag= GetAlphaName("Ingrese titulo :\n ",NameMod,45);///Pido el nombre de la pilicula.
                                if(flag== -1){break;}///En caso de no conseguirlo retorna al menu de opciones.

                                flag= GetTheName("Genero de la pelicula:\n",GeneroMod);///pido el genero de la pelicula.
                                if(flag== -1){break;}///En caso de no conseguirlo retorna el menu de opciones.

                                fflush(stdin);printf("Horas de duracion: ");///Pido duracion de la pelicula.
                                scanf("%d",&HoursMovieMod);
                                flag= validLimitsInt(HoursMovieMod,0,11);
                                if(flag!= 0){errorMssgeAndTime("Fuera de rando",1000);break;}

                                fflush(stdin);printf("Ingrese el puntaje: ");///Pido el puntaje de la pelicula en valor entero.
                                scanf("%d",&ClasificationMod);flag=validLimitsInt(ClasificationMod,0,11);
                                if(flag!= 0){errorMssgeAndTime("Fuera de rando",1000);break;}

                                flag= getAlpha(DescriptionMod,"Ingrese una breve descripcion de la pelicula [maximo 195 caracteres]:\n","ERROR: MAximo de caracteres alcanzado.","ERROR: tipo de datos incompatibles [solo alfanumericos]",195,2);
                                if(flag== -1){break;} ///En caso de ingraso  falldo retorna al mrnu de opciones.

                                getString("Ingrese link de imagen: ",LinkImageMod);///Tomo el link de la imagen.
                                flag= strlen(LinkImageMod);///mido el tamaño de la cadena para evitar overflow.
                                if(flag>200){errorMssgeAndTime("Link demaciado largo para ser aceptado.",1200);break;}///retorno -1 y aviso del arror.

                                strcpy(MLst[i].titulo,NameMod);strcpy(MLst[i].genero,GeneroMod);
                                MLst[i].duracion= HoursMovieMod; MLst[i].puntaje= ClasificationMod;

                                strcpy(MLst[i].descripcion,DescriptionMod);
                                strcpy(MLst[i].linkImagen,LinkImageMod);
                                break;
                            }

                            i=Cont;
                            SuccessMessage("Modificacion completada!",1500);
                        }
                    }
                }
            break;
            case 5:
                clearScreen();//OK.
                FMov= fopen("Movies.bin","wb");
                if(FMov==NULL){errorMssgeAndTime("ERROR:\n No se puede abrir el archivo",1500);exit(1);}

                for(i= 0;i< Cont ;i++ )//OK
                {
                    if(MLst[i].status!=0 ){continue;}
                    flag= fwrite((MLst+i),sizeof(EMovie),1,FMov);
                    if(flag< 1){errorMssgeAndTime("ERROR:\n\nNo pueden guardarce los datos",1500);exit(1);}
                }

                flag= fclose(FMov);//OK
                if(flag== -1){errorMssgeAndTime("ERROR:\nNo se puede cerrar el archivo.",1500);exit(1);}
                else{SuccessMessage("Datos Guardados\n\n HASTA LA PROXIMA.",1500);}
                Seguir= 'n';
            break;

            case 6:
                clearScreen();
                for(i= 0;i< Cont;i++ )//OK.
                {
                    if(MLst[i].status== 0)
                    {
                        printf("NOMBRE:%s  GENERO:%s\n\nDESCRIPCION:%s\n\nDURACION:%d\nCLASIFICACION:%d\nlink:%s\n\n\n",MLst[i].titulo,MLst[i].genero,MLst[i].descripcion,MLst[i].duracion,MLst[i].puntaje,MLst[i].linkImagen);

                    }
                }
                system("pause");
            break;
        }
    }
    return 0;
}
///desarrooyo  de funciones d uso general____________________.

int Fl_loadMovie(char* path,EMovie* Mlst)
{
    int ok= -1;

    int cont= 1;
    FILE* arch= NULL;
    EMovie* auxMlst=NULL;


    arch= fopen(path,"rb");if(arch== NULL){errorMssgeAndTime("Error de apertura File",1500);return ok;}

    while(fread((Mlst+cont),sizeof(EMovie),1,arch)==1)
    {
        auxMlst=(EMovie)realloc(Mlst,cont*sizeof(EMovie));


    }

    return ok;
}
