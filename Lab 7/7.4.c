#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define TAM_NOME 50
#define TAM_TELEFONE 20

typedef struct {
    char nome[TAM_NOME];
    int idade;
    char telefone[TAM_TELEFONE];
} Contato;

void inserirContato(FILE *arquivo) {
    Contato contato;
    fseek(arquivo, 0, SEEK_END); // Move o ponteiro para o final do arquivo

    long tamanho = ftell(arquivo) / sizeof(Contato); // Calcula o número de contatos
    if (tamanho >= MAX_CONTATOS) {
        printf("Espaço insuficiente\n");
        return;
    }

    printf("Digite o nome: ");
    scanf(" %[^\n]", contato.nome);
    printf("Digite a idade: ");
    scanf("%d", &contato.idade);
    printf("Digite o telefone: ");
    scanf(" %[^\n]", contato.telefone);

    fwrite(&contato, sizeof(Contato), 1, arquivo);
    printf("Registro %s %d %s inserido\n", contato.nome, contato.idade, contato.telefone);
}

void alterarContato(FILE *arquivo) {
    Contato contato;
    char nome[TAM_NOME];
    int encontrado = 0;

    printf("Digite o nome do contato a alterar: ");
    scanf(" %[^\n]", nome);

    fseek(arquivo, 0, SEEK_SET); // Move para o início do arquivo
    while (fread(&contato, sizeof(Contato), 1, arquivo)) {
        if (strcmp(contato.nome, nome) == 0) {
            encontrado = 1;
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", contato.nome);
            printf("Digite a nova idade: ");
            scanf("%d", &contato.idade);
            printf("Digite o novo telefone: ");
            scanf(" %[^\n]", contato.telefone);

            fseek(arquivo, -sizeof(Contato), SEEK_CUR); // Volta para regravar o contato
            fwrite(&contato, sizeof(Contato), 1, arquivo);
            printf("Registro %s alterado\n", contato.nome);
            break;
        }
    }

    if (!encontrado) {
        printf("Registro %s invalido\n", nome);
    }
}

void excluirContato(FILE *arquivo) {
    FILE *temp = fopen("temp.bin", "wb");
    Contato contato;
    char nome[TAM_NOME];
    int encontrado = 0;

    if (!temp) {
        printf("Erro ao criar arquivo temporário.\n");
        return;
    }

    printf("Digite o nome do contato a excluir: ");
    scanf(" %[^\n]", nome);

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&contato, sizeof(Contato), 1, arquivo)) {
        if (strcmp(contato.nome, nome) == 0) {
            encontrado = 1;
            printf("Registro %s %d %s excluido\n", contato.nome, contato.idade, contato.telefone);
        } else {
            fwrite(&contato, sizeof(Contato), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    remove("agenda.bin");
    rename("temp.bin", "agenda.bin");

    if (!encontrado) {
        printf("Registro %s invalido\n", nome);
    }
}

void exibirContato(FILE *arquivo) {
    Contato contato;
    char nome[TAM_NOME];
    int encontrado = 0;

    printf("Digite o nome do contato a exibir: ");
    scanf(" %[^\n]", nome);

    fseek(arquivo, 0, SEEK_SET);
    while (fread(&contato, sizeof(Contato), 1, arquivo)) {
        if (strcmp(contato.nome, nome) == 0) {
            encontrado = 1;
            printf("Registro %s %d %s exibido\n", contato.nome, contato.idade, contato.telefone);
            break;
        }
    }

    if (!encontrado) {
        printf("Registro %s invalido\n", nome);
    }
}

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    char opcao[10];

    printf("Digite o nome do arquivo: ");
    scanf(" %[^\n]", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r+b"); // Abre o arquivo para leitura e escrita em binário
    if (!arquivo) {
        arquivo = fopen(nomeArquivo, "w+b"); // Cria o arquivo se não existir
        if (!arquivo) {
            printf("Erro ao abrir ou criar o arquivo.\n");
            return 1;
        }
    }

    while (1) {
        printf("Digite uma opcao (Inserir, Alterar, Excluir, Exibir, Sair): ");
        scanf(" %[^\n]", opcao);

        if (strcmp(opcao, "Inserir") == 0) {
            inserirContato(arquivo);
        } else if (strcmp(opcao, "Alterar") == 0) {
            alterarContato(arquivo);
        } else if (strcmp(opcao, "Excluir") == 0) {
            excluirContato(arquivo);
            arquivo = fopen(nomeArquivo, "r+b"); // Reabrir arquivo apos exclusão
        } else if (strcmp(opcao, "Exibir") == 0) {
            exibirContato(arquivo);
        } else if (strcmp(opcao, "Sair") == 0) {
            break;
        } else {
            printf("Opcao invalida\n");
        }
    }

    fclose(arquivo);
    return 0;
}
