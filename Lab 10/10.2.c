#include <stdio.h>

int main() {
    int linhas, colunas;

    // Lendo o número de linhas e colunas
    scanf("%d", &linhas);
    scanf("%d", &colunas);

    int matriz[linhas][colunas];

    // Lendo os valores da matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimindo a matriz
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d", matriz[i][j]);
            if (j < colunas - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

