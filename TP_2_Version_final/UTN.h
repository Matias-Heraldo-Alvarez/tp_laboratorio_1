#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

#include <time.h>
#include <string.h>
#include<windows.h>
#include <limits.h>


#define  FACTORIAL_ERROR system("cls");printf("\n\tERROR ingrese solo numeros (ENTEROS POSITIVOS)\n\n\t");system("pause");

#define  DIVISION_ERROR system("cls");printf("\n\n\n\t\tERROR:(NO ES POSIBLE LA DIVISION ENTRE CERO(0).\n\n\n\t\t");system("pause");
#define  RESULTADOS system("cls"); printf("Resultado= %d\n",resultado);system("pause");
#define  DIVISION_RESULTADO system("cls");printf("Resultado= %.2f\n",DivResultado);system("pause");
#define  FACTORIAL_RESULTADOS system("cls");printf("Resultado= %ld\n",FactorialResult);system("pause");





typedef struct
{
    int legajo;
    char nombre[50];
    char Apellido[50];
}Persona;


typedef struct {
    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;


int  getFactorial(int);
float  sum(float,float);
float  subtraction(float,float);
float division(float,float);
float multiply(float,float);


int getInt(char[]);
int soloNumeros(char[]);
int soloLetras(char[]);
int soloAlfanumericos(char[]);
int esTelefono(char[]);
char getCharacter(char[]);
float getFloat(char[]);


int getStringNumeros(char[],char[]);
int getStringLetras(char[],char[]);
void getString(char[],char[]);


int validaFacorialTable(float);
int validaFacorial(float);
int validoOpcion(int,int);
void basicOperation(float,float);
void chargeSecuenceArrayInt(int[],int,char[],char[]);
float validoOperando(float);

int MaxoMinArrayInt(int vec[],int tam,int maxMin);
int buscarPrimeraOcurrencia(int[],int,int);
void inicializaArray(int[],int,int);
void ordenoArrayInt(int[],int,int);
void printArrayInt(int[],int,int,char[]);


int getInts(int*,char[],char[], int, int);
int getFloats(float*,char[],char[],float,float);
int getChars(char*,char[],char[],char,char);
int getStrings(char*,char[],char[],int,int);

void inicilizarArrrayPersonas (Persona[],int,int);
int  buscPrimerOcurrenciaPersonas(Persona[],int,int);

int buscarPorDni(EPersona[],int,int);
int obtenerEspacioLibre(EPersona[],int);


void goSleep(int);
void iniciaArrayEpersona(EPersona[],int,int);
int buscarPrimerOcurrenciaEpersona(EPersona[],int,int);
void ordenoPersonasPor(EPersona[],int,int,int);
void scanRangesEpersonas(EPersona[],int,int*,int*,int*);

void mostrarPersona(EPersona,char[],char[]);
void mostrarPersonas(EPersona[],int,char[],char[]);
void errorMensaje(char[]);
void warningMessage(char[]);
void SuccessMessage(char[],int);
void clearScreen();

#endif // UTN_H_INCLUDED
