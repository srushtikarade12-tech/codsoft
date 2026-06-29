import math

board = [" " for _ in range(9)]


# Display the board
def print_board():
    print()
    print(board[0], "|", board[1], "|", board[2])
    print("--+---+--")
    print(board[3], "|", board[4], "|", board[5])
    print("--+---+--")
    print(board[6], "|", board[7], "|", board[8])
    print()


# Check winner
def check_winner(player):
    win_positions = [
        [0,1,2],[3,4,5],[6,7,8],
        [0,3,6],[1,4,7],[2,5,8],
        [0,4,8],[2,4,6]
    ]

    for position in win_positions:
        if all(board[i] == player for i in position):
            return True
    return False


# Check draw
def is_draw():
    return " " not in board


# Minimax Algorithm
def minimax(is_maximizing):

    if check_winner("O"):
        return 1

    if check_winner("X"):
        return -1

    if is_draw():
        return 0

    if is_maximizing:

        best_score = -math.inf

        for i in range(9):
            if board[i] == " ":
                board[i] = "O"
                score = minimax(False)
                board[i] = " "
                best_score = max(score, best_score)

        return best_score

    else:

        best_score = math.inf

        for i in range(9):
            if board[i] == " ":
                board[i] = "X"
                score = minimax(True)
                board[i] = " "
                best_score = min(score, best_score)

        return best_score


# AI Move
def ai_move():

    best_score = -math.inf
    move = -1

    for i in range(9):

        if board[i] == " ":

            board[i] = "O"

            score = minimax(False)

            board[i] = " "

            if score > best_score:
                best_score = score
                move = i

    board[move] = "O"


# Human Move
def human_move():

    while True:

        try:
            position = int(input("Enter position (1-9): ")) - 1

            if position < 0 or position > 8:
                print("Invalid Position!")
                continue

            if board[position] == " ":
                board[position] = "X"
                break
            else:
                print("Position already occupied!")

        except ValueError:
            print("Enter numbers only!")


# Main Game
print("======== TIC TAC TOE AI ========")
print("You are X")
print("Computer is O")

while True:

    print_board()

    human_move()

    if check_winner("X"):
        print_board()
        print("🎉 You Win!")
        break

    if is_draw():
        print_board()
        print("Game Draw!")
        break

    print("\nComputer is thinking...\n")

    ai_move()

    if check_winner("O"):
        print_board()
        print("🤖 Computer Wins!")
        break

    if is_draw():
        print_board()
        print("Game Draw!")
        break