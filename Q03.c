#include <stdio.h>

int tamInvalido (int tam) {
    do {
        printf("Informe o tamanho do Vetor: ");
        scanf("%d", &tam);
        printf("\n");
        
        if (tam<=0) {
            printf("Tamanho de Inválido! Informe novamente (TAM > 0)\n");
            printf("--------------------\n");
        }
    } while (tam<=0);

    return tam;
}
void preecherVetor(int vetor[], int tam) {

    int repetido=0;

    for (int i=0; i<tam; i++) {
        printf("Valor [%d]: ", i+1);
        scanf("%d", &vetor[i]);
    } 
        for (int i=0; i<tam; i++) {
            for (int j=0; j<tam; j++) {

                if(vetor[j]==vetor[j]){
                    repetido++;
                    printf("[%d] foi repetido %d vezes\n", i, repetido);
                    repetido=0;
                } 
            }
        }
}

int main (void) {

    int tam=0;
    tam = tamInvalido (tam);
    int vetor[tam];

    preecherVetor(vetor, tam);

    return 0;
}