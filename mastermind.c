#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void genererSequence(char *voyelles) {
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

char saisirVoyelle(int i) {
    char rep;

    do {
        printf("\nSaisissez voyelle %d (minuscule) : ", i);
        rep = getchar();
        while (getchar() != '\n');
    } while (rep != 'a' && rep != 'e' &&
             rep != 'i' && rep != 'o' &&
             rep != 'u' && rep != 'y');
    return rep;
}


void comparerProposition(char voyelles[4], char propositions[4]) {
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

int mastermind(bool *victoire) {
    char voyelles[4], propositions[4];
    int tentatives;
    *victoire = false;

    srand(time(NULL));
    genererSequence(voyelles);

    puts("L'ordinateur a généré aléatoirement une suite de 4 voyelles.\n"
         "Vous avez jusqu'à 10 essais pour retrouver cette suite.\n");

    for (tentatives = 0; !*victoire && tentatives < 10; ++tentatives) {
        for (int i = 0; i < 4; i++) {
            propositions[i] = saisirVoyelle(i+1);
        }

        comparerProposition(voyelles, propositions);

        if (propositions[0] == voyelles[0] &&
            propositions[1] == voyelles[1] &&
            propositions[2] == voyelles[2] &&
            propositions[3] == voyelles[3]) {
            *victoire = true;
        }
    }

    return tentatives + 1;
}
