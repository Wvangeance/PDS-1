#include <stdio.h>
#include <string.h>

int main() {
    char S1[100], S2[100];
    char *resultado;

    printf("Digite a string S1: ");
    fgets(S1, sizeof(S1), stdin);

    printf("Digite a string S2: ");
    fgets(S2, sizeof(S2), stdin);

    resultado = strstr(S1, S2);

    if(resultado) {
        printf("É substring\n");
    } else {
        printf("Não é substring\n");
    }

    return 0;
}
