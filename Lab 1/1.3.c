#include <stdio.h>

int main() {
    int x, y, z;

    // Read input values
    scanf("%d %d %d", &x, &y, &z);

    // Check if x is divisible by both y and z
    if (x % y == 0 && x % z == 0) {
        printf("O número é divisível\n");
    } else {
        printf("O número não é divisível\n");
    }

    return 0;
}
