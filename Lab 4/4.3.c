#include <stdio.h>
#include <string.h>

int main() {
    char S[100], C1, C2;
    int i, len;

    printf("Digite uma string: ");
    fgets(S, sizeof(S), stdin);

    printf("Digite o caractere C1: ");
    scanf(" %c", &C1); // espaço antes de %c para ignorar o caractere de nova linha

    printf("Digite o caractere C2: ");
    scanf(" %c", &C2); // espaço antes de %c para ignorar o caractere de nova linha

    len = strlen(S);

    for(i = 0; i < len; i++) {
        if(S[i] == C1) {
            S[i] = C2;
            break;
        }
    }

    printf("A string após a substituição é: %s", S);

    return 0;
}
