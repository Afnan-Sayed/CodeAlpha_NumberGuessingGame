#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function for input validation to check if the input is a valid integer
void checkInputValidity() {
    if (cin.fail()) {
        cout << "Invalid input! Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to provide hints based on the guessed number
void provideHint(int numberToBeGuessed, int score) {
    if (score >= 5) {
        if (numberToBeGuessed % 2 == 0) {
            cout << "Hint: The number is even.\n";
        } else {
            cout << "Hint: The number is odd.\n";
        }
    }
}

int main() {
    cout << "Welcome! Are you ready? Let's start...\n";

    int score = 0;
    bool continueGame = true;
    srand(time(nullptr));

    // Loop until the user chooses to stop playing
    while (continueGame) {
        int difficultyLevel;
        int numberToBeGuessed;

        // Choose the difficulty level and generate the number to be guessed
        while (true) {
            cout << "Choose the difficulty level:\n"
                 << "Press 1 for Easy mode (1-100)\n"
                 << "Press 2 for Medium mode (1-500)\n"
                 << "Press 3 for Hard mode (1-1000)\n";
            cin >> difficultyLevel;
            checkInputValidity();

            switch (difficultyLevel) {
                case 1:
                    numberToBeGuessed = rand() % 100 + 1;
                    break;
                case 2:
                    numberToBeGuessed = rand() % 500 + 1;
                    break;
                case 3:
                    numberToBeGuessed = rand() % 1000 + 1;
                    break;
                default:
                    cout << "Invalid difficulty level! Try again.\n";
                    continue;
            }
            break;
        }

        provideHint(numberToBeGuessed, score);

        cout << "Guess the number:\n";
        int numberGuessedByUser;

        // Check if the guessed number is correct or provide hints until getting the correct guess
        while (true) {
            cin >> numberGuessedByUser;
            checkInputValidity();

            int differenceAway = abs(numberToBeGuessed - numberGuessedByUser);

            if (score >= 5) {
                if (differenceAway <= 10 && differenceAway >= 1) {
                    cout << "Almost there! You're just " << differenceAway << " away from the target! Try again.\n";
                }
            } else if (differenceAway <= 5 && differenceAway >= 1) {
                cout << "Almost there! You're just " << differenceAway << " away from the target! Try again.\n";
            } else if (numberGuessedByUser > numberToBeGuessed) {
                cout << "Too high! Try again with a lower number.\n";
            } else if (numberGuessedByUser < numberToBeGuessed) {
                cout << "Too low! Try again with a higher number.\n";
            } else if (numberToBeGuessed == numberGuessedByUser) {
                score++;
                cout << "Hurray! You got it right! Your score now is " << score << ".\n";
                if (score < 5) {
                    cout << "Once your score is 5, additional hints will be available for you!\n";
                }
                cout << "Do you want to continue with another challenge? Press 1 for another challenge or 0 to close:\n";
                cin >> continueGame;
                if (!continueGame) {
                    cout << "Hope you enjoyed! Exiting...\n";
                } else {
                    cout << "Let's play again, then ...\n";
                }
                break;
            }
        }
    }
    return 0;
}
