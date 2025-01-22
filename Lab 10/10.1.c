#include <stdio.h>
#include <stdlib.h>

void lerElementos(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}

int main() {
    int tamanho;
    scanf("%d", &tamanho);

    int *vetor = (int *) malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    lerElementos(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetor[i]);
    }

    free(vetor);

    return 0;
}