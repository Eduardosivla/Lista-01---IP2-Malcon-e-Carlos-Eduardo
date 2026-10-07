#include <stdio.h>

#define TAMANHO 3

void desenharTabuleiro(char tabuleiro[TAMANHO][TAMANHO])
{
    printf("\n");
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++) 
        {
            printf(" %c ", tabuleiro[i][j]); 
            if (j < TAMANHO - 1) 
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < TAMANHO - 1) 
        {
            printf("---+---+---\n"); 
        }
    }
    printf("\n");
}

void fazerJogada(char tabuleiro[TAMANHO][TAMANHO], char jogador) 
{
    int linha, coluna;
    while (1) 
    { 
        printf("Sua vez, jogador %c. Digite a linha e a coluna (0-2): ", jogador);
        scanf("%d %d", &linha, &coluna);

        if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO) 
        {
            if (tabuleiro[linha][coluna] == ' ') 
            {
                tabuleiro[linha][coluna] = jogador; 
                break;
            } 
            else 
            {
                printf("Posicao ocupada, tente novamente.\n");
            }
        } 
        else 
        {
            printf("Entrada invalida! Escolha numeros entre 0 e 2.\n");
        }
    }
}

int verificarVitoria(char tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return 1; // Vitória em uma linha
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return 1; // Vitória em uma coluna
        }
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
    {
        return 1; // Vitória na diagonal principal
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
    {
        return 1; // Vitória na diagonal secundária
    }
    return 0; // Ninguém venceu ainda
}

int verificarEmpate(char tabuleiro[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            if (tabuleiro[i][j] == ' ')
            {
                return 0; // Ainda há espaços vazios
            }
        }
    }
    return 1; // Tabuleiro cheio (empate)
}

int main()
{
    char tabuleiro[TAMANHO][TAMANHO];
    char jogadorAtual = 'X'; 

    // Preenche o tabuleiro com espaços vazios
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }

    printf("Bem-vindo ao Jogo da Velha!\n");

    while (1)
    {
        desenharTabuleiro(tabuleiro);
        
        // Pede para o jogador atual fazer a sua jogada
        fazerJogada(tabuleiro, jogadorAtual);

        // Verifica se a jogada resultou em vitória
        if (verificarVitoria(tabuleiro)) 
        {
            desenharTabuleiro(tabuleiro);
            printf("Parabens! O Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        // Verifica se a jogada resultou em empate
        if (verificarEmpate(tabuleiro))
        {
            desenharTabuleiro(tabuleiro);
            printf("Deu velha! O jogo empatou.\n");
            break;
        }
        
        // Passa a vez para o outro jogador
        if(jogadorAtual == 'X')
        {
            jogadorAtual = 'O';
        }

        else
        {
            jogadorAtual = 'X';
        }
    }

    return 0;
}
