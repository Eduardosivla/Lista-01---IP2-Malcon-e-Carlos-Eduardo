#include <stdio.h>

void NUMEROS_PRIMOS (int num) {
    
    for (int i=2; i<=num; i++) {
        int ehPrimo=1;

        for (int j=2; j<i; j++) {

            if (i%j==0) {
                ehPrimo=0;
            }

            if (ehPrimo==1) {
                printf("[%d], ", i);
                break;
            }

         }
    }
    printf("\n\n");
}

int main (void) {

int NUM;

    do {

    printf("NÚMEROS PRIMOS entre 1 e [N]\n");
    printf("INFORME UM NÚMERO [N]: ");
    scanf("%d", &NUM);

        if (NUM<=1) {

            printf("\nERRO! o número deve ser positivo e maior que [1]\n");

        }

    }   while (NUM<=1);



NUMEROS_PRIMOS(NUM);

    return 0;
}