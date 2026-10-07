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

// ---------------------------------------------------------
// FUNÇÕES AUXILIARES DA INTELIGÊNCIA DO COMPUTADOR (MINIMAX)
// ---------------------------------------------------------

// Avalia o tabuleiro e retorna uma pontuação
int avaliarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) 
{
    for (int linha = 0; linha < TAMANHO; linha++) {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]) {
            if (tabuleiro[linha][0] == 'O') return +10;
            else if (tabuleiro[linha][0] == 'X') return -10;
        }
    }
    for (int coluna = 0; coluna < TAMANHO; coluna++) {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]) {
            if (tabuleiro[0][coluna] == 'O') return +10;
            else if (tabuleiro[0][coluna] == 'X') return -10;
        }
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        if (tabuleiro[0][0] == 'O') return +10;
        else if (tabuleiro[0][0] == 'X') return -10;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        if (tabuleiro[0][2] == 'O') return +10;
        else if (tabuleiro[0][2] == 'X') return -10;
    }
    return 0; 
}

// O algoritmo que prevê todas as jogadas (Recursivo)
int minimax(char tabuleiro[TAMANHO][TAMANHO], int profundidade, int isMax) 
{
    int score = avaliarTabuleiro(tabuleiro);

    if (score == 10) return score - profundidade;
    if (score == -10) return score + profundidade;
    if (verificarEmpate(tabuleiro)) return 0;

    if (isMax) {
        int melhor = -1000;
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                if (tabuleiro[i][j] == ' ') {
                    tabuleiro[i][j] = 'O'; 
                    int valor = minimax(tabuleiro, profundidade + 1, 0); 
                    tabuleiro[i][j] = ' '; 
                    if (valor > melhor) melhor = valor;
                }
            }
        }
        return melhor;
    } else {
        int melhor = 1000;
        for (int i = 0; i < TAMANHO; i++) {
            for (int j = 0; j < TAMANHO; j++) {
                if (tabuleiro[i][j] == ' ') {
                    tabuleiro[i][j] = 'X'; 
                    int valor = minimax(tabuleiro, profundidade + 1, 1); 
                    tabuleiro[i][j] = ' '; 
                    if (valor < melhor) melhor = valor;
                }
            }
        }
        return melhor;
    }
}

// Aciona a Inteligência para realizar a melhor jogada
void jogadaComputador(char tabuleiro[TAMANHO][TAMANHO]) 
{
    int melhorValor = -1000;
    int melhorLinha = -1;
    int melhorColuna = -1;

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ') {
                tabuleiro[i][j] = 'O'; 
                int valorJogada = minimax(tabuleiro, 0, 0); 
                tabuleiro[i][j] = ' '; 

                if (valorJogada > melhorValor) {
                    melhorLinha = i;
                    melhorColuna = j;
                    melhorValor = valorJogada;
                }
            }
        }
    }
    tabuleiro[melhorLinha][melhorColuna] = 'O';
    printf("O Computador (O) jogou na linha %d, coluna %d\n", melhorLinha, melhorColuna);
}

// ---------------------------------------------------------
// FUNÇÃO PRINCIPAL
// ---------------------------------------------------------

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
    printf("Voce e o Jogador X e jogara contra o Computador (O).\n");

    while (1)
    {
        desenharTabuleiro(tabuleiro);
        
        // Verifica de quem é a vez
        if(jogadorAtual == 'X')
        {
            fazerJogada(tabuleiro, jogadorAtual);
        }
        else
        {
            printf("Turno do computador aguarde...\n");
            jogadaComputador(tabuleiro);
        }

        // Verifica se a jogada resultou em vitória
        if (verificarVitoria(tabuleiro)) 
        {
            desenharTabuleiro(tabuleiro);
            if (jogadorAtual == 'X') {
                printf("Parabens! Voce venceu!\n"); // Dificilmente o computador vai deixar isso acontecer
            } else {
                printf("O Computador venceu! Boa sorte na proxima.\n");
            }
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
