#include <stdio.h>

// Mudei o nome da função para fazer mais sentido com o que ela faz
int obterTamanho (int tam) {
    do {
        printf("Informe o tamanho do Vetor: ");
        scanf("%d", &tam);
        printf("\n");
        
        if (tam <= 0) {
            printf("Tamanho Invalido! Informe novamente (TAM > 0)\n");
            printf("--------------------\n");
        }
    } while (tam <= 0);

    return tam;
}

// Juntei a leitura e a verificação na mesma função
void preencherEVerificarVetor(int vetor[], int tam) {

    // 1. Primeiro, temos de preencher o vetor com os valores do utilizador
    for(int i = 0; i < tam; i++) {
        printf("Informe o valor da posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    // 2. Agora sim, aplicamos a tua lógica para contar as repetições
    for(int i = 0; i < tam; i++) {
        int jaApareceu = 0;
        int rep = 0;

        // Verifica se o número atual já apareceu para trás
        for(int j = 0; j < i; j++) { 
            if(vetor[i] == vetor[j]) {
                jaApareceu = 1;
                break; // Se já apareceu, podemos parar este ciclo
            }
        }   

        // Se é a primeira vez que vemos este número, vamos contar
        if(jaApareceu == 0) {   
            for(int j = 0; j < tam; j++) {
                if(vetor[i] == vetor[j]) {
                    rep++;
                }
            }
            
            if(rep == 1) {
                printf("O numero %d apareceu %d vez\n", vetor[i], rep);
            } else if (rep > 1) {
                printf("O numero %d apareceu %d vezes\n", vetor[i], rep);
            }
        }
    } 
}

int main (void) {
    int tam = 0; 
    
    // Obtém o tamanho validado
    tam = obterTamanho(tam);
    
    // Declara o vetor com o tamanho escolhido
    int vetor[tam];

    // Chama a função para preencher e analisar
    preencherEVerificarVetor(vetor, tam);

    return 0;
}
