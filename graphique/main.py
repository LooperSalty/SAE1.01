# sae.py
import random
import time

def genererSequence():
    alphabet = ['a', 'e', 'i', 'o', 'u', 'y']
    indicesUtilises = [0] * 6
    voyelles = []

    for _ in range(4):
        index = random.randint(0, 5)
        while indicesUtilises[index] == 1:
            index = random.randint(0, 5)
        indicesUtilises[index] = 1
        voyelles.append(alphabet[index])

    return voyelles

def saisirVoyelle(i):
    while True:
        rep = input(f"Saisissez voyelle {i} (minuscule): ")
        if rep in ['a', 'e', 'i', 'o', 'u', 'y']:
            return rep

def comparerProposition(voyelles, propositions):
    for i in range(4):
        if propositions[i] == voyelles[i]:
            print("\nUne voyelle est correcte et bien placée")
        else:
            for j in range(4):
                if propositions[i] == voyelles[j] and i != j:
                    print("\nUne voyelle est correcte mais mal placée")
                    break

def mastermind():
    victoire = False
    voyelles = genererSequence()

    print("L'ordinateur a généré aléatoirement une suite de 4 voyelles.")
    print("Vous avez jusqu'à 10 essais pour retrouver cette suite.\n")

    for tentatives in range(10):
        propositions = [saisirVoyelle(i + 1) for i in range(4)]
        comparerProposition(voyelles, propositions)

        if propositions == voyelles:
            victoire = True
            break

    return tentatives + 1

def myst_coeff():
    return random.randint(1, 10)

def myst_suite(n, a, b, c):
    if n == 0:
        return c
    else:
        return a * myst_suite(n - 1, a, b, c) + b

def mystere():
    victoire = False
    random.seed(time.time())

    a, b, c = myst_coeff(), myst_coeff(), myst_coeff()
    termes = [myst_suite(i, a, b, c) for i in range(4)]

    print(f"Premiers termes de la suite: {termes[0]} {termes[1]} {termes[2]}")
    entree = int(input("Entrer le 4ème terme: "))

    debut = time.time()
    if entree == termes[3] and (time.time() - debut) <= 30:
        victoire = True

    score = (time.time() - debut) if victoire else 31
    return score

def cacher():
    n = random.randint(1, 1000)
    score = 0
    tentatives = 0
    correct = False

    phrases = [
        "lâche pas les études",
        "toujours aussi nul",
        "encore ça fait beaucoup là non ?",
        "aie coup dur pour guillaume",
        "T'es éclaté au sol !"
    ]

    print("Devinez un nombre entre 1 et 1000")

    while tentatives < 10:
        indice = random.randint(0, 4)
        tentatives += 1
        nbrutilisateurs = int(input(f"Tentative {tentatives} : "))

        if nbrutilisateurs < 1 or nbrutilisateurs > 1000:
            print("Le nombre doit être entre 1 et 1000. Réessayez.")
            print(phrases[indice])
        elif nbrutilisateurs < n:
            print("Le nombre à deviner est plus grand.")
            print(phrases[indice])
        elif nbrutilisateurs > n:
            print("Le nombre à deviner est plus petit.")
            print(phrases[indice])
        else:
            correct = True
            break

    score = tentatives if correct else 11
    return score

def jeu_gagne(score):
    print("\n")
    print("  ____                               _ ")
    print(" / ___| __ _  __ _ _ __   ___ _ __  | |")
    print("| |  _ / _` |/ _` | '_ \\ / _ \\ '__| | |")
    print("| |_| | (_| | (_| | | | |  __/ |    |_|")
    print(" \\____|\\__,_|\\__, |_| |_|\\___|_|    (_)")
    print("             |___/\n")
    print("\033[1;32m\n avec un score de {}\n\033[0m".format(score))

def jeu_perdu(score):
    print("\n")
    print("                    _         _ ")
    print(" _ __   ___ _ __ __| |_   _  | |")
    print("| '_ \\ / _ \\ '__/ _` | | | | | |")
    print("| |_) |  __/ | | (_| | |_| | |_|")
    print("| .__/ \\___|_|  \\__,_|\\__,_| (_)")
    print("|_|                              ")
    print("\n")
    print("\033[1;31m\nAie... Coup dur... Score: {}\n\033[0m".format(score))

def main():
    rejouer = True
    print("\n")
    print("  _     _                                      \n")
    print(" | |__ (_) ___ _ ____   _____ _ __  _   _  ___ \n")
    print(" | '_ \\| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| | | |/ _ \\\n")
    print(" | |_) | |  __/ | | \\ V /  __/ | | | |_| |  __/\n")
    print(" |_.__/|_|\\___|_| |_|\_/ \\___|_| |_|\\__,_|\\___|\n")
    print("\n")

    while rejouer:
        print("NOTRE SUPER JEU!!!1!\n"
              " 1 - Suite mystere\n"
              " 2 - Nombre cache\n"
              " 3 - Mastermind")

        numero_jeu = 0
        while numero_jeu < 1 or numero_jeu > 3:
            numero_jeu = int(input("Entrer le numero du jeu [1-3]: "))

        score = 0
        victoire = False

        if numero_jeu == 1:
            score = mystere()
        elif numero_jeu == 2:
            score = cacher()
        elif numero_jeu == 3:
            score = mastermind()

        if victoire:
            jeu_gagne(score)
        else:
            jeu_perdu(score)

        choix = ""
        while choix != 'o' and choix != 'n':
            choix = input("Voulez-vous rejouer ? (o/n)\n").lower()
            if choix == 'o':
                print("C'est parti, on rejoue !\n")
                rejouer = True
            elif choix == 'n':
                rejouer = False
            else:
                print("Saisie invalide. Veuillez choisir 'o' pour rejouer ou 'n' pour ne pas rejouer.\n")

if __name__ == "__main__":
    main()