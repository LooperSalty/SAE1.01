#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 
#include "sae.h"

void nbrcacher() {
    int n, nbrutilisateurs, tentatives = 0;
    bool correct = false;

    srand(time(0));

    n = rand() % 1000 + 1; 

    printf("Devinez un nombre entre 1 et 1000\n");

    while (tentatives < 10) { 
        printf("Tentative %d : ", tentatives + 1);
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

        tentatives++;
    }

    if (correct) {
        printf("Félicitations, vous avez deviné le nombre en %d tentatives !\n", tentatives);
    } else {
        printf("Désolé, vous n'avez pas réussi à deviner le nombre. Le nombre était : %d\n", n);
    }

}