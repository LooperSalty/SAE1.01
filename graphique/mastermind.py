import random
from PyQt5.QtWidgets import QInputDialog

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
        rep, ok = QInputDialog.getText(None, f'Saisissez voyelle {i}', f'Entrez une voyelle {i} (minuscule):')
        if ok and rep in ['a', 'e', 'i', 'o', 'u', 'y']:
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

def mastermind_play():
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
