#include <stdio.h>
#include <string.h>

typedef enum {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
} Month;

typedef struct {
    int day;
    Month month;
    int year;
} Date;

typedef struct {
    char name[100];
    char location[100];
    Date date;
} Event;

void cadastrar_eventos(Event agenda[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter event name: ");
        scanf("%s", agenda[i].name);
        printf("Enter event location: ");
        scanf("%s", agenda[i].location);
        printf("Enter event date (day month year): ");
        scanf("%d %d %d", &agenda[i].date.day, (int*)&agenda[i].date.month, &agenda[i].date.year);
    }
}

void imprimir_eventos(Event agenda[], Date d, int n) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (agenda[i].date.day == d.day && agenda[i].date.month == d.month && agenda[i].date.year == d.year) {
            printf("%s %s\n", agenda[i].name, agenda[i].location);
            found = 1;
        }
    }
    if (!found) {
        printf("Nenhum evento encontrado!\n");
    }
}

int main() {
    int n;
    printf("Enter the number of events to register: ");
    scanf("%d", &n);

    Event agenda[n];

    cadastrar_eventos(agenda, n);

    Date searchDate;
    printf("Enter the date to search (day month year): ");
    scanf("%d %d %d", &searchDate.day, (int*)&searchDate.month, &searchDate.year);

    imprimir_eventos(agenda, searchDate, n);

    return 0;
}