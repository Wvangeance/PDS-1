#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 8
#define MAX_COMPRIMENTO 50

typedef struct {
    char nome[MAX_COMPRIMENTO];
    char marca[MAX_COMPRIMENTO];
    float preco;
} Produto;

void calcular_estatisticas(Produto produtos[], int quantidade) {
    int contagem_marca[MAX_PRODUTOS] = {0};
    char marcas[MAX_PRODUTOS][MAX_COMPRIMENTO];
    int indice_marca = 0;
    float preco_total = 0.0;
    float preco_marca[MAX_PRODUTOS] = {0.0};

    // Processar cada produto
    for (int i = 0; i < quantidade; i++) {
        preco_total += produtos[i].preco;
        int encontrado = 0;
        for (int j = 0; j < indice_marca; j++) {
            if (strcmp(marcas[j], produtos[i].marca) == 0) {
                contagem_marca[j]++;
                preco_marca[j] += produtos[i].preco;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            strcpy(marcas[indice_marca], produtos[i].marca);
            contagem_marca[indice_marca]++;
            preco_marca[indice_marca] += produtos[i].preco;
            indice_marca++;
        }
    }

    // Imprimir o número de produtos para cada marca
    for (int i = 0; i < indice_marca; i++) {
        printf("%s %d\n", marcas[i], contagem_marca[i]);
    }

    // Imprimir o preço médio total
    printf("media total %.2f\n", preco_total / quantidade);

    // Imprimir o preço médio por marca
    for (int i = 0; i < indice_marca; i++) {
        printf("media %s %.2f\n", marcas[i], preco_marca[i] / contagem_marca[i]);
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    char nome[MAX_COMPRIMENTO], marca[MAX_COMPRIMENTO];
    float preco;

    // Ler 8 produtos
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        scanf("%s %s %f", nome, marca, &preco);
        strcpy(produtos[i].nome, nome);
        strcpy(produtos[i].marca, marca);
        produtos[i].preco = preco;
    }

    // Calcular e imprimir estatísticas
    calcular_estatisticas(produtos, MAX_PRODUTOS);

    return 0;
}
