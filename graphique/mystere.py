
import random
import time

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

