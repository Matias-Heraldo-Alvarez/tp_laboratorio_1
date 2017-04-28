#ifndef OUPUTINPUTTP2_H_INCLUDED
#define OUPUTINPUTTP2_H_INCLUDED

#include <stdio.h>
#include <ctype.h>
#include "UTN.h"
#include"Epersona.h"

int deleteAperson(EPersona[],int,int);
int incomeOfPersons(EPersona[],int,int*,int*,char*);

void showPanel();
void showGrapicBars(EPersona[],int);
void graficosDeBarras(int,int,int);
void listOfPeople(EPersona[],int);

int getDni(char[]);
int getEdad(char[],int,int);
int GetTheName(char[],char[]);
int validLimitsInt(int,int,int);

#endif // OUPUTINPUTTP2_H_INCLUDED
