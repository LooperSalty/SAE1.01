# mastermind.py
import random
from PyQt5.QtWidgets import QPushButton

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

def mastermind_play(self):
    def saisirVoyelle(i):
        while True:
            rep = input(f"Saisissez voyelle {i} (minuscule): ")
            if rep in ['a', 'e', 'i', 'o', 'u', 'y']:
                return rep

    victoire = False
    voyelles = genererSequence()
    tentatives = 0

    for tentatives in range(10):
        propositions = [saisirVoyelle(i + 1) for i in range(4)]
        comparerProposition(voyelles, propositions)

        if propositions == voyelles:
            victoire = True
            break

    return tentatives + 1

