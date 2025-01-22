#include <stdio.h>
#include <math.h>

// Função que verifica se um número é primo
int Primo(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Função que calcula a soma dos primeiros N números primos
int Soma_Primos(int N) {
    int soma = 0;
    int count = 0;
    int num = 2;
    
    while (count < N) {
        if (Primo(num)) {
            soma += num;
            count++;
        }
        num++;
    }
    
    return soma;
}

int main() {
    int entrada;
    
    // Leitura das entradas até o final do arquivo (EOF)
    while (scanf("%d", &entrada) != EOF) {
        int resultado = Soma_Primos(entrada);
        printf("%d\n", resultado);
    }
    
    return 0;
}

