from PyQt5.QtWidgets import QLineEdit
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QPushButton, QTextEdit, QLineEdit
import sys
from cache import CacheGame

class GameWindow(QWidget):
    def __init__(self):
        super().__init__() 

        self.initUI()

    def initUI(self):
        self.setWindowTitle("Jeux")
        self.setGeometry(100, 100, 400, 300)

        layout = QVBoxLayout()

        self.result_text = QTextEdit(self)
        self.result_text.setReadOnly(True)
        layout.addWidget(self.result_text)

        self.game_buttons = []

        self.cache_game = CacheGame()  

        # Champ de texte pour entrer le nombre
        self.input_field = QLineEdit(self)
        layout.addWidget(self.input_field)

        # Bouton pour soumettre le nombre
        submit_button = QPushButton("Soumettre", self)
        submit_button.clicked.connect(self.submit_number)
        layout.addWidget(submit_button)

        # Bouton pour chaque jeu 
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
                self.cache_game.tentatives = 0  # Réinitialise le jeu
                self.result_text.append(f"Vous avez lancé le jeu : {game_name}")
                self.result_text.append("Devinez un nombre entre 1 et 1000")
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

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = GameWindow()
    window.show()
    sys.exit(app.exec_())
