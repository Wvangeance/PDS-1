#include <stdio.h>

int main() {
    int n1, n2, n3, maior;

    printf("Primeiro número: ");
    scanf("%d", &n1);
  
    printf("Segundo número: ");
    scanf("%d", &n2);
  
    printf("Terceiro número: ");
    scanf("%d", &n3);

    maior = n1;
    if (n2 > maior) {
        maior = n2;
    }
    if (n3 > maior) {
        maior = n3;
    }

    printf("O maior número é: %d\n", maior);

    return 0;
}