#include <stdbool.h>
#include <stdio.h>
#include "sae.h"

void jeu_gagne(int score) {
    printf("\n");
    printf("  ____                               _ \n");
    printf(" / ___| __ _  __ _ _ __   ___ _ __  | |\n");
    printf("| |  _ / _` |/ _` | '_ \\ / _ \\ '__| | |\n");
    printf("| |_| | (_| | (_| | | | |  __/ |    |_|\n");
    printf(" \\____|\\__,_|\\__, |_| |_|\\___|_|    (_)\n");
    printf("             |___/\n");
    printf("\n");
    printf("\033[1;32m\n avec un score de %d\n033[0m", score);
}

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

int main() {
    bool rejouer;
    char tampon[32];

    printf("\n");
    printf("  _     _                                      \n");
    printf(" | |__ (_) ___ _ ____   _____ _ __  _   _  ___ \n");
    printf(" | '_ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |/ _ \\\n");
    printf(" | |_) | |  __/ | | \\ V /  __/ | | | |_| |  __/\n");
    printf(" |_.__/|_|\\___|_| |_|\_/ \\___|_| |_|\\__,_|\\___|\n");
    printf("\n");
    do {
        puts("NOTRE SUPER JEU!!!1!\n"
             " 1 - Suite mystere\n"
             " 2 - Nombre cache\n"
             " 3 - Mastermind");

        int numero_jeu = 0;
        while (numero_jeu < 1 || numero_jeu > 3) {
            printf("Entrer le numero du jeu [1-3]: ");
            fgets(tampon, 16, stdin);
            sscanf(tampon, "%d", &numero_jeu);
        }

        int score;
        bool victoire;

        switch (numero_jeu) {
            case 1: score = suite_mystere(&victoire); break;
            case 2: score = nbrcacher(&victoire); break;
            case 3: score = mastermind(&victoire); break;
        }

        if (victoire)
            jeu_gagne(score);
        else
            jeu_perdu(score);

        char choix;
        do {
            printf("Voulez-vous rejouer ? (o/n)\n");
            while (getchar() != '\n');
            scanf("%c", &choix);
            if (choix == 'o') {
                printf("C'est parti, on rejoue !\n");
                rejouer = true;
            } else if (choix == 'n') {
                rejouer = false;
            } else {
                printf("Saisie invalide. Veuillez choisir 'o' pour rejouer ou 'n' pour ne pas rejouer.\n");
            }
        } while (choix != 'o' && choix != 'n');
    } while (rejouer);

    return 0;
}
