#include <stdio.h>

int main() {
  
    float celsius, fahrenheit;

    printf("Temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (1.8 * celsius) + 32;

    printf("Temperatura em Fahrenheit: %.0f\n", fahrenheit);

    return 0;
  
}