#include <stdio.h>
#include <stdlib.h>

void sumVectors(int* vector1, int* vector2, int* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = vector1[i] + vector2[i];
    }
}

int main() {
    int size;
    printf("Enter the size of the vectors: ");
    scanf("%d", &size);

    int* vector1 = (int*)malloc(size * sizeof(int));
    int* vector2 = (int*)malloc(size * sizeof(int));
    int* result = (int*)malloc(size * sizeof(int));

    printf("Enter the elements of vector 1:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &vector1[i]);
    }

    printf("Enter the elements of vector 2:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &vector2[i]);
    }

    sumVectors(vector1, vector2, result, size);

    printf("The sum of the vectors is:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", result[i]);
    }

    free(vector1);
    free(vector2);
    free(result);

    return 0;
}