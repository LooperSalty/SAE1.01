# SAE1.01

![berner](bernard.jpg)

La SAE 1.01 est une serie de petits jeux ecrits en C et fonctionnant avec une
interface console (CLI). Dans ce dossier est inclus la source du projet mais
egalement un executable Linux x86-64 compile statiquement pour maximiser la
compatibilite.

## Fichiers

Dans la source est inclus

- `cache.c` - jeu du nombre cache
- `commun.c` - fonctions communes
- `main.c` - programme principal
- `mastermind.c` - le Mastermind
- `mystere.c` - la Suite Mystere
- `sae.h` - definitions de fonctions

## Compilation

Pour compiler, il est necessaire d'avoir un compilateur C (de preference GCC) et
GNU Make.

Tapez `make` pour compiler le programme, `make static` pour le compiler
statiquement et `make run` pour l'executer.
