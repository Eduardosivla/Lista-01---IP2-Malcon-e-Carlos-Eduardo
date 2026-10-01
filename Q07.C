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

void matTrans (int dimen, int matriz[][dimen], int matTrans[][dimen]) {
    
    for (int i=0; i<dimen; i++) {
        for (int j=0; j<dimen; j++) {

            matTrans[j][i] = matriz[i][j];
            
        }
    }


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

int matriz[linhas][colunas];









    return 0;
}