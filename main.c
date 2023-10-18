#include <stdbool.h>
#include <stdio.h>
#include "sae.h"

static void jeu_gagne(int score) {
    printf("Gagne avec un score de %d\n", score);
}
static void jeu_perdu(int score) {
    printf("Aie... Coup dur... Score: %d\n", score);
}

int main() {
    puts("NOTRE SUPER JEU!!!1!\n"
         " 1 - Suite mystere\n"
         " 2 - Nombre cache\n"
         " 3 - Mastermind");

    int numero_jeu = 0;
    while (numero_jeu < 1 || numero_jeu > 3) {
        printf("Entrer le numero du jeu [1-3]: ");
        scanf("%d", &numero_jeu);
    }
    while (getchar() != '\n');

    int score; bool victoire;
    switch (numero_jeu) {
    case 1: score = suite_mystere(&victoire); break;
    case 2: score = nbrcacher(&victoire); break;
    case 3: score = mastermind(&victoire); break;
    }

    if (victoire)
        jeu_gagne(score);
    else
        jeu_perdu(score);

    return 0;
}
