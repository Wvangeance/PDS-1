#include <stdio.h>

int contar_a(char *nome_arquivo) {
    FILE *arquivo;
    int contador = 0;
    char ch;

    arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return -1;
    }

    while ((ch = fgetc(arquivo)) != EOF) {
        if (ch == 'a' || ch == 'A') {
            contador++;
        }
    }

    fclose(arquivo);

    return contador;
}

int main() {
    char nome_arquivo[100];

    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    int resultado = contar_a(nome_arquivo);
    if (resultado >= 0) {
        printf("O número de letras 'a' no arquivo é: %d\n", resultado);
    }

    return 0;
}