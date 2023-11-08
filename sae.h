/*
** SAE1.01
** Paul RUIZ - Matthilde CONDENSEAU
**
** sae.h
**
** Fichier d'entete contenant les definitions de fonctions necessaires au
** fonctionnement du logiciel.
*/
#ifndef SAE_H_
#define SAE_H_

// mystere.c
int suite_mystere(int *victoire);
// cache.c
int nbr_cache(int *victoire);
// mastermind.c
int mastermind(int *victoire);
// commun.c
int lire_nombre(const char* prompt);

#endif
