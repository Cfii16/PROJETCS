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

