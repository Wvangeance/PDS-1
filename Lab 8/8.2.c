#include <stdio.h>

void primos(int m, int *p1, int *p2) {
    int i, j;
    *p1 = 0;
    *p2 = 0;

    // Verifica o maior número primo menor que m
    for (i = m - 1; i > 1; i--) {
        int isPrime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            *p1 = i;
            break;
        }
    }

    // Verifica o menor número primo maior que m
    for (i = m + 1;; i++) {
        int isPrime = 1;
        for (j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            *p2 = i;
            break;
        }
    }
}

int main() {
    int m, p1, p2;
    scanf("%d", &m);

    primos(m, &p1, &p2);

    printf("%d\n", p1);
    printf("%d\n", p2);

    return 0;
}