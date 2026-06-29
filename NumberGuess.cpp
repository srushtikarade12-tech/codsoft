#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class NumberGuessingGame
{
private:
    int randomNumber;
    int maxRange;
    int maxAttempts;
    int score;

public:
    NumberGuessingGame()
    {
        srand((unsigned)time(0));
        score = 100;
    }

    void clearInput()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void displayTitle()
    {
        cout << "\n=============================================\n";
        cout << "        NUMBER GUESSING GAME\n";
        cout << "=============================================\n";
    }

    void chooseDifficulty()
    {
        int choice;

        cout << "\nChoose Difficulty\n";
        cout << "1. Easy (1 - 50, 10 Attempts)\n";
        cout << "2. Medium (1 - 100, 7 Attempts)\n";
        cout << "3. Hard (1 - 200, 5 Attempts)\n";
        cout << "Enter Choice : ";

        while (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cout << "Invalid Choice! Enter Again : ";
            clearInput();
        }

        switch (choice)
        {
        case 1:
            maxRange = 50;
            maxAttempts = 10;
            break;

        case 2:
            maxRange = 100;
            maxAttempts = 7;
            break;

        case 3:
            maxRange = 200;
            maxAttempts = 5;
            break;
        }

        randomNumber = rand() % maxRange + 1;
    }

    void play()
    {
        displayTitle();
        chooseDifficulty();

        int guess;
        int attempts = 0;
        score = 100;

        cout << "\nGuess a number between 1 and " << maxRange << endl;

        while (attempts < maxAttempts)
        {
            cout << "\nAttempt "
                 << attempts + 1
                 << " of "
                 << maxAttempts
                 << "\nEnter Guess : ";

            while (!(cin >> guess))
            {
                cout << "Enter Valid Number : ";
                clearInput();
            }

            attempts++;

            if (guess == randomNumber)
            {
                cout << "\nCongratulations!\n";
                cout << "You guessed the correct number.\n";
                cout << "Attempts Used : " << attempts << endl;
                cout << "Final Score : " << score << endl;
                return;
            }

            else if (guess < randomNumber)
            {
                cout << "Too Low!\n";
            }

            else
            {
                cout << "Too High!\n";
            }

            score -= 10;

            if (score < 0)
                score = 0;
        }

        cout << "\nGame Over!\n";
        cout << "Correct Number was : " << randomNumber << endl;
    }
};

int main()
{
    char choice;

    do
    {
        NumberGuessingGame game;
        game.play();

        cout << "\nPlay Again? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "\n====================================\n";
    cout << " Thank You For Playing!\n";
    cout << "====================================\n";

    return 0;
}