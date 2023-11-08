/*
** SAE1.01
** Paul RUIZ - Matthilde CONDENSEAU
**
** commun.c
**
** Fonctions communes a tout les modules.
*/
#include <stdio.h>

/*
** lire_nombre: Lire un nombre entier naturel depuis stdin
**
** @param const char* prompt: Message de demande
** @return int: Chiffre lu, renvoie -1 si aucun nombre n'a ete lu.
*/
int lire_nombre(const char* prompt) {
    char tampon[32]; // Memoire tampon de traitement
    int resultat;    // Resultat a renvoyer

    printf("%s ", prompt);
    if (fgets(tampon, 32, stdin) == NULL) return -1;
    if (!sscanf(tampon, "%u", &resultat)) return -1;
    return resultat;
}
