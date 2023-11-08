#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sae.h"

// Donne un coefficient aleatoire entre 1 et 10
int myst_coeff() {
    return rand() % 10 + 1;
}

// Calcule le n-ieme terme de la suite mystere
int myst_suite(unsigned n, int a, int b, int c) {
    if (n == 0)
        return c;
    else
        return a * myst_suite(n - 1, a, b, c) + b;
}

int suite_mystere(bool *victoire) {
    *victoire = false;
    srand(time(NULL));

    // Variables pour mesurer le temps
    long debut, fin;

    // Coefficients mystere
    int a = myst_coeff(), b = myst_coeff(), c = myst_coeff();

    int terme;

    // Saisie utilisateur, on mesure le temps qu'il prend
    int entree, score = 31;
    printf("Premiers termes de la suite: %d %d %d\nEntrer le 4eme terme: ",
           myst_suite(0, a, b, c),
           myst_suite(1, a, b, c),
           myst_suite(2, a, b, c));

    debut = time(NULL);
    while (!scanf("%d", &entree) && difftime(debut, time(NULL)) < 30);
    fin = time(NULL);

    if ((fin - debut) <= 30 && entree == terme) {
        score = (fin - debut);
        *victoire = true;
    }

    return score;
}
