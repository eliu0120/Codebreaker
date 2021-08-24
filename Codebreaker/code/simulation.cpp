#include <iostream>
#include <vector>
#include <string>
#include "code.hpp"
#include "board.hpp"
#include "simulation.hpp"
using namespace std;

void Simulation::game(int codeLength) {
    // Initialize variables for function
    Board b(codeLength);
    Code c(codeLength);
    double row = 1;
    int maxTurn = codeLength + (codeLength - 2);
    char response = 0;

    // Display board
    b.displayBoard();

    // Gameplay loop
    while (!b.getIsDecrypted() && row <= maxTurn) {

        // Print char selections
        cout << "\n";
        c.printSelections();

        // Ask player for input of all chars
        for (double column = 1; column <= codeLength; column++) {
            cout << "\nInput char for column " << column << ":\n";
            while (1 == 1) {
                cin >> response;
                if (b.checkInput(response, c)) {
                    b.setBoard(response, row, column);
                    b.setBoard(b.checkCode(c, row, column), row + 0.5, column);
                    break;
                }
                cout << "Error, please input again\n";
            }
        }

        // Display board again
        system("cls");
        b.displayBoard();
        b.checkDecryption(row);
        row++;
    }

    // Display results
    if (b.getIsDecrypted()) {
        cout << "\nCongratulations! You cracked the code!\n";
    } else {
        cout << "\nOut of turns! Game over!\n";
        c.printKey();
    }
    cout << "Input any char to continue!\n";
    cin >> response;

    // Play again?
    system("cls");
    cout << "Play again? (Y/N)\n";
    cin >> response;
    system("cls");
    if (toupper(response) == 'Y')
        Simulation::game(codeLength);
}