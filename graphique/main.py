#!/usr/bin/env python3
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QTextEdit, QPushButton, QLineEdit, QInputDialog
from PyQt5.QtCore import QTimer
import sys
from mastermind import mastermind_play
from mystere import mystere
from cache import CacheGame
import random

class GameWindow(QWidget):
    def __init__(self):
      super().__init__()
      self.initUI()
      self.cache_game = None
      self.mystere_timer = QTimer()
      self.mystere_timer.timeout.connect(self.check_mystere)
        
    def initUI(self):
        self.setWindowTitle("Jeux")
        self.setGeometry(100, 100, 400, 300)

        layout = QVBoxLayout()

        self.result_text = QTextEdit(self)
        self.result_text.setReadOnly(True)
        layout.addWidget(self.result_text)

        self.game_buttons = []

        self.input_field = QLineEdit(self)
        layout.addWidget(self.input_field)

        submit_button = QPushButton("Soumettre", self)
        submit_button.clicked.connect(self.submit_number)
        layout.addWidget(submit_button)

        for game_name in ["Suite mystère", "Nombre caché", "Mastermind"]:
            button = QPushButton(game_name, self)
            button.clicked.connect(self.run_game)
            layout.addWidget(button)
            self.game_buttons.append(button)

        self.setLayout(layout)

    def run_game(self):
        sender = self.sender()
        if sender in self.game_buttons:
            game_name = sender.text()
            self.result_text.clear()
            if game_name == "Nombre caché":
                self.cache_game = CacheGame()
                self.result_text.append(f"Vous avez lancé le jeu : {game_name}")
                self.result_text.append("Devinez un nombre entre 1 et 1000")
            elif game_name == "Mastermind":
                self.play_mastermind()
            elif game_name == "Suite mystère":
                self.play_mystere()
            else:
                self.result_text.append(f"Vous avez lancé le jeu : {game_name}")

    def play_mastermind(self):
        self.result_text.append("Vous avez lancé le jeu : Mastermind")
        self.result_text.append("Vous devez deviner une suite de 4 voyelles.")
        self.result_text.append("Les voyelles possibles sont : a, e, i, o, u, y.")
        self.result_text.append("Vous avez jusqu'à 10 essais pour retrouver la suite.")

        tentatives = mastermind_play()

        if tentatives <= 10:
            self.result_text.append(f"Bravo, vous avez trouvé la suite en {tentatives} essais!")
        else:
            self.result_text.append("Désolé, vous n'avez pas trouvé la suite en 10 essais.")

    def submit_number(self):
        user_input = self.input_field.text()
        if user_input.isdigit() and self.cache_game:
            number = int(user_input)
            result = self.cache_game.guess_number(number)
            self.result_text.append(result)
        else:
            self.result_text.append("Veuillez entrer un nombre valide ou sélectionner le jeu Nombre caché.")
            
    def play_mystere(self):
        a, b, c = self.myst_coeff(), self.myst_coeff(), self.myst_coeff()
        termes = [self.myst_suite(i, a, b, c) for i in range(4)]

        self.result_text.append(f"Premiers termes de la suite: {termes[0]} {termes[1]} {termes[2]}")

        self.mystere_value = termes[3]

        self.mystere_timer.start(30000)

        user_input, ok = QInputDialog.getInt(self, "Suite Mystère", "Entrez le 4ème terme de la suite:")

        if ok:
            if user_input == self.mystere_value:
                self.result_text.append("Bravo, vous avez résolu le mystère en temps!")
            else:
                self.result_text.append("Désolé, le temps est écoulé ou la réponse est incorrecte.")
        else:
            self.result_text.append("Vous n'avez pas saisi de valeur valide.")

      
        self.input_field.setDisabled(False)
       

    def myst_coeff(self):
        return random.randint(1, 10)

    def myst_suite(self, n, a, b, c):
        if n == 0:
            return c
        else:
            return a * self.myst_suite(n - 1, a, b, c) + b

    def check_mystere(self):
        self.mystere_timer.stop()
        user_input, ok = QInputDialog.getInt(self, "Suite Mystère", "Entrez le 4ème terme de la suite:")

        if ok and user_input == self.mystere_value:
            self.result_text.append("Bravo, vous avez résolu le mystère en temps!")
        else:
            self.result_text.append("Désolé, le temps est écoulé ou la réponse est incorrecte.")

      
        self.input_field.setDisabled(False)
                
    

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = GameWindow()
    window.show()
    sys.exit(app.exec_())
