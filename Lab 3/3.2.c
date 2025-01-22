#include <stdio.h>

int main() {
    long long fibonacci[801];  // Usamos long long para lidar com números grandes
    int n;

    // Inicialização dos primeiros termos da série de Fibonacci
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Pré-cálculo da série de Fibonacci até o 800º termo
    for (int i = 2; i <= 800; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    while (1) {
        // Leitura da entrada do usuário
        scanf("%d", &n);

        // Verifica se a entrada é válida
        if (n < 0 || n > 800) {
            break;
        }

        // Impressão do termo correspondente da série de Fibonacci
        printf("%lld\n", fibonacci[n]);
    }

    return 0;
}
