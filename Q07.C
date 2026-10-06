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

void zerarMat(int dimen, int matTrans[][dimen]) {

    for (int i=0; i<dimen;i++) {
        for (int j=0; j<dimen; j++) {

            matTrans[i][j] = 0;

        }
    }
}

void matTransP (int dimen, int matriz[][dimen], int matTrans[][dimen]) {
    

    printf("MATRIZ ORIGINAL: \n");

            for (int i=0; i<dimen; i++) {
                for (int j=0; j<dimen; j++) {

                    matTrans[j][i] = matriz[i][j];

                 printf("[%d] ", matriz[i][j]);
                }
                printf("\n");
            }
             

        printf("\n\nMATRIZ TRANSPOSTA: \n");

            for (int i=0; i<dimen; i++) {
                for (int j=0; j<dimen; j++) {

                    printf("[%d] ", matTrans[i][j]);
                }
                printf("\n");
            }
}


void multiplicarMat (int dimen,int matB[][dimen], int matA[][dimen], int resultado[][dimen]) {
    zerarMat(dimen, resultado);

    printf("\n");
    printf("MULTIPLICAÇÃO: \n\n");

    for (int i=0; i<dimen; i++) {
        for (int j=0; j<dimen; j++) {
            for (int k=0; k<dimen; k++) {

                resultado[i][j] += matA[i][k] * matB[k][j];
                
                    }
                    printf("[%d] ", resultado[i][j]);
                }


        printf("\n");
    }
    printf("\n");
}

int ehOrtogonal (int dimen, int resultado[][dimen]){
    
    int sinal=1;
        
        for (int i=0; i<dimen; i++) {
            for (int j=0; j<dimen; j++) {
                
                if (i==j) {
                    if (resultado[i][j] !=1) {
                        sinal=0;
                    } 
                }

                if (i!=j) {
                    if (resultado[i][j] !=0) {
                        sinal=0;
                    }
                }
            }
        }
        
        return sinal;

}



int main (void) {
    
int linhas, colunas, dimen=0;

do {

        printf("Informe Número de Linhas: ");
        scanf("%d", &linhas);
        
        printf("--------------\n");


        printf("Informe o número de Colunas: ");
        scanf("%d", &colunas);
        printf("\n");

        if (linhas != colunas) {
            printf("\n[ERRO! O número de Linhas e Colunas devem ser iguais!]\n\n\n");
        }
        if (linhas == colunas) {
            dimen+=linhas; //recebe o tamanho da matriz quadrada e deixa somente em uma variavel para facilitar na escrita do código
        }

    } while (linhas!= colunas);

int matriz[dimen][dimen], matTran[dimen][dimen];
int resultado[dimen][dimen];



    zerarMat (dimen, matriz);
    matrizElementos (dimen, matriz);
    matTransP (dimen, matriz, matTran);
    multiplicarMat(dimen, matTran, matriz, resultado);

        if (ehOrtogonal(dimen, resultado)) {
            printf("\nA matriz e ortogonal!\n");
        } else {
            printf("\nA matriz nao e ortogonal!\n");
        }





    return 0;
}
