/*
** SAE1.01
** Paul RUIZ - Matthilde CONDENSEAU
**
** mystere.c
**
** La Suite Mystere, devinez le 4eme terme de la suite!
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "commun.h"

/*
** myst_coeff: donne un coefficient aleatoire entre 1 et 10
**
** @return int: coefficient
*/
int myst_coeff() {
    return rand() % 10 + 1;
}

/*
** myst_suite: Calcule le n-ieme terme de la suite mystere
**
** @param unsigned n: terme a calculer
** @param int a: 1er coefficient
** @param int b: 2nd coefficient
** @param int c: 3eme coefficient
** @return int: resultat
*/
int myst_suite(unsigned n, int a, int b, int c) {
    if (n == 0)
        return c;
    else
        return a * myst_suite(n - 1, a, b, c) + b;
}

/*
** suite_mystere: programme principal du jeu
**
** @param int *victoire: ecrit 1 si c'est gagne
** @return int: score
*/
int suite_mystere(int *victoire) {
    *victoire = 0;
    srand(time(NULL));

    // Variables pour mesurer le temps
    long debut, fin = 0;

    // Coefficients mystere
    int a = myst_coeff(), b = myst_coeff(), c = myst_coeff();

    int terme = myst_suite(3, a, b, c);

    // Saisie utilisateur, on mesure le temps qu'il prend
    int entree, score = 31;
    printf("Premiers termes de la suite: %d %d %d\n",
           myst_suite(0, a, b, c),
           myst_suite(1, a, b, c),
           myst_suite(2, a, b, c));

    debut = time(NULL);
    entree = lire_nombre("Entrer le 4eme terme:");
    fin = time(NULL) - debut;

    if (fin <= 30 && entree == terme) {
        score = fin;
        *victoire = 1;
    }

    return score;
}
