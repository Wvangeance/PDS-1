#include <stdio.h>

void imprime(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void multiplica(int vetor[], int n, double v) {
    for (int i = 0; i < n; i++) {
        vetor[i] *= v;
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    printf("Digite os valores do vetor:\n");
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }

    double valor;
    printf("Digite o valor para multiplicar o vetor: ");
    scanf("%lf", &valor);

    printf("Valores do vetor antes da multiplicação:\n");
    imprime(vetor, tamanho);

    multiplica(vetor, tamanho, valor);

    printf("Valores do vetor após a multiplicação:\n");
    imprime(vetor, tamanho);

    double inverso = 1 / valor;
    multiplica(vetor, tamanho, inverso);

    printf("Valores do vetor após a segunda multiplicação:\n");
    imprime(vetor, tamanho);

    return 0;
}