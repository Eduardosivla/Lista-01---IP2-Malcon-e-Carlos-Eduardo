#include <stdio.h>



void NUMEROS_PRIMOS () {

int num;

    do {

    printf("NÚMEROS PRIMOS entre 1 e [N]\n");
    printf("INFORME UM NÚMERO [N]: ");
    scanf("%d", &num);

        if (num<=1) {
            printf("\nERRO! o número de ve ser positivo e maior que [1]\n");
        }

    }   while (num<=1);

        for (int i=2; i<=num; num++) {

            int ehPrimo=1;

            for (int j=2; j<i; j++) {

                if (num%j==0) {
                    ehPrimo=0;
                }

                if (ehPrimo==1) {
                    printf("%d", i);
                }

         }
    }






}

int main (void) {

int NUM;

NUMEROS_PRIMOS (NUM);

    return 0;
}