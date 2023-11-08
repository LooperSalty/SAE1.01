/*
** SAE1.01
** Paul RUIZ - Matthilde CONDENSEAU
**
** mastermind.c
**
** Le jeu du Mastermind.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
** mm_generer_sequence: Genere la sequence de voyelles
**
** @param char* voyelles: chaine de 4 caracteres a remplir.
*/
void mm_generer_sequence(char *voyelles) {
    const char alphabet[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int indicesUtilises[6] = {0};

    for (int i = 0; i < 4; i++) {
        int index;
        do {
            index = rand() % 6;
        } while (indicesUtilises[index] == 1);
        indicesUtilises[index] = 1;
        voyelles[i] = alphabet[index];
    }
}

/*
** mm_lire_voyelle: lit une voyelle
** La fonction ne s'arretera pas tant qu'il n'aura pas eu sa voyelle.
**
** @param i: numero de tentative (pour l'affichage)
** @return char: voyelle
*/
char mm_lire_voyelle(int i) {
    char rep;

    do {
        printf("\nSaisissez voyelle %d (minuscule) : ", i);
        scanf(" %c", &rep);
        while (getchar() != '\n');
    } while (rep != 'a' && rep != 'e' &&
             rep != 'i' && rep != 'o' &&
             rep != 'u' && rep != 'y');
    return rep;
}

/*
** mm_compare: compare les voyelles
** La fonction va verifier si toutes les voyelles ont ete mises a leur place et
** indique a l'utilisateur les bonnes et mauvaises reponses.
**
** @param char voyelles[4]: series de voyelles
** @param char propositions[4]: entree de l'utilisateur
*/
void mm_compare(char voyelles[4], char propositions[4]) {
    for (int i = 0; i < 4; i++) {
        if (propositions[i] == voyelles[i]) {
            printf("\nUne voyelle est correcte et bien placée\n");
        } else {
            for (int j = 0; j < 4; j++) {
                if (propositions[i] == voyelles[j] && i != j) {
                    printf("\nUne voyelle est correcte mais mal placée\n");
                    break;
                }
            }
        }
    }
}

/*
** mastermind: programme principal du jeu
**
** @param int *victoire: la fonction ecrira 1 si le joueur a gagne
** @return int: score
*/
int mastermind(int *victoire) {
    char voyelles[4], propositions[4];
    int tentatives;
    *victoire = 0;

    srand(time(NULL));
    mm_generer_sequence(voyelles);

    puts("L'ordinateur a généré aléatoirement une suite de 4 voyelles uniques.\n"
         "Vous avez jusqu'à 10 essais pour retrouver cette suite.\n");
    printf("%c %c %c %c\n", voyelles[0], voyelles[1], voyelles[2], voyelles[3]);

    for (tentatives = 0; !*victoire && tentatives < 10; ++tentatives) {
        for (int i = 0; i < 4; i++) {
            propositions[i] = mm_lire_voyelle(i+1);
        }

        mm_compare(voyelles, propositions);

        if (propositions[0] == voyelles[0] &&
            propositions[1] == voyelles[1] &&
            propositions[2] == voyelles[2] &&
            propositions[3] == voyelles[3]) {
            *victoire = 1;
        }
    }

    return tentatives + 1;
}
