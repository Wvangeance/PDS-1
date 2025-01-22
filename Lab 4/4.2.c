#include <stdio.h>
#include <string.h>

int main() {
    char str[100], str_invertida[100];
    int i, j, len;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str) - 1; // desconta o caractere de nova linha

    for(i = len - 1, j = 0; i >= 0; i--, j++) {
        str_invertida[j] = str[i];
    }

    str_invertida[j] = '\0'; // adiciona o caractere nulo no final

    printf("A string invertida é: %s", str_invertida);

    return 0;
}
