#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_MAXIMO 100

int main() {
    int numJogos;
    scanf("%d", &numJogos);

    for (int jogo = 0; jogo < numJogos; jogo++) {
        int tamanho;
        scanf("%d", &tamanho);

        // Alocar memória para o tabuleiro
        char tabuleiro[TAMANHO_MAXIMO][TAMANHO_MAXIMO];
        bool revelado[TAMANHO_MAXIMO][TAMANHO_MAXIMO];

        // Inicializa a matriz de revelado
        memset(revelado, false, sizeof(revelado));

        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                scanf(" %c", &tabuleiro[i][j]);
            }
        }

        int numMovimentos;
        scanf("%d", &numMovimentos);

        // Ler movimentos
        int movimentos[TAMANHO_MAXIMO][2];
        for (int i = 0; i < numMovimentos; i++) {
            scanf("%d %d", &movimentos[i][0], &movimentos[i][1]);
        }

        int totalNaoMinas = 0, celulasReveladas = 0;

        // Contar células que não contêm bombas
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (tabuleiro[i][j] == 'x') {
                    totalNaoMinas++;
                }
            }
        }

        int direcoes[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, 
                               { 0, -1},         { 0, 1}, 
                               { 1, -1}, { 1, 0}, { 1, 1} };

        bool perdeu = false;
        for (int i = 0; i < numMovimentos; i++) {
            int linha = movimentos[i][0];
            int coluna = movimentos[i][1];
            if (tabuleiro[linha][coluna] == 'b') {
                perdeu = true;
                break;
            }

            if (linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho && !revelado[linha][coluna]) {
                revelado[linha][coluna] = true;

                bool temMinas = false;
                for (int k = 0; k < 8; k++) {
                    int novaLinha = linha + direcoes[k][0];
                    int novaColuna = coluna + direcoes[k][1];
                    if (novaLinha >= 0 && novaLinha < tamanho && novaColuna >= 0 && novaColuna < tamanho && tabuleiro[novaLinha][novaColuna] == 'b') {
                        temMinas = true;
                        break;
                    }
                }

                if (!temMinas) {
                    for (int k = 0; k < 8; k++) {
                        int novaLinha = linha + direcoes[k][0];
                        int novaColuna = coluna + direcoes[k][1];
                        if (novaLinha >= 0 && novaLinha < tamanho && novaColuna >= 0 && novaColuna < tamanho && !revelado[novaLinha][novaColuna]) {
                            revelado[novaLinha][novaColuna] = true;
                        }
                    }
                }
            }
        }

        if (perdeu) {
            printf("PERDEU\n");
            continue;
        }

        // Contar quantas células foram reveladas
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (revelado[i][j] && tabuleiro[i][j] == 'x') {
                    celulasReveladas++;
                }
            }
        }

        if (celulasReveladas == totalNaoMinas) {
            printf("GANHOU\n");
        } else {
            printf("FALTOU TERMINAR\n");
        }
    }

    return 0;
}


