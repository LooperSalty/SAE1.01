from PyQt5.QtWidgets import QLineEdit
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QPushButton, QTextEdit, QLineEdit
from PyQt5.QtCore import QObject, pyqtSignal
import sys
from cache import CacheGame
from mastermind import mastermind_play
from mystere import mystere


class GameWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

        self.cache_game = CacheGame()

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
                self.cache_game.tentatives = 0
                self.result_text.append(f"Vous avez lancé le jeu : {game_name}")
                self.result_text.append("Devinez un nombre entre 1 et 1000")
            elif game_name == "Mastermind":
                self.play_mastermind()
            elif game_name == "Suite mystère":
                self.play_mystere()
            else:
                self.result_text.append(f"Vous avez lancé le jeu : {game_name}")
                

    def submit_number(self):
        user_input = self.input_field.text()
        if user_input.isdigit():
            number = int(user_input)
            result = self.cache_game.guess_number(number)
            self.result_text.append(result)
        else:
            self.result_text.append("Veuillez entrer un nombre valide.")

    def play_mastermind(self):
        self.result_text.append("Vous avez lancé le jeu : Mastermind")
        self.result_text.append("Vous devez deviner une suite de 4 voyelles.")
        self.result_text.append("Les voyelles possibles sont : a, e, i, o, u, y.")
        self.result_text.append("Vous avez jusqu'à 10 essais pour retrouver la suite.")

        tentatives = mastermind_play(self)

        if tentatives <= 10:
            self.result_text.append(f"Bravo, vous avez trouvé la suite en {tentatives} essais!")
        else:
            self.result_text.append("Désolé, vous n'avez pas trouvé la suite en 10 essais.")
            
     
    def play_mystere(self):
        self.result_text.append("Vous avez lancé le jeu : Mystère")
        self.result_text.append("Vous devez résoudre le mystère de la suite de nombres.")
        self.result_text.append("Entrez le 4ème terme de la suite dans les 30 secondes.")

        score = mystere()

        if score <= 30:
            self.result_text.append(f"Bravo, vous avez résolu le mystère en {score} secondes!")
        else:
            self.result_text.append("Désolé, le temps est écoulé ou la réponse est incorrecte.")

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = GameWindow()
    window.show()
    sys.exit(app.exec_())
