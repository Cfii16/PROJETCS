Jogo do Galo em C

Descrição:

Este é um programa em C que implementa o clássico jogo da velha (Tic-Tac-Toe) para dois jogadores: um humano (jogando como 'O') e o computador (jogando como 'X'). O jogo é jogado em um tabuleiro 3x3, onde o jogador humano escolhe posições para colocar seu 'O', e o computador responde colocando um 'X' na primeira posição vazia disponível. O programa verifica automaticamente se há um vencedor após cada jogada.

Funcionalidades:

Tabuleiro 3x3 representado por uma matriz de caracteres.
O jogador humano ('O') escolhe a linha e coluna para sua jogada.
O computador ('X') joga automaticamente na primeira posição livre.
Verificação de vitória para ambos os jogadores (linhas, colunas e diagonais).
Tratamento básico de erros:
Impede jogadas em posições ocupadas.
Valida entradas fora do intervalo (0-2).
Exibição do tabuleiro após cada jogada.

Requisitos:

Um compilador C (ex.: GCC).
Um ambiente com entrada/saída de terminal (ex.: Linux, Windows).

Como Compilar:

Salve o código em um arquivo chamado tictactoe.c.
Abra o terminal na pasta onde o arquivo está salvo.
Compile o programa com o comando:

gcc tictactoe.c -o tictactoe

Isso gera um executável chamado tictactoe (ou tictactoe.exe no Windows).

Como Executar:

Após compilar, execute o programa com:

./tictactoe(No Windows, use tictactoe.exe).

Siga as instruções no terminal:
Digite a linha (0-2) e pressione Enter.
Digite a coluna (0-2) e pressione Enter.
O computador jogará automaticamente após sua jogada.

Código:

Aqui está o código completo para referência:

#include <stdio.h>

char tabuleiro[3][3];

void LimparTabuleiro() {
    int linha, coluna;
    for (linha = 0; linha < 3; linha++)
        for (coluna = 0; coluna < 3; coluna++)
            tabuleiro[linha][coluna] = ' ';
}

void MostrarTabuleiro() {
    int linha;
    for (linha = 0; linha < 3; linha++) {
        printf(" %c | %c | %c\n", tabuleiro[linha][0], tabuleiro[linha][1], tabuleiro[linha][2]);
        if (linha < 2) {
            printf("---+---+---\n");
        }
    }
}

int PerguntarALinhaDoProximoPeao() {
    int linha = 0;
    printf("Qual a linha (0-2): ");
    scanf("%d", &linha);
    return linha;
}

int PerguntarAColunaDoProximoPeao() {
    int coluna = 0;
    printf("Qual a coluna (0-2): ");
    scanf("%d", &coluna);
    return coluna;
}

void PorPeaoNoTabuleiro(char peao, int linha, int coluna) {
    if (tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = peao;
    } else {
        printf("Essa posicao esta ocupada! Tente outra vez.\n");
    }
}

int VerificarSeJogadaVencedora(char peao) {
    int linha, coluna;
    for (linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][0] == peao && tabuleiro[linha][1] == peao && tabuleiro[linha][2] == peao) {
            return 1;
        }
    }
    for (coluna = 0; coluna < 3; coluna++) {
        if (tabuleiro[0][coluna] == peao && tabuleiro[1][coluna] == peao && tabuleiro[2][coluna] == peao) {
            return 1;
        }
    }
    if ((tabuleiro[0][0] == peao && tabuleiro[1][1] == peao && tabuleiro[2][2] == peao) ||
        (tabuleiro[0][2] == peao && tabuleiro[1][1] == peao && tabuleiro[2][0] == peao)) {
        return 1;
    }
    return 0;
}

void JogadaComputador() {
    int linha, coluna;
    for (linha = 0; linha < 3; linha++) {
        for (coluna = 0; coluna < 3; coluna++) {
            if (tabuleiro[linha][coluna] == ' ') {
                tabuleiro[linha][coluna] = 'X';
                printf("Bot jogou na linha %d e coluna %d\n", linha, coluna);
                return;
            }
        }
    }
}

int main() {
    LimparTabuleiro();
    int linha, coluna, ganhou;

    while (1) {
        MostrarTabuleiro();
        printf("Jogador O:\n");
        
        linha = PerguntarALinhaDoProximoPeao();
        
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("Essa jogada nao existe! Tente novamente.\n");
            continue;
        }
        
        coluna = PerguntarAColunaDoProximoPeao();

        if (tabuleiro[linha][coluna] != ' ') {
            printf("Essa posicao esta ocupada! Tente novamente.\n");
            continue;
        }

        PorPeaoNoTabuleiro('O', linha, coluna);
        MostrarTabuleiro();
        
        ganhou = VerificarSeJogadaVencedora('O');
        if (ganhou == 1) {
            MostrarTabuleiro();
            printf("Jogador O ganhou!!!!\n");
            break;
        }
        
        JogadaComputador();
        
        ganhou = VerificarSeJogadaVencedora('X');
        if (ganhou == 1) {
            MostrarTabuleiro();
            printf("Jogador X ganhou!!!!\n");
            break;
        }
    }

    return 0;
}


Licença:

Este é um projeto de código aberto. Sinta-se à vontade para usá-lo, modificá-lo e distribuí-lo como desejar!
