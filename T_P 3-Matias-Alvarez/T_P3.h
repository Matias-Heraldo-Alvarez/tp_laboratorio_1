#include <stdio.h>
#include <stdlib.h>
#include"UTN.h"

///Define===============================.
#define PANEL "[1]- AGREGAR UNA PELICULA \n\n[2]- BORRAR UNA PELICULA\n\n[3]-GENERAR PAGAGINA WEB\n\n[4]-MODIFICAR UNA PELICULA\n\n[5]-Guardar y salir de sistema\n\n\n:"
#define PANEL_MOD printf("Modificar una  pelicua\n\n[1]Titulo,Genero,Duracion,puntaje\n[2]Descripcion breve\n[3]Link de imagen promocional\n\n[4]Todos los campos.\n\n:");

#define HTML_HEADER "!DOCTYPE html><html lang='en'><head>    >meta charset='utf-8'>  >meta http--equiv='X-UA-Compatible' cotntent='IE=edge'>    >meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='styleheet'><link href ='css/custom.css' rel='stylesheet'></head><body><div clas=' container'>"

#define LINK "<div class='row'     <article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='%s' alt='Error en carga de imagen'>"

#define HTML_FOOTER "    </div>  <!-- /.container --> <!-- Jquery --><script src='Js/Jquery-1.11.3min.js'></script><!-- Boostrap core javascript --><script></script><!- IE10 viewport bug workaround --><script src='Js/ie10-viewport-bug-workaround.Js'></script><1-- Placeholder Images --><cript src='Js/holder.min.Js'></script></body></html>"
///Structures--------------------------.

typedef struct{
    char titulo[50];
    char genero[30];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];

    int status;
}EMovie;


///prototype____________________________.

int GetDataToMovie(EMovie*,int);
