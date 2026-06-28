#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants
const int ROCK = 1;
const int PAPER = 2;
const int SCISSOR = 3;

// Prints the game menu
void printMenu() {
    cout << "\n========== ROCK PAPER SCISSORS ==========\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissor\n";
    cout << "=========================================\n";
    cout << "Enter your choice: ";
}

// Converts number to choice name
string getChoiceName(int choice) {
    if (choice == ROCK) return "Rock";
    if (choice == PAPER) return "Paper";
    return "Scissor";
}

// Generates random computer choice
int getComputerChoice() {
    return rand() % 3 + 1;
}

// Prints winner
void printResult(int userChoice, int computerChoice) {

    if (userChoice == computerChoice) {
        cout << "\n Match Tie!\n";
        return;
    }

    if ((userChoice == ROCK && computerChoice == SCISSOR) ||
        (userChoice == PAPER && computerChoice == ROCK) ||
        (userChoice == SCISSOR && computerChoice == PAPER)) {

        cout << "\n You Win!\n";
    }
    else {
        cout << "\n Computer Wins!\n";
    }
}

int main() {

    srand(time(NULL));

    int playAgain = 1;

    while (playAgain) {

        int userChoice;

        printMenu();
        cin >> userChoice;

        if (userChoice < 1 || userChoice > 3) {
            cout << "\n Invalid Choice!\n";
            continue;
        }

        int computerChoice = getComputerChoice();

        cout << "\nYou chose      : " << getChoiceName(userChoice) << endl;
        cout << "Computer chose : " << getChoiceName(computerChoice) << endl;

        printResult(userChoice, computerChoice);

        cout << "\nPlay Again?\n";
        cout << "1 -> Yes\n";
        cout << "0 -> No\n";
        cout << "Choice: ";

        cin >> playAgain;

        if (playAgain != 0 && playAgain != 1) {
            cout << "\nInvalid Input! Exiting...\n";
            break;
        }
    }

    cout << "\nThank You For Playing \n";

    return 0;
}