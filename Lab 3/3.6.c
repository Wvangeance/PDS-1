#include <stdio.h>

int main() {
    int n, m;
    printf("Digite o número de linhas (n): ");
    scanf("%d", &n);
    printf("Digite o número de colunas (m): ");
    scanf("%d", &m);

    int matriz[n][m];

    printf("Digite os elementos da matriz:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz oposta:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", -matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
