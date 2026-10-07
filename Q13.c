#include <stdio.h>

#define LINHAS 7
#define COLUNAS 7
#define TAM_HISTOGRAMA 256

void preencherMatriz(int matriz[LINHAS][COLUNAS])
{
    printf("Preencha a matriz %dx%d com valores de intensidade (0 a 255):\n", LINHAS, COLUNAS);
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            do
            {
                printf("Valor para a posicao [%d][%d]: ", i, j);
                scanf("%d", &matriz[i][j]);
                
                if (matriz[i][j] < 0 || matriz[i][j] > 255)
                {
                    printf("Erro: O valor deve estar entre 0 e 255. Tente novamente.\n");
                }
            } 
            while (matriz[i][j] < 0 || matriz[i][j] > 255);
          
        }
    }
}

void calcularHistograma(int matriz[LINHAS][COLUNAS], int histograma[TAM_HISTOGRAMA])
{
    for (int i = 0; i < TAM_HISTOGRAMA; i++)
    {
        histograma[i] = 0;
    }

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            int valor_intensidade = matriz[i][j];
            histograma[valor_intensidade]++; 
        }
    }
}

void exibirHistograma(int histograma[TAM_HISTOGRAMA])
{
    printf("\n Histograma Calculado \n");
    printf("Intensidade | Frequencia\n");
    
    for (int i = 0; i < TAM_HISTOGRAMA; i++)
    {
        if (histograma[i] > 0)
        {
            printf("   %3d     |   %2d\n", i, histograma[i]);
        }
    }
}

int main()
{
    int imagem[LINHAS][COLUNAS];
    int histograma[TAM_HISTOGRAMA];

    preencherMatriz(imagem);

    calcularHistograma(imagem, histograma);

    exibirHistograma(histograma);

    return 0;
}
