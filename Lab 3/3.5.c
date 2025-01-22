#include <stdio.h>

int main() {
    int linhas, colunas, i, j, max;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    max = matriz[0][0]; // Inicializa max com o primeiro elemento da matriz

    // Encontra o maior elemento
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
    }

    printf("%d", max);

    return 0;
}
