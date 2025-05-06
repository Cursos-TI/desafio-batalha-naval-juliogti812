#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO_TABULEIRO 10
// Valor representando água
#define AGUA 0
// Valor representando parte do navio
#define NAVIO 3
// Tamanho fixo dos navios
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0 (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio horizontalmente
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe horizontalmente e não sobrepõe outro navio
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        if (tabuleiro[linha][coluna + j] != AGUA) return 0;
    }
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][coluna + j] = NAVIO;
    }
    return 1;
}

// Função para posicionar um navio verticalmente
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe verticalmente e não sobrepõe outro navio
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) return 0;
    }
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1;
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Define coordenadas iniciais dos navios
    int linhaH = 2, colunaH = 4; // Navio horizontal
    int linhaV = 5, colunaV = 7; // Navio vertical

    // Posiciona os navios e verifica sucesso
    if (!posicionarNavioHorizontal(tabuleiro, linhaH, colunaH)) {
        printf("Erro ao posicionar navio horizontal!\n");
    }

    if (!posicionarNavioVertical(tabuleiro, linhaV, colunaV)) {
        printf("Erro ao posicionar navio vertical!\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
