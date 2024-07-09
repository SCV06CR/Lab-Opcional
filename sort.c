#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONAS 5

typedef struct {
    char name[50];
    int age;
    double height;
} Person;
int compare_by_name(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return strcmp(p1->name, p2->name);
}
int compare_by_age(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return p1->age - p2->age;
}
int compare_by_height(const void *a, const void *b) {
    Person *p1 = (Person *)a;
    Person *p2 = (Person *)b;
    return (p1->height > p2->height) - (p1->height < p2->height); // realiza una diferencia entre dos personas y retorna 1, -1 o 0
}
void print_personas(const Person *personas, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nombre: %s, Edad: %d, Altura: %.2f cm\n", personas[i].name, personas[i].age, personas[i].height);
    }

    printf("\n");

}

int main() {
    Person personas[MAX_PERSONAS] = {
        {"Sergio", 19, 175.0},
        {"Santiago", 20, 180.2},
        {"Sofia", 18, 166.0},
        {"Larissa", 22, 178.5},
        {"Felipe", 23, 172.8}
    };


    qsort(personas, MAX_PERSONAS, sizeof(Person), compare_by_name);
    printf("Nombre:\n");
    print_personas(personas, MAX_PERSONAS);
    qsort(personas, MAX_PERSONAS, sizeof(Person), compare_by_age);
    printf("Edad:\n");
    print_personas(personas, MAX_PERSONAS);
    qsort(personas, MAX_PERSONAS, sizeof(Person), compare_by_height);
    printf("Altura:\n");
    print_personas(personas, MAX_PERSONAS);

    return 0;
}