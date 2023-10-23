import random
from PyQt5.QtCore import pyqtSignal

class CacheGame:
    game_over_signal = pyqtSignal(int)

    def __init__(self):
        self.n = random.randint(1, 1000)
        self.score = 0
        self.tentatives = 0
        self.correct = False
        self.phrases = [
            "lâche pas les études",
            "toujours aussi nul",
            "encore ça fait beaucoup là non ?",
            "aie coup dur pour guillaume",
            "T'es éclaté au sol!"
        ]

    def guess_number(self, nbrutilisateurs):
        self.tentatives += 1

        if nbrutilisateurs < 1 or nbrutilisateurs > 1000:
            return f"Le nombre doit être entre 1 et 1000. Réessayez.\n{self.phrases[random.randint(0, 4)]}"
        elif nbrutilisateurs < self.n:
            return f"Le nombre à deviner est plus grand.\n{self.phrases[random.randint(0, 4)]}"
        elif nbrutilisateurs > self.n:
            return f"Le nombre à deviner est plus petit.\n{self.phrases[random.randint(0, 4)]}"
        else:
            self.correct = True
            return "Vous avez deviné le nombre !"


    def play_game(self, nbrutilisateurs):
        if not self.correct and self.tentatives < 10:
            result = self.guess_number(nbrutilisateurs)
            if self.correct:
                self.score = self.tentatives
                self.game_over_signal.emit(self.score)
            return result

        return "Le jeu est terminé. Votre score est : {self.score}"

if __name__ == "__main__":
    cache_game = CacheGame()
    while not cache_game.correct and cache_game.tentatives < 10:
        try:
            nbrutilisateurs = int(input(f"Tentative {cache_game.tentatives + 1} : "))
            result = cache_game.play_game(nbrutilisateurs)
            print(result)
        except ValueError:
            print("Veuillez entrer un nombre valide.")