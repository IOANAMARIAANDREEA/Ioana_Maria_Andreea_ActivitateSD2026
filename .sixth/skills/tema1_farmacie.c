#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct
typedef struct {
    int id;
    char* denumire;
    char* producator;
    float pret;
    int stoc;
} Medicament;

// initializare
Medicament initializare(int id, const char* denumire, const char* producator,
    float pret, int stoc) {

    Medicament m;
    m.id = id;

    m.denumire = (char*)malloc(strlen(denumire) + 1);
    strcpy(m.denumire, denumire);

    m.producator = (char*)malloc(strlen(producator) + 1);
    strcpy(m.producator, producator);

    m.pret = pret;
    m.stoc = stoc;

    return m;
}

// afisare medicament
void afisare(Medicament m) {
    printf("ID: %d\n", m.id);
    printf("Denumire: %s\n", m.denumire);
    printf("Producator: %s\n", m.producator);
    printf("Pret: %.2f\n", m.pret);
    printf("Stoc: %d\n\n", m.stoc);
}

// afisare vector
void afisareVector(Medicament* vector, int nr) {
    for (int i = 0; i < nr; i++) {
        afisare(vector[i]);
    }
}

// dezalocare memorie
void dezalocare(Medicament** vector, int* nr) {
    for (int i = 0; i < *nr; i++) {
        free((*vector)[i].denumire);
        free((*vector)[i].producator);
    }
    free(*vector);
    *vector = NULL;
    *nr = 0;
}

// main
int main() {

    int nr = 3;
    Medicament* vector = (Medicament*)malloc(sizeof(Medicament) * nr);

    vector[0] = initializare(1, "Paracetamol", "Terapia", 12.5, 50);
    vector[1] = initializare(2, "Nurofen", "Reckitt", 24.9, 30);
    vector[2] = initializare(3, "Augmentin", "GSK", 31.7, 20);

    printf("Lista medicamente:\n\n");
    afisareVector(vector, nr);

    dezalocare(&vector, &nr);

    return 0;
}