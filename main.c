/*
** SAE1.01
** Paul RUIZ - Matthilde CONDENSEAU
**
** main.c
**
** Programme principal.
*/
#include <stdio.h>
#include "mystere.h"
#include "mastermind.h"
#include "cache.h"
#include "commun.h"

/*
** jeu_gagne: Le joueur a gagne
**
** @param int score: Score a afficher.
*/
void jeu_gagne(int score) {
    printf("\n");
    printf("  ____                               _ \n");
    printf(" / ___| __ _  __ _ _ __   ___ _ __  | |\n");
    printf("| |  _ / _` |/ _` | '_ \\ / _ \\ '__| | |\n");
    printf("| |_| | (_| | (_| | | | |  __/ |    |_|\n");
    printf(" \\____|\\__,_|\\__, |_| |_|\\___|_|    (_)\n");
    printf("             |___/\n");
    printf("\n");
    printf("\033[1;32m\n avec un score de %d\n\033[0m", score);
}

/*
** jeu_perdu: Le joueur a perdu
**
** @param int score: Score a afficher.
*/
void jeu_perdu(int score) {
    printf("\n");
    printf("                    _         _ \n");
    printf(" _ __   ___ _ __ __| |_   _  | |\n");
    printf("| '_ \\ / _ \\ '__/ _` | | | | | |\n");
    printf("| |_) |  __/ | | (_| | |_| | |_|\n");
    printf("| .__/ \\___|_|  \\__,_|\\__,_| (_)\n");
    printf("|_|                              \n");
    printf("\n");
    printf("\033[1;31m\nAie... Coup dur... Score: %d\n\033[0m", score);
}

/*
** main: Fonction principale
*/
int main() {
    int  rejouer;
    char tampon[32];

    printf("\n");
    printf("  _     _                                      \n");
    printf(" | |__ (_) ___ _ ____   _____ _ __  _   _  ___ \n");
    printf(" | '_ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |/ _ \\\n");
    printf(" | |_) | |  __/ | | \\ V /  __/ | | | |_| |  __/\n");
    printf(" |_.__/|_|\\___|_| |_|\\_/ \\___|_| |_|\\__,_|\\___|\n");
    printf("\n");
    do {
        puts("NOTRE SUPER JEU!!!1!\n"
             " 1 - Suite mystere\n"
             " 2 - Nombre cache\n"
             " 3 - Mastermind");

        int numero_jeu = 0;
        while ((numero_jeu = lire_nombre("Entrez le numero du jeu [1-3]:")) < 0
               || (numero_jeu < 1 || numero_jeu > 3)) ;

        int score;
        int victoire;

        switch (numero_jeu) {
            case 1: score = suite_mystere(&victoire); break;
            case 2: score = nbr_cache(&victoire); break;
            case 3: score = mastermind(&victoire); break;
        }

        if (victoire)
            jeu_gagne(score);
        else
            jeu_perdu(score);

        char choix;
        do {
            printf("Voulez-vous rejouer ? (o/n)\n");
            if (!fgets(tampon, 32, stdin)) { rejouer = 0; break; }
            choix = tampon[0];
            if (choix == 'o') {
                printf("C'est parti, on rejoue !\n");
                rejouer = 1;
            } else if (choix == 'n') {
                rejouer = 0;
            } else {
                printf("Saisie invalide. Veuillez choisir 'o' pour rejouer ou 'n' pour ne pas rejouer.\n");
            }
        } while (choix != 'o' && choix != 'n');
    } while (rejouer);

    return 0;
}
