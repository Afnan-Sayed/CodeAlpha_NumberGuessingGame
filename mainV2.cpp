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
    if (score < 5)
    {
        cout << "Once your score is 5, additional hints will be available for you!\n";
    }
    else
    {
        if (numberToBeGuessed % 2 == 0) {
            cout << "Hint: The number is even.\n";
        }
        else {
            cout << "Hint: The number is odd.\n";
        }
    }
}

// Function to inform player about number of tries to take care
void numOfTriesUpdate(int & numOfTries)
{
    numOfTries ++;
    if (numOfTries <= 5){
        cout << "Number of tries now is: " << numOfTries << "\n";
    }
    else
    {
        cout << "Warning ...\n"
                "Take care! Number of tries now is: " << numOfTries << "\n";
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

        int numberGuessedByUser;
        int numOfTries = 0;

        // Check if the guessed number is correct or provide hints until getting the correct guess
        while (numOfTries<10) {
            cout << "Guess the number:\n";
            cin >> numberGuessedByUser;
            checkInputValidity();

            int differenceAway = abs(numberToBeGuessed - numberGuessedByUser);

            if (score >= 5)
            {
                if (differenceAway <= 10 && differenceAway >= 1) {
                    cout << "Almost there! You're just " << differenceAway << " away from the target! Try again.\n";
                    numOfTriesUpdate(numOfTries);
                }
            }
            else if (differenceAway <= 5 && differenceAway >= 1)
            {
                cout << "Almost there! You're just " << differenceAway << " away from the target! Try again.\n";
                numOfTriesUpdate(numOfTries);
            }

            else if (numberGuessedByUser > numberToBeGuessed) {
                cout << "Too high! Try again with a lower number.\n";
                numOfTriesUpdate(numOfTries);
            }
            else if (numberGuessedByUser < numberToBeGuessed) {
                cout << "Too low! Try again with a higher number.\n";
                numOfTriesUpdate(numOfTries);
            }
            else if (numberToBeGuessed == numberGuessedByUser) {
                score++;
                numOfTries = 0;
                cout << "Hurray! You got it right! Your score now is " << score << ".\n";
                cout << "Do you want to continue and have a chance to increase your score? \n"
                        "Press 1 to continue or 0 to close \n";
                cin >> continueGame;
                if (!continueGame) {
                    cout << "Hope you enjoyed! \n"
                            "Exiting...";
                }
                else {
                    cout << "Let's play again, then ...\n";
                }
            break;
            }
            if (numOfTries >= 10)
            {
                cout << "You exceeded the possible number of tries \n";
                cout << "Do you want to continue with another new challenge? Press 1 for a new challenge or 0 to close:\n";
                cin >> continueGame;
                if (!continueGame) {
                    cout << "Hope you enjoyed! Exiting...\n";
                }
                else {
                    cout << "Let's play again, then ...\n";
                }
                break;
            }

        }
    }
    return 0;
}

