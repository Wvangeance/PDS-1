#include <stdio.h>
#include <math.h>

// Função que verifica se um número é primo
int is_prime(int num) {
    if (num < 2) {
        return -1; // Números menores que 2 não são considerados
    }
    if (num == 2) {
        return 1; // 2 é primo
    }
    if (num % 2 == 0) {
        return 0; // Números pares maiores que 2 não são primos
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0; // Encontrou um divisor, não é primo
        }
    }
    return 1; // É primo
}

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        int result = is_prime(num);
        printf("%d\n", result);
    }
    return 0;
}

