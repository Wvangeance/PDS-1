#include <stdio.h>

int main() {
    int X;
    scanf("%d", &X);

    int count_2 = 0, count_3 = 0, count_5 = 0, count_2_3_5 = 0;
    int i = 1;
    while (i <= X) {
        if (i % 2 == 0) count_2++;
        if (i % 3 == 0) count_3++;
        if (i % 5 == 0) count_5++;
        if (i % 2 == 0 && i % 3 == 0 && i % 5 == 0) count_2_3_5++;
        i++;
    }

    printf("Múltiplos de 2: %d\n", count_2);
    printf("Múltiplos de 3: %d\n", count_3);
    printf("Múltiplos de 5: %d\n", count_5);
    printf("Múltiplos de todos: %d\n", count_2_3_5);

    return 0;
}

