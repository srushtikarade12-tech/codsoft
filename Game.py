import random

choices = ["rock", "paper", "scissors"]

user_score = 0
computer_score = 0

while True:

    print("\nRock Paper Scissors")
    user = input("Enter rock/paper/scissors: ").lower()

    if user not in choices:
        print("Invalid Input")
        continue

    computer = random.choice(choices)

    print("Computer:", computer)

    if user == computer:
        print("Match Draw")

    elif (user == "rock" and computer == "scissors") or \
         (user == "paper" and computer == "rock") or \
         (user == "scissors" and computer == "paper"):

        print("You Win")
        user_score += 1

    else:
        print("Computer Wins")
        computer_score += 1

    print("\nScore")
    print("You :", user_score)
    print("Computer :", computer_score)

    again = input("\nPlay Again? (yes/no): ").lower()

    if again != "yes":
        break

print("\nFinal Score")
print("You :", user_score)
print("Computer :", computer_score)

print("Thanks for Playing!")