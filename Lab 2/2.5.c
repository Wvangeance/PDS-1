#include <stdio.h>

int main() {
    int num, soma = 0;

   scanf("%d", &num);

    for(int i = 1; i <= num; i++) {
        soma += i;
    }

    printf("%d\n", soma);

    return 0;
}