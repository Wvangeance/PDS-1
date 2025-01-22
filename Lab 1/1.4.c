#include <stdio.h>

int main() {
    int valor, i;
    int cedulas[] = {100, 50, 20, 10, 5, 2, 1};
    int quantidade[7] = {0}; // Inicializa todas as quantidades como 0

    scanf("%d", &valor);

    for(i = 0; i < 7; i++) {
        quantidade[i] = valor / cedulas[i];
        valor %= cedulas[i];
        printf("%d: %d\n", cedulas[i], quantidade[i]);
    }

    return 0;
}
