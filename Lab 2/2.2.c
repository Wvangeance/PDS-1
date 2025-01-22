#include <stdio.h>
#include <math.h>

int main() {
    double X, pi = 0;
    int i = 0;

    printf("Digite o valor de X para a diferença máxima desejada: ");
    scanf("%lf", &X);

    // Calcula a aproximação de Pi usando a série de Gregory-Leibniz
    while(fabs(M_PI - pi) > X) {
        pi += pow(-1, i) * (4.0 / (2 * i + 1));
        i++;
    }

    // Imprime o número de iterações necessárias para atingir a aproximação desejada
    printf("Número de iterações: %d\n", i);

    return 0;
}
