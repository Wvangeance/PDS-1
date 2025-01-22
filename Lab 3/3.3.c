#include <stdio.h>

int main() {
    int X[10], Y[10];

    // Leitura do vetor X
    for (int i = 0; i < 10; i++) {
        scanf("%d", &X[i]);
    }

    // Geração do vetor Y em ordem inversa
    for (int i = 0; i < 10; i++) {
        Y[i] = X[9 - i];
    }

    // Impressão do vetor Y
    for (int i = 0; i < 10; i++) {
        printf("%d\n", Y[i]);
    }

    return 0;
}
