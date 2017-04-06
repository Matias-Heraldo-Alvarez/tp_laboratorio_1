                                            //ok
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"
#include "varios.h"

int main()
{
    int opcion = 0,operando1Flag = 0,operando2Flag = 0,panelFlag = 0,resultado;//ok
    char seguir = 's';
    float DivResultado,num1,num2;
    long int FactorialResult;

    while(seguir == 's')//ok
    {
        system("cls");TITULO;TOLBAR;TITULO2;TOLBAR2;
        chargePanel(num1,num2,operando1Flag,operando2Flag);
        do//ok
        {
         opcion = validoOpcion();
         if(opcion != 0){panelFlag =1;}
        }while(panelFlag != 1);

        switch(opcion)
        {
            case 1://ok

                num1 = validoOperando(num1);
                if(num1!= num1+1){operando1Flag = 1;}
                break;
            case 2://ok
                num2 = validoOperando(num2);
                if(num2!= num2+1){operando2Flag = 1;}
                break;
            case 3://ok
                if(operando1Flag == 1 && operando2Flag == 1){resultado = sum(num1,num2);RESULTADOS}
                else{ERROR}
                break;
            case 4://ok
                if(operando1Flag == 1 && operando2Flag == 1){resultado = subtraction(num1,num2);RESULTADOS}
                else{ERROR}
                break;
            case 5://ok
                if(operando1Flag == 1 && operando2Flag == 1)
                {
                    DivResultado = division(num1,num2);
                    if(num2 == 0){DIVISION_ERROR}
                    else{DIVISION_RESULTADO}
                }
                else{ERROR}
                break;
            case 6://ok
                if(operando1Flag == 1 && operando2Flag == 1){resultado = multiply(num1,num2);RESULTADOS}
                else{ERROR}
                break;
            case 7://ok
                if(operando1Flag == 1)
                {
                    FactorialResult = validaFacorial(num1);
                    if(FactorialResult == num1){FactorialResult = getFactorial(num1);FACTORIAL_RESULTADOS}
                }
                else{ERROR}
                break;
          case 8://ok
                if(operando1Flag == 1 && operando2Flag == 1){basicOperation(num1,num2);}
                else
                {system("cls");ERROR}
                break;
            case 9://ok
                seguir = 'n';
            break;
        }
    }
    return 0;
}
