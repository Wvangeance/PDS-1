#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 4
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    unsigned int age;
    float salary;
} Person;

void insert_person(Person people[], int *count, const char *name, unsigned int age, float salary) {
    if (*count >= MAX_PEOPLE) {
        printf("Espaco insuficiente\n");
    } else {
        strcpy(people[*count].name, name);
        people[*count].age = age;
        people[*count].salary = salary;
        printf("Registro %s %u %.2f inserido\n", name, age, salary);
        (*count)++;
    }
}

void show_person(Person people[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Registro %s %u %.2f\n", people[i].name, people[i].age, people[i].salary);
            return;
        }
    }
    printf("Registro ausente\n");
}

int main() {
    Person people[MAX_PEOPLE];
    int count = 0;
    char operation[10];
    char name[NAME_LENGTH];
    unsigned int age;
    float salary;

    while (scanf("%s", operation) != EOF) {
        if (strcmp(operation, "inserir") == 0) {
            scanf("%s %u %f", name, &age, &salary);
            insert_person(people, &count, name, age, salary);
        } else if (strcmp(operation, "mostrar") == 0) {
            scanf("%s", name);
            show_person(people, count, name);
        }
    }

    return 0;
}
