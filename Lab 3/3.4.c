#include <stdio.h>

int main() {
    int nAEDS1, nCalc1, i, j;

    scanf("%d", &nAEDS1);

    int matAEDS1[nAEDS1];

    for (i = 0; i < nAEDS1; i++) {
        scanf("%d", &matAEDS1[i]);
    }

    scanf("%d", &nCalc1);

    int matCalc1[nCalc1];

    for (i = 0; i < nCalc1; i++) {
        scanf("%d", &matCalc1[i]);
    }

    for (i = 0; i < nAEDS1; i++) {
        for (j = 0; j < nCalc1; j++) {
            if (matAEDS1[i] == matCalc1[j]) {
                printf("%d\n", matAEDS1[i]);
            }
        }
    }

    return 0;
}
