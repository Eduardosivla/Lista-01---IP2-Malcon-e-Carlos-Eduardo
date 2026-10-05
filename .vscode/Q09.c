#include <stdio.h>

#define MAX 100

void rotacionarMatriz(int matriz[MAX][MAX], int *linhas, int *colunas)
{
    int matriz_temp[MAX][MAX];
    int i, j;
    int n = *linhas;
    int m = *colunas;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            matriz_temp[j][n - 1 - i] = matriz[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) {
            matriz[i][j] = matriz_temp[i][j];
        }
    }

    *linhas = m;
    *colunas = n;
}

int main()
{
    int matriz[MAX][MAX];
    int n, m;
    int i, j;

    printf("Digite o numero de linhas (N) e colunas (M): ");
    scanf("%d %d", &n, &m);

    printf("Digite os elementos da matriz %dx%d:\n", n, m);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf(" Matriz Original \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%3d ", matriz[i][j]);
        }

        printf("\n");
    }

    rotacionarMatriz(matriz, &n, &m);

    printf("Matriz Resultante em 90 Graus\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++)
        {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
