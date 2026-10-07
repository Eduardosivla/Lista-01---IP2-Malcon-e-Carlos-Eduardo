#include <stdio.h>
#define TAM 7

int main()
{
    int matriz[TAM][TAM];
    int matriz_normalizada[TAM][TAM];
    int f_min, f_max;
    int i, j;

    printf("Digite os valores para a matriz %dx%d:\n", TAM, TAM);
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    f_min = matriz[0][0];
    f_max = matriz[0][0];

    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            if (matriz[i][j] > f_max)
            {
                f_max = matriz[i][j];
            }

            if (matriz[i][j] < f_min)
            {
                f_min = matriz[i][j];
            }
        }
    }

    for (i = 0; i < TAM; i++) 
    {
        for (j = 0; j < TAM; j++)
        {

            if (f_max == f_min) 
            {
                matriz_normalizada[i][j] = 0; 
            }
            
            else
            {
                float g = (255.0 / (f_max - f_min)) * (matriz[i][j] - f_min);
                matriz_normalizada[i][j] = (int)g; 
            }
        }
    }

    printf("\nMatriz Normalizada:\n");
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            printf("%3d ", matriz_normalizada[i][j]);
        }

        printf("\n");
    }

    return 0;
}
