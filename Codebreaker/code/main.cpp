#include <iostream>
#include <vector>
#include "code.hpp"
#include "board.hpp"
#include "simulation.hpp"
using namespace std;

int main() {
    /* TEST CODE
    Code c1(3);
    Code c2(4);
    Code c3(5);
    Code c4(6);

    c1.printSelections();
    c2.printSelections();
    c3.printSelections();
    c4.printSelections();
    cout << "\n";

    c1.printKey();
    c2.printKey();
    c3.printKey();
    c4.printKey();
    cout << "\n";

    Board b1(3);
    Board b2(4);
    Board b3(5);
    Board b4(6);
    b1.displayBoard();
    cout << "\n";
    b2.displayBoard();
    cout << "\n";
    b3.displayBoard();
    cout << "\n";
    b4.displayBoard();
    cout << "\n";

    cout << b1.getIsDecrypted() << "\n";

    for (int i = 0; i < c1.getSelections().size(); i++)
        cout << c1.getSelections()[i];
    cout << "\n" << b1.checkInput('j', c1) << "\n\n";
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 4; j++)
            b1.setBoard('a', i, j);
    b1.setBoard('b', 2, 2);
    b1.setBoard('C', 9, 6);
    b1.displayBoard();

    b1.setBoard('a', 1, 1);
    b1.setBoard('G', 1, 2);
    b1.setBoard('C', 1, 3);
    b1.setBoard('E', 1, 4);
    b1.setBoard('D', 1, 5);
    b1.setBoard('H', 1, 6);
    c1.setKey("ABCDEF");
    for (int i = 1; i <= 6; i++)
        b1.setBoard(b1.checkCode(c1, 1, i), 1.5, i);
    b1.checkDecryption(1);
    cout << b1.getIsDecrypted() << "\n\n";
    b1.setBoard('a', 2, 1);
    b1.setBoard('b', 2, 2);
    b1.setBoard('C', 2, 3);
    b1.setBoard('d', 2, 4);
    b1.setBoard('e', 2, 5);
    b1.setBoard('f', 2, 6);
    for (int i = 1; i <= 6; i++)
        b1.setBoard(b1.checkCode(c1, 2, i), 2.5, i);
    b1.displayBoard();
    b1.checkDecryption(2);
    cout << "\n\n" << b1.getIsDecrypted();
    */

    // Resposne char for cin
    char response = '0';

    // Game menu
    while (1 == 1) {
        // Title card
        cout << "CODEBREAKER\n\n\n\n\n1) Play\n2) Quit\n";
        cin >> response;

        // Select game mode
        if (response == '1') {
            system("cls");
            cout << "Instructions:\nGuess the code from the selection of chars given.\nYou only have a certain amount of tries displayed in the board.\nY - correct char, O - incorrect place for char, X - incorrect char.\nEach char is only used once.\nInput anything to continue.\n";
            cin >> response;
            system("cls");
            cout << "Select game mode:\n\n1) 3 char code\n2) 4 char code\n3) 5 char code\n4) 6 char code\n5) Return to title screen\n";
            cin >> response;
            if (response == '1') {
                system("cls");
                Simulation::game(3);
            } else if (response == '2') {
                system("cls");
                Simulation::game(4);
            } else if (response == '3') {
                system("cls");
                Simulation::game(5);
            } else if (response == '4') {
                system("cls");
                Simulation::game(6);
            } else
                system("cls");
        } else
            return 0;
    }
}