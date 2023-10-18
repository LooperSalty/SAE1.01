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

    *victoire = false;

    srand(time(NULL));

    n = rand() % 1000 + 1; 

    printf("Devinez un nombre entre 1 et 1000\n");

    while (tentatives < 10) { 
        printf("Tentative %d : ", ++tentatives);
        scanf("%d", &nbrutilisateurs); 

        // Verification du nombre
        if (nbrutilisateurs < 1 || nbrutilisateurs > 1000) {
            printf("Le nombre doit être entre 1 et 1000. Réessayez.\n");
        } else if (nbrutilisateurs < n) {
            printf("Le nombre à deviner est plus grand.\n");
        } else if (nbrutilisateurs > n) {
            printf("Le nombre à deviner est plus petit.\n");
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
