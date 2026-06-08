import random

def display_board(board):
    print("+-------+-------+-------+")
    for row in board:
        print("|       |       |       |")
        print(f"|   {row[0]}   |   {row[1]}   |   {row[2]}   |")
        print("|       |       |       |")
        print("+-------+-------+-------+")

def enter_move(board):
    while True:
        try:
            move = int(input("Jouw beurt, kies een vak: "))
            if 1 <= move <= 9:
                row = (move - 1) // 3 #geeft de rij door het gehele getal van de deling te geven
                col = (move - 1) % 3 #geeft de kolum door de rest van een deling te geven
                if board[row][col] not in ['X', 'O']: #controleert of het vakje nog vrij is
                    board[row][col] = 'O' #als vakje vrij is, wordt er een O neer gezet
                    break
                else:
                    print("Dit vak is al gekozen, kies een ander vak!")
            else:
                print("Fout, kies een getal tussen 1 en 9")
        except ValueError:
            print("Fout, kies een getal.")

def make_list_of_free_fields(board): #geeft aan de computer terug welke vakjes nog vrij zijn
    free_fields = []
    for row in range(3):
        for col in range(3):
            if board[row][col] not in ['X', 'O']:
                free_fields.append((row, col))
    return free_fields

def victory_for(board, sign):
    
    for row in board:
        if all(s == sign for s in row): #loopt door elke rij van het bord en controleert of alle elementen gelijk zijn
            return True

    for col in range(3):
        if all(board[row][col] == sign for row in range(3)): #er zijn 3 kollommen en er wordt 1 kolom tegelijk gecontroleerd
            return True

    if all(board[i][i] == sign for i in range(3)) or all(board[i][2 - i] == sign for i in range(3)): #kolom wordt berekend als 2 - i, zodat het van rechts naar links gaat
            return True

    

    return False


def draw_move(board):
    free_fields = make_list_of_free_fields(board) #roept de lijst van de vrije vakken op
    if free_fields:
        row, col = random.choice(free_fields) 
        board[row][col] = 'X'

def main():
    board = [[1, 2, 3],
             [4, 'X', 6],
             [7, 8, 9]]

    print("Welkom bij Tic-Tac-Toe!")
    display_board(board)

    while True:
        enter_move(board)
        display_board(board)
        if victory_for(board, 'O'):
            print("Je hebt gewonnen!")
            break
        if not make_list_of_free_fields(board):
            print("Het is gelijk spel!")
            break

        print("De beurt van de computer")
        draw_move(board)
        display_board(board)
        if victory_for(board, 'X'):
            print("Computer heeft gewonnen!")
            break
        if not make_list_of_free_fields(board):
            print("Het is gelijkspel!")
            break

if __name__ == "__main__":
    main()
