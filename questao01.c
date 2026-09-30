#include <stdio.h>
#define TAM 20

void vetorValores (int valorEntrada, int vetor[TAM]) {

    int cont=0;

    for (int i=0; i<TAM; i++) {
        cont++;
        vetor[i] = cont;

            if(cont==valorEntrada-1) {
                cont=0;
            }
        
        printf("{%d} ", vetor[i]);
    }
    }

int main (void) {

    int vetor[TAM];
    int valorEnt, cont=0, result;
    
    printf("Informe um valor de entrada: ");
    scanf("%d", &valorEnt);

    vetorValores (valorEnt, vetor);


    return 0;
}