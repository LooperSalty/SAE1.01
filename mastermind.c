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

char saisirVoyelle() {
    char rep;
    do {
        printf("\nSaisissez une voyelle en minuscules : ");
        rep = getchar();
        while (getchar() != '\n'); // Ajoutez cette ligne pour vider le tampon d'entrée

        if (rep != 'a' && rep != 'e' && rep != 'i' && rep != 'o' && rep != 'u' && rep != 'y') {
            printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINUSCULES\n");
        }
    } while (rep != 'a' && rep != 'e' && rep != 'i' && rep != 'o' && rep != 'u' && rep != 'y');
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

int mastermind() {
    char voyelles[4];
    char propositions[4];
    int essaisRestants = 10;
    bool victoire = false;

    srand(time(NULL));
    genererSequence(voyelles);

    printf("L'ordinateur a généré aléatoirement une suite de 4 voyelles.\nVous avez jusqu'à 10 essais pour retrouver cette suite.\n\n");

    do {
    for (int i = 0; i < 4; i++) {
        propositions[i] = saisirVoyelle();
    }

    comparerProposition(voyelles, propositions);
    essaisRestants--;

    if (propositions[0] == voyelles[0] && propositions[1] == voyelles[1] && propositions[2] == voyelles[2] && propositions[3] == voyelles[3]) {
        victoire = true;
        printf("Félicitations, vous avez trouvé la séquence correcte !\n");
        break;  // Sortir de la boucle si l'utilisateur a gagné
    } else if (essaisRestants <= 0) {
        printf("Vous avez épuisé tous vos essais. La séquence était : %c%c%c%c\n", voyelles[0], voyelles[1], voyelles[2], voyelles[3]);
        break;  // Sortir de la boucle si l'utilisateur a épuisé tous ses essais
    }
} while (!victoire);
}