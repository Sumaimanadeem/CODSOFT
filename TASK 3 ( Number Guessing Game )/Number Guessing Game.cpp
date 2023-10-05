#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    
    srand(time(0));

    cout << "\n\t\t\tWelcome to GuessTheNumber game!" << endl;
    cout << "You have to guess a number between 1 and 100. "
            "You'll have limited choices based on the "
            "level you choose. Good Luck!" << endl;

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "1 for easy!\t";
        cout << "2 for medium!\t";
        cout << "3 for difficult!\t";
        cout << "0 for ending the game!\n" << endl;

        int difficultyChoice;
        cout << "Enter the number: ";
        cin >> difficultyChoice;

        int secretNumber = 1 + (rand() % 100);
        int playerChoice;
        int choicesLeft;
        int attempts = 0;

        
        switch (difficultyChoice) {
            case 1:
                choicesLeft = 10;
                break;
            case 2:
                choicesLeft = 7;
                break;
            case 3:
                choicesLeft = 5;
                break;
            case 0:
                exit(0); 
            default:
                cout << "Wrong choice, Enter a valid choice to play the game! (0, 1, 2, 3)" << endl;
                continue; 
        }

        
        while (choicesLeft > 0) {
            cout << "\n\nEnter your guess: ";
            cin >> playerChoice;
            attempts++;

            if (playerChoice == secretNumber) {
                cout << "Congratulations! You guessed the correct number (" << playerChoice << ") in " << attempts << " attempts!" << endl;
                break;
            } else if (playerChoice > secretNumber) {
                cout << "Nope, " << playerChoice << " is too high. Try again." << endl;
            } else {
                cout << "Nope, " << playerChoice << " is too low. Try again." << endl;
            }

            choicesLeft--;
            cout << "You have " << choicesLeft << " choices left." << endl;

            if (choicesLeft == 0) {
                cout << "You couldn't find the secret number. It was " << secretNumber << ". You lose!" << endl;
            }
        }

        // Ask if the user wants to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}
