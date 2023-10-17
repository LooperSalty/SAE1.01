#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#include "sae.h"

int mastermind() {
    int var1;
    int essaisr = 10;
    char lettre;
    char voy1, voy2, voy3, voy4;
    char rep1, rep2, rep3, rep4;
    bool victoire = false;
    float scoremm;
    time_t debut, fin;
    int tempsfinal;

    srand(time(NULL));

    do {
        for (int i = 0; i < 4; i++) {
            var1 = (rand() % 5 + 1);
            switch (var1) {
                case 0:
                    lettre = 'a';
                    break;
                case 1:
                    lettre = 'e';
                    break;
                case 2:
                    lettre = 'i';
                    break;
                case 3:
                    lettre = 'o';
                    break;
                case 4:
                    lettre = 'u';
                    break;
                case 5:
                    lettre = 'y';
                    break;
            }

            if (i == 0) {
                voy1 = lettre;
            }
            else if (i == 1) {
                voy2 = lettre;
            }
            else if (i == 2) {
                voy3 = lettre;
            }
            else if (i == 3) {
                voy4 = lettre;
            }
        }
    } while (voy1 == voy2 || voy1 == voy3 || voy1 == voy4 || voy2 == voy3 || voy2 == voy4 || voy3 == voy4);

    printf("L'ordinateur a généré aléatoirement une suite de 4 voyelles.\nVous avez jusqu'à 10 essais pour retrouver cette suite.\n\n");

    debut = time(NULL);

    do {
        do {
            printf("\nProposition pour la 1e voyelle : ");
            while ((getchar()) != '\n');
            rep1 = getchar();

            if (rep1 != 'a' && rep1 != 'e' && rep1 != 'i' && rep1 != 'o' && rep1 != 'u' && rep1 != 'y') {
                printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINUSCULES\n");
            }
        } while (rep1 != 'a' && rep1 != 'e' && rep1 != 'i' && rep1 != 'o' && rep1 != 'u' && rep1 != 'y');

        do {
            printf("Proposition pour la 2e voyelle : ");
            while ((getchar()) != '\n');
            rep2 = getchar();

            if (rep2 != 'a' && rep2 != 'e' && rep2 != 'i' && rep2 != 'o' && rep2 != 'u' && rep2 != 'y') {
                printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINUSCULES\n");
            }
        } while (rep2 != 'a' && rep2 != 'e' && rep2 != 'i' && rep2 != 'o' && rep2 != 'u' && rep2 != 'y');

        do {
            printf("Proposition pour la 3e voyelle : ");
            while ((getchar()) != '\n');
            rep3 = getchar();

            if (rep3 != 'a' && rep3 != 'e' && rep3 != 'i' && rep3 != 'o' && rep3 != 'u' && rep3 != 'y') {
                printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINUSCULES\n");
            }
        } while (rep3 != 'a' && rep3 != 'e' && rep3 != 'i' && rep3 != 'o' && rep3 != 'u' && rep3 != 'y');

        do {
            printf("Proposition pour la 4e voyelle : ");
            while ((getchar()) != '\n');
            rep4 = getchar();

            if (rep4 != 'a' && rep4 != 'e' && rep4 != 'i' && rep4 != 'o' && rep4 != 'u' && rep4 != 'y') {
                printf("Saisie incorrecte, veuillez saisir une VOYELLE en MINUSCULES\n");
            }
        } while (rep4 != 'a' && rep4 != 'e' && rep4 != 'i' && rep4 != 'o' && rep4 != 'u' && rep4 != 'y');

        if (rep1 == voy1) {
            printf("\nUne voyelle est correcte et bien placée");
        }
        else if (rep1 == voy2) {
            printf("\nUne voyelle est correcte mais mal placée");
        }
        else if (rep1 == voy3) {
            printf("\nUne voyelle est correcte mais mal placée");
        }
        else if (rep1 == voy4) {
            printf("\nUne voyelle est correcte mais mal placée");
        }

        if (rep2 == voy2) {
            printf("\nUne voyelle est correcte et bien placée");
        }
        else if (rep2 == voy1) {
            printf("\nUne voyelle est correcte mais mal placée");
        }
        else if (rep2 == voy3) {
            printf("\nUne voyelle est correcte mais mal placée");
        }
        else if (rep2 == voy4) {
            printf("\nUne voyelle est correcte mais mal placée");
        }

        if (rep3 == voy3) {
            printf("\nUne voyelle est correcte and bien placée");
        }
        else if (rep3 == voy2) {
            printf("\nUne voyelle est correcte but mal placée");
        }
        else if (rep3 == voy1) {
            printf("\nUne voyelle est correcte but mal placée");
        }
        else if (rep3 == voy4) {
            printf("\nUne voyelle est correcte but mal placée");
        }

        if (rep4 == voy4) {
            printf("\nUne voyelle est correcte and bien placée");
        }
        else if (rep4 == voy2) {
            printf("\nUne voyelle est correcte but mal placée");
        }
        else if (rep4 == voy3) {
            printf("\nUne voyelle est correcte but mal placée");
        }
        else if (rep4 == voy1) {
            printf("\nUne voyelle est correcte but mal placée");
        }

        essaisr = essaisr - 1;

        if (rep1 == voy1 && rep2 == voy2 && rep3 == voy3 && rep4 == voy4) {
            victoire = true;
        }
        else if (essaisr <= 0) {
            break;
        }
    } while (victoire == false);

}
