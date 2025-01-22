#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 5
#define NAME_LENGTH 50
#define ADDRESS_LENGTH 50

typedef struct {
    char street[ADDRESS_LENGTH];
    unsigned int number;
    char state[ADDRESS_LENGTH];
} Address;

typedef struct {
    char name[NAME_LENGTH];
    unsigned int age;
    float salary;
    Address address;
} Person;

void insert_person(Person people[], int *count, const char *name, unsigned int age, float salary, const char *street, unsigned int number, const char *state) {
    if (*count >= MAX_PEOPLE) {
        printf("Espaco insuficiente\n");
    } else {
        strcpy(people[*count].name, name);
        people[*count].age = age;
        people[*count].salary = salary;
        strcpy(people[*count].address.street, street);
        people[*count].address.number = number;
        strcpy(people[*count].address.state, state);
        printf("Registro %s %u %.2f %s %u %s inserido\n", name, age, salary, street, number, state);
        (*count)++;
    }
}

void show_person(Person people[], int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Registro %s %u %.2f %s %u %s\n", people[i].name, people[i].age, people[i].salary, people[i].address.street, people[i].address.number, people[i].address.state);
            return;
        }
    }
    printf("Registro ausente\n");
}

void alter_person(Person people[], int count, const char *name, unsigned int age, float salary, const char *street, unsigned int number, const char *state) {
    for (int i = 0; i < count; i++) {
        if (strcmp(people[i].name, name) == 0) {
            people[i].age = age;
            people[i].salary = salary;
            strcpy(people[i].address.street, street);
            people[i].address.number = number;
            strcpy(people[i].address.state, state);
            printf("Registro %s %u %.2f %s %u %s alterado\n", name, age, salary, street, number, state);
            return;
        }
    }
    printf("Registro ausente para alteracao\n");
}

int main() {
    Person people[MAX_PEOPLE];
    int count = 0;
    char operation[10];
    char name[NAME_LENGTH];
    unsigned int age;
    float salary;
    char street[ADDRESS_LENGTH];
    unsigned int number;
    char state[ADDRESS_LENGTH];

    while (scanf("%s", operation) != EOF) {
        if (strcmp(operation, "inserir") == 0) {
            scanf("%s %u %f %s %u %s", name, &age, &salary, street, &number, state);
            insert_person(people, &count, name, age, salary, street, number, state);
        } else if (strcmp(operation, "mostrar") == 0) {
            scanf("%s", name);
            show_person(people, count, name);
        } else if (strcmp(operation, "alterar") == 0) {
            scanf("%s %u %f %s %u %s", name, &age, &salary, street, &number, state);
            alter_person(people, count, name, age, salary, street, number, state);
        }
    }

    return 0;
}
