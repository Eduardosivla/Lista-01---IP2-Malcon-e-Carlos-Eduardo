#include <stdio.h>

void matrizElementos (int dimen, int matriz[][dimen]) {
    
    for (int i=0; i<dimen; i++) {
        for (int j=0; j<dimen; j++) {

            printf("Elementos [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            printf("\n");

        }
    }
}

void tracoMatriz (int dimen, int matriz[][dimen]) {
    
    int traco=0;

    for (int i=0; i<dimen; i++) {
        for (int j=0; j<dimen; j++) {

        traco+=matriz[i][i];

        }  
    }
        printf("\nTraço da Matriz: %d\n", traco);
}

int determinante3x3 (int matriz[][3]) {
    int det;
    det = matriz[0][0] * matriz[1][1] * matriz[2][2] 
        + matriz[0][1] * matriz[1][2] * matriz[2][0]
        + matriz[0][2] * matriz[1][0] * matriz[2][1]
        - matriz[0][2] * matriz[1][1] * matriz[2][0]
        - matriz[0][0] * matriz[1][2] * matriz[2][1] 
        - matriz[0][0] * matriz[1][2] * matriz[2][1];

        return 0;
}

void matrizDeterminante (int dimen, int matriz[][dimen]) {

int somaDPrinci=1, somaDSecun=1, determ=0;

    if (dimen==1) {

    }
        if (dimen==2) { //determina uma matriz ondem 2x2
            printf("MATRIZ 2X2\n");
                    
        for (int i=0; i<dimen; i++) {
            for (int j=0; j<dimen; j++) {

                if (i==j) {
                    somaDPrinci*= matriz[i][j];
                }
                    if (i+j == dimen-1) {
                        somaDSecun*=matriz[i][j];
                    }
                }
            }
            determ += somaDPrinci - somaDSecun;
            printf("DETERMINANE: %d\n", determ);
        }

        if (dimen==3) {
            
            int matAux[dimen-1][dimen-1];


            for (int i=0; i<dimen; i++) {
                for (int j=0; j<dimen-1; j++) {

                    matAux[i][j] = matriz[i][j];


                }
            }
        }
    }


int main (void) {

int linhas, colunas, dimen=0;

do {

        printf("Informe Número de Linhas");
        scanf("%d", &linhas);
        
        printf("\n--------------\n");


        printf("Informe o número de Colunas");
        scanf("%d", &colunas);
        printf("\n");

        if (linhas != colunas) {
            printf("[ERRO! O número de Linhas e Colunas devem ser iguais!]");
            printf("\n--------------\n");
        }
        if (linhas == colunas) {
            dimen+=linhas; //recebe o tamanho da matriz quadrada e deixa somente em uma variavel para facilitar na escrita do código
        }

    } while (linhas!= colunas);

int matriz[linhas][colunas];

matrizElementos (dimen, matriz);
matrizDeterminante (dimen, matriz);


    return 0;
}