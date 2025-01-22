#include <stdio.h>

// Função que verifica se um ano é bissexto
int ehBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
        return 1; // Ano bissexto
    } else {
        return 0; // Não é ano bissexto
    }
}

int main() {
    int ano;
    while (scanf("%d", &ano) != EOF) {
        printf("%d\n", ehBissexto(ano));
    }
    return 0;
}
