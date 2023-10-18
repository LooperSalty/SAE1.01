#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#include "sae.h"

// Le jeu du nombre cache:
//  Demande a l'utilisateur de deviner un nombre
int nbrcacher(bool *victoire) {
    int n, score, nbrutilisateurs, tentatives = 0;
    bool correct = false;

    srand(time(NULL));

     const char *phrases[5] = {
        "lâche pas les études",
        "toujours aussi nul",
        "encore sa fait beaucoup la non ?",
        "aie coup du pour guillaume",
        "T'est éclater au sol !"
    };

    *victoire = false;
    n = rand() % 1000 + 1; 

    printf("Devinez un nombre entre 1 et 1000\n");

    while (tentatives < 10) { 
        int indice = rand() % 5;
        printf("Tentative %d : ", ++tentatives);
        scanf("%d", &nbrutilisateurs); 

        // Verification du nombre
        if (nbrutilisateurs < 1 || nbrutilisateurs > 1000) {
            printf("Le nombre doit être entre 1 et 1000. Réessayez.\n");
            printf("%s\n", phrases[indice]);
        } else if (nbrutilisateurs < n) {
            printf("Le nombre à deviner est plus grand.\n");
            printf("%s\n", phrases[indice]);
        } else if (nbrutilisateurs > n) {
            printf("Le nombre à deviner est plus petit.\n");
            printf("%s\n", phrases[indice]);
        } else {
            correct = *victoire = true;
            break; 
        }
    }

    // On calcule le score
    score = correct ? tentatives : 11;

    // Renvoi du score
    return score;
}
