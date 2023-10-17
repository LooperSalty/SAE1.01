#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#include "sae.h"

int nbrcacher() {
    int n, score, nbrutilisateurs, tentatives = 0;
    bool correct = false;

    srand(time(0));

    n = rand() % 1000 + 1; 

    printf("Devinez un nombre entre 1 et 1000\n");

    while (tentatives < 10) { 
        printf("Tentative %d : ", ++tentatives);
        scanf("%d", &nbrutilisateurs); 

        if (nbrutilisateurs < 1 || nbrutilisateurs > 1000) {
            printf("Le nombre doit être entre 1 et 1000. Réessayez.\n");
        } else if (nbrutilisateurs < n) {
            printf("Le nombre à deviner est plus grand.\n");
        } else if (nbrutilisateurs > n) {
            printf("Le nombre à deviner est plus petit.\n");
        } else {
            correct = true;
            break; 
        }
    }

    if (correct)
        score = tentatives;
    else
        score = 11;

    return score;
}
