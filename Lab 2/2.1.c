#include <stdio.h>

void print_series(int n, int x0, int x1) {
    printf("X0: %d\n", x0);
    printf("X1: %d\n", x1);

    int xn;
    for (int i = 2; i <= n; i++) {
        xn = 4 * x1 - 2 * x0;
        printf("X%d: %d\n", i, xn);
        x0 = x1;
        x1 = xn;
    }
}

int main() {
    int n, x0, x1;
     scanf("%d %d %d", &n, &x0, &x1);
    print_series(n, x0, x1);
    return 0;
}
