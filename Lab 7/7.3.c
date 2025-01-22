#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

void read_matrix(FILE *file, long long int matrix[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            fscanf(file, "%lld", &matrix[i][j]);
        }
    }
}

void print_matrix(long long int matrix[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%lld ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char filename[100];
    FILE *file;
    long long int matrix1[TAMANHO][TAMANHO];
    long long int matrix2[TAMANHO][TAMANHO];
    long long int result[TAMANHO][TAMANHO];

    // Solicita o nome do arquivo ao usuário
    scanf("%s", filename);

    // Abre o arquivo para leitura
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê as duas matrizes do arquivo
    read_matrix(file, matrix1);
    read_matrix(file, matrix2);

    // Fecha o arquivo
    fclose(file);

    // Calcula a soma das matrizes
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    // Exibe a matriz resultante
    print_matrix(result);

    return 0;
}
