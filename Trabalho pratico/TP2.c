#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 1000
#define MAX_NOME 100
#define MAX_ESTADO 3

typedef struct {
    char codigo[10];
    char nome[MAX_NOME];
    int quantidade;
    float preco;
    char estado[MAX_ESTADO];
} Produto;

void lerDados(char *nomeArquivo, Produto produtos[], int *qtdProdutos) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    fscanf(arquivo, "%d", qtdProdutos);

    for (int i = 0; i < *qtdProdutos; i++) {
        fscanf(arquivo, "%s", produtos[i].codigo);
        fgetc(arquivo); // remover '\n'
        fgets(produtos[i].nome, MAX_NOME, arquivo);
        produtos[i].nome[strcspn(produtos[i].nome, "\n")] = 0; 
        fscanf(arquivo, "%d", &produtos[i].quantidade);
        fscanf(arquivo, "%f", &produtos[i].preco);
        fscanf(arquivo, "%s", produtos[i].estado);
    }

    fclose(arquivo);
}

void gerarRelatorio(Produto produtos[], int qtdProdutos, char *nomeArquivoSaida) {
    FILE *arquivo = fopen(nomeArquivoSaida, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo");
        exit(EXIT_FAILURE);
    }

    // Ordenar produtos por nome
    for (int i = 0; i < qtdProdutos - 1; i++) {
        for (int j = i + 1; j < qtdProdutos; j++) {
            if (strcmp(produtos[i].nome, produtos[j].nome) > 0) {
                Produto temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }

    for (int i = 0; i < qtdProdutos; i++) {
        fprintf(arquivo, "%s\n%s\n%d\n%.2f\n%s\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].estado);
    }

    fclose(arquivo);
}

void pesquisarPorCodigo(Produto produtos[], int qtdProdutos, char *codigo) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigo) == 0) {
            printf("%s\n%s\n%d\n%.2f\n%s\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco, produtos[i].estado);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void listarMenorQuantidade(Produto produtos[], int qtdProdutos) {
    if (qtdProdutos == 0) return;
    
    Produto *menor = &produtos[0];
    for (int i = 1; i < qtdProdutos; i++) {
        if (produtos[i].quantidade < menor->quantidade) {
            menor = &produtos[i];
        }
    }

    printf("%s\n%s\n%d\n%.2f\n%s\n", menor->codigo, menor->nome, menor->quantidade, menor->preco, menor->estado);
}

void listarPorEstado(Produto produtos[], int qtdProdutos, char *estado) {
    Produto produtosEstado[MAX_PRODUTOS];
    int qtdEstado = 0;

    for (int i = 0; i < qtdProdutos; i++) {
        if (strcmp(produtos[i].estado, estado) == 0) {
            produtosEstado[qtdEstado++] = produtos[i];
        }
    }

    // Ordenar por nome
    for (int i = 0; i < qtdEstado - 1; i++) {
        for (int j = i + 1; j < qtdEstado; j++) {
            if (strcmp(produtosEstado[i].nome, produtosEstado[j].nome) > 0) {
                Produto temp = produtosEstado[i];
                produtosEstado[i] = produtosEstado[j];
                produtosEstado[j] = temp;
            }
        }
    }

    for (int i = 0; i < qtdEstado; i++) {
        printf("%s\n%s\n%d\n%.2f\n%s\n", produtosEstado[i].codigo, produtosEstado[i].nome, produtosEstado[i].quantidade, produtosEstado[i].preco, produtosEstado[i].estado);
    }
}

void menorQuantidadePorEstado(Produto produtos[], int qtdProdutos, char *estado) {
    Produto *menor = NULL;

    for (int i = 0; i < qtdProdutos; i++) {
        if (strcmp(produtos[i].estado, estado) == 0) {
            if (menor == NULL || produtos[i].quantidade < menor->quantidade) {
                menor = &produtos[i];
            }
        }
    }

    if (menor != NULL) {
        printf("%s\n%s\n%d\n%.2f\n%s\n", menor->codigo, menor->nome, menor->quantidade, menor->preco, menor->estado);
    } else {
        printf("Nenhum produto encontrado para o estado %s.\n", estado);
    }
}

void calcularTotal(Produto produtos[], int qtdProdutos) {
    int quantidadeTotal = 0;
    float precoTotal = 0;

    for (int i = 0; i < qtdProdutos; i++) {
        quantidadeTotal += produtos[i].quantidade;
        precoTotal += produtos[i].preco * produtos[i].quantidade;
    }

    printf("%d\n%.2f\n", quantidadeTotal, precoTotal);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Uso: %s <arquivo_entrada> <opcao> [param3]\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *arquivoEntrada = argv[1];
    int opcao = atoi(argv[2]);
    char *param3 = argc == 4 ? argv[3] : NULL;

    Produto produtos[MAX_PRODUTOS];
    int qtdProdutos;

    lerDados(arquivoEntrada, produtos, &qtdProdutos);

    switch (opcao) {
        case 1:
            if (param3) {
                gerarRelatorio(produtos, qtdProdutos, param3);
            } else {
                fprintf(stderr, "Parâmetro de saída não fornecido.\n");
                return EXIT_FAILURE;
            }
            break;
        case 2:
            if (param3) {
                pesquisarPorCodigo(produtos, qtdProdutos, param3);
            } else {
                fprintf(stderr, "Código do produto não fornecido.\n");
                return EXIT_FAILURE;
            }
            break;
        case 3:
            listarMenorQuantidade(produtos, qtdProdutos);
            break;
        case 4:
            if (param3) {
                listarPorEstado(produtos, qtdProdutos, param3);
            } else {
                fprintf(stderr, "Estado não fornecido.\n");
                return EXIT_FAILURE;
            }
            break;
        case 5:
            if (param3) {
                menorQuantidadePorEstado(produtos, qtdProdutos, param3);
            } else {
                fprintf(stderr, "Estado não fornecido.\n");
                return EXIT_FAILURE;
            }
            break;
        case 6:
            calcularTotal(produtos, qtdProdutos);
            break;
        default:
            fprintf(stderr, "Opção inválida.\n");
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}