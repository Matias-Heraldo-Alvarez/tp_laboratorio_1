#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


#define  ERROR printf("\n\n\n\t\tERROR:(debe  ingresar los operandos antes de calcular.)\n\n\n");system("pause");
#define  DIVISION_ERROR system("cls");printf("\n\n\n\t\tERROR:(NO ES POSIBLE LA DIVISION ENTRE CERO(0).\n\n\n\t\t");system("pause");
#define  RESULTADOS system("cls"); printf("Resultado= %d\n",resultado);system("pause");
#define  DIVISION_RESULTADO system("cls");printf("Resultado= %.2f\n",DivResultado);system("pause");
#define  FACTORIAL_RESULTADOS system("cls");printf("Resultado= %ld\n",FactorialResult);system("pause");

int  getFactorial(int);

float  sum(float,float);

float  subtraction(float,float);

float division(float,float);

float multiply(float,float);

//int basicOperation(int,int);

#endif // FUNCIONES_H_INCLUDED
