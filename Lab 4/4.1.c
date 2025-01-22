#include <stdio.h>
#include <string.h>

int main() {
    char S1[100], S2[100], S3[200];

    printf("Digite a primeira string: ");
    fgets(S1, sizeof(S1), stdin);

    printf("Digite a segunda string: ");
    fgets(S2, sizeof(S2), stdin);

    strcpy(S3, S1);
    strcat(S3, S2);

    printf("A string concatenada é: %s", S3);

    return 0;
}
