#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool ehPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int A, B;

    // Entrada dos valores de A e B
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    // Garantir que A seja menor que B
    if (A > B) {
        int temp = A;
        A = B;
        B = temp;
    }

    // Verificar e imprimir números primos no intervalo
    printf("Números primos no intervalo [%d, %d]:\n", A, B);
    for (int i = A; i <= B; i++) {
        if (ehPrimo(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
