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
    for (int i=0; i<tam; i++) {

        printf("Valor [%d]: ", i+1);
        scanf("%d", &vetor[i]);
        
    } 
}
void picosVetor (int vetor[], int tam) {

    int achouPico=0;
    printf("\n\nPOSICOES QUE POSSUEM PICOS: \n");
    for (int i=0; i<tam; i++) {

        if (i==0) {
            if (vetor[i]>vetor[i+1]) {
                printf("[%d]\n", i+1);
                achouPico++;
            }
        }

        else if(i==tam-1) {
            if(vetor[i]>vetor[i-1]){
                printf("[%d]\n", i+1);
                achouPico++;
            }
        }
         else{
                if (vetor[i]>vetor[i-1]&& vetor[i]>vetor[i+1]){
                printf("[%d]", i+1);

                achouPico++;
                }
            }
        }  
         if(achouPico==0) {
                printf("\nNÃO EXISTE PICOS!\n");
        }
        printf("\n\n");
}   


int main (void) {

    int tam=0;

    tam = tamInvalido(tam);

    int vetor[tam];
        
        preecherVetor (vetor, tam);
        picosVetor(vetor, tam);

        return 0;
}