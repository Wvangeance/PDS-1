#include <stdio.h>

int main() {
    char nomeArquivo[100];
    scanf("%s", nomeArquivo);

    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Falha ao abrir o arquivo.\n");
        return 1;
    }

    int contador = 0;
    char ch;
    while ((ch = fgetc(arquivo)) != EOF) {
        if (ch == 'a') {
            contador++;
        }
    }

    fclose(arquivo);

    printf("%d\n", contador);

    return 0;
}
