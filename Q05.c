#include <stdio.h>

void matrizElementos (int linhas, int colunas, int matriz[][colunas]) {
    
    for (int i=0; i<linhas; i++) {
        for (int j=0; j<colunas; j++) {

            printf("Elementos [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            printf("\n");

        }
    }
}

void quadradoPerfeito (int linhas, int colunas, int matriz[][colunas]) {

int somaLinhas[linhas], somaColunas[colunas];
int sDprinci=0, sDSecun=0;

int igual=1;

    for (int i=0; i<colunas; i++) { //loop para zerar as posições das colunas(vetor), evitando lixo de memória
        somaColunas [i] = 0;
    }


    for (int i=0; i<linhas; i++) {

        somaLinhas[i]=0; //zerar as posições das linhas(vetor), evitando lixo de memória

        for (int j=0; j<colunas; j++) {

            if (i==j) {
                sDprinci += matriz[i][j];
            }
            
            if (i+j==colunas-1) {
                sDSecun += matriz[i][j];
            }

            somaLinhas[i] += matriz[i][j];
            somaColunas[j] += matriz[i][j];

        }
    }

    for (int i=1; i<linhas; i++) {

        if (somaLinhas[i] != somaLinhas[0] || somaColunas[i] != somaColunas[0]){
            igual=0;
            break;
        }
    }
        if (igual==1) {
            printf("É um quadrado mágico\n");

                printf("Matriz: \n");
                printf("--------\n");

                for (int i=0; i<linhas;i++) {
                    for (int j=0; j<colunas; j++) {
                        printf("[%d] ", matriz[i][j]);
                    }
                        printf("\n");
                }
                        printf("\n");
        }

        else {
            printf("Não é um quadrado mágico\n");
                printf("Matriz: \n");
                printf("--------\n");

                for (int i=0; i<linhas;i++) {
                    for (int j=0; j<colunas; j++) {
                        printf("[%d] ", matriz[i][j]);
                    }
                        printf("\n");
                }
                        printf("\n");
            }
        }


int main (void) {

int linhas, colunas;

do {

        printf("Informe Número de Linhas: ");
        scanf("%d", &linhas);
        printf("--------------\n");


        printf("Informe o número de Colunas: ");
        scanf("%d", &colunas);
        printf("\n");

        if (linhas != colunas) {
            printf("[ERRO! O número de Linhas e Colunas devem ser iguais!]");
            printf("\n--------------\n");
        }

    } while (linhas!= colunas);

int matriz[linhas][colunas];

matrizElementos(linhas, colunas, matriz);
quadradoPerfeito (linhas, colunas, matriz);



    return 0;
}




//carlos eduardo