#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_TYPE_LENGTH 50

typedef struct {
    float comprimento_sepala;
    float largura_sepala;
    float comprimento_petala;
    float largura_petala;
    char tipo[MAX_TYPE_LENGTH];
} Iris;

void lerIris(Iris *iris) {
    scanf("%f %f %f %f %[^\n]s", &iris->comprimento_sepala, &iris->largura_sepala, &iris->comprimento_petala, &iris->largura_petala, iris->tipo);
}

float calcularDistancia(Iris a, Iris b) {
    return sqrt(pow(a.comprimento_sepala - b.comprimento_sepala, 2) +
                pow(a.largura_sepala - b.largura_sepala, 2) +
                pow(a.comprimento_petala - b.comprimento_petala, 2) +
                pow(a.largura_petala - b.largura_petala, 2));
}

void classificar(Iris nao_identificada, Iris registros_identificados[], int n) {
    float menor_distancia = calcularDistancia(nao_identificada, registros_identificados[0]);
    int indice_menor_distancia = 0;

    for (int i = 1; i < n; i++) {
        float distancia = calcularDistancia(nao_identificada, registros_identificados[i]);
        if (distancia < menor_distancia) {
            menor_distancia = distancia;
            indice_menor_distancia = i;
        }
    }

    printf("%s\n", registros_identificados[indice_menor_distancia].tipo);
}

int main() {
    int n;
    scanf("%d", &n);

    Iris registros_identificados[n];
    for (int i = 0; i < n; i++) {
        lerIris(&registros_identificados[i]);
    }

    Iris nao_identificada;
    lerIris(&nao_identificada);

    classificar(nao_identificada, registros_identificados, n);

    return 0;
}