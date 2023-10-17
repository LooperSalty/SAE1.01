#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sae.h"

// Donne un coefficient aleatoire entre 1 et 10
static int myst_coeff() {
    return rand() % 10 + 1;
}

// Calcule le n-ieme terme de la suite mystere
static int myst_suite(unsigned n, int a, int b, int c) {
    if (n == 0)
        return c;
    else
        return a * myst_suite(n - 1, a, b, c) + b;
}

void suite_mystere() {
    srand(time(NULL));

    // Variables pour mesurer le temps
    long debut, fin;

    // Coefficients mystere
    int a = myst_coeff(), b = myst_coeff(), c = myst_coeff();

    // 4 premiers termes de la suite
    int termes[4];
    for (int i = 0; i < 4; ++i)
        termes[i] = myst_suite(i, a, b, c);

    // Saisie utilisateur, on mesure le temps qu'il prend
    int entree, score = 31;
    printf("Premiers termes de la suite: %d %d %d\nEntrer le 4eme terme: ",
           termes[0], termes[1], termes[2]);

    debut = time(NULL);
    scanf("%d", &entree);
    fin = time(NULL);

    if ((fin - debut) <= 30 && entree == termes[3])
        score = (fin - debut);
    printf("            _                                  \n");
printf("__   _____ | |_ _ __ ___   ___  ___ ___  _ __ ___\n");
printf("\\ \\ / / _ \\| __| '__/ _ \\ / __|/ __/ _ \\| '__/ _ \\\n");
printf(" \\ V / (_) | |_| | |  __/ \\__ \\ (_| (_) | | |  __/\n");
printf("  \\_/ \\___/ \\__|_|  \\___| |___/\\___\\___/|_|  \\___|\n");

    printf("\n: %d\n", score);
}
