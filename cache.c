#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sae.h"

#define NB_PHRASES 3

/*
** nbr_cache: jeu du nombre cache
** Le joueur doit devnier le nombre avec le moins de tentatives possible.
**
** @param int* victoire: ecrit 1 si le joueur a gagne
** @return int: score du joueur
*/
int nbr_cache(int *victoire) {
    char tampon[64];
    int n, score, nbrutilisateurs, tentatives = 0;

    // Genere une seed pour le generateur de nombres aleatoires.
    srand(time(NULL));

    // Phrases aleatoires
    const char *phrases[NB_PHRASES] = {
        "Lâche pas les études",
        "Encore ca fait beaucoup la non ?",
        "Aie, coup dur...",
    };

    *victoire = 0;
    n = rand() % 1000 + 1; 

    printf("Devinez un nombre entre 1 et 1000\n");

    while (tentatives < 10) { 
        sprintf(tampon, "Tentative %d:", ++tentatives);
        while ((nbrutilisateurs = lire_nombre(tampon)) < 0) ;

        // Verification du nombre
        if (nbrutilisateurs < 1 || nbrutilisateurs > 1000)
            printf("Le nombre doit être entre 1 et 1000. Réessayez.\n");
        else if (nbrutilisateurs < n)
            printf("Le nombre à deviner est plus grand.\n");
        else if (nbrutilisateurs > n)
            printf("Le nombre à deviner est plus petit.\n");
        else {
            *victoire = 1;
            break; 
        }
        printf("%s\n", phrases[rand() % NB_PHRASES]);
    }

    // On calcule le score
    score = *victoire ? tentatives : 11;

    // Renvoi du score
    return score;
}
