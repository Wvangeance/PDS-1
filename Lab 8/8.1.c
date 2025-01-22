#include <stdio.h>
#include <math.h>

void media(double vet[], int n, int *i) {
    double soma = 0;
    double media = 0;
    double diff = INFINITY;

    // Calcula a soma de todos os elementos do vetor
    for (int j = 0; j < n; j++) {
        soma += vet[j];
    }

    // Calcula a média dos elementos do vetor
    media = soma / n;

    // Encontra o elemento mais próximo da média
    for (int j = 0; j < n; j++) {
        double current_diff = fabs(vet[j] - media);
        if (current_diff < diff) {
            diff = current_diff;
            *i = j;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    double vet[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vet[i]);
    }

    int i;
    media(vet, n, &i);

    printf("%d\n", i);

    return 0;
}