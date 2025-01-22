#include <stdio.h>

int main() {
    int i = 233;
    do {
        printf("%d\n", i);
        if (i >= 300 && i <= 400) {
            i += 3;
        } else {
            i += 5;
        }
    } while (i <= 457);

    return 0;
}
