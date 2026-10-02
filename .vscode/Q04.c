#include <stdio.h>

void identificaModa(int *moda, int *quantidadeMax)
{
    int i, j, tam;
    int rep, jaApareceu;
    int maiorRep = 0;

    *quantidadeMax = 0;

    printf("Qual o tamanho deste vetor? ");
    scanf("%d", &tam);

    int vetor[tam];

    for (i = 0; i < tam; i++)
    {
        printf("Valor [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < tam; i++)
    {
        jaApareceu = 0;

        for (j = 0; j < i; j++)
        {
            if (vetor[i] == vetor[j])
            {
                jaApareceu = 1;
                break;
            }
        }

        if (jaApareceu == 0)
        {
            rep = 0;

            for (j = 0; j < tam; j++)
            {
                if (vetor[i] == vetor[j])
                {
                    rep++;
                }
            }

            if (rep > maiorRep)
            {
                maiorRep = rep;
                *moda = vetor[i];
                *quantidadeMax = 1;
            }
            else if (rep == maiorRep)
            {
                (*quantidadeMax)++;
            }
        }
    }
}

void verificaModa(int quantidadeMax, int moda)
{
    if (quantidadeMax == 1)
    {
        printf("A moda e: %d\n", moda);
    }
    else
    {
        printf("Nao existe uma moda.\n");
    }
}

int main(void)
{
    int moda = 0, quantidadeMax = 0;

    identificaModa(&moda, &quantidadeMax);

    verificaModa(quantidadeMax, moda);

    return 0;
    
}
