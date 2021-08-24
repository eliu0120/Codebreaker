#include <iostream>
#include <vector>
#include <string>
#include "code.hpp"
#include "board.hpp"
using namespace std;

// Default constructor
Board::Board() {
    board.push_back("A");
    isDecrypted = false;
}

// Constructor
Board::Board(int codeLength) {
    isDecrypted = false;

    // Generate board parameters
    int rows = 0, &columns = codeLength;
    if (codeLength == 3)
        rows = 4;
    else if (codeLength == 4)
        rows = 6;
    else if (codeLength == 5)
        rows = 8;
    else if (codeLength == 6)
        rows = 10;

    // Create top of board
    string rowString = "X|";
    for (int i = 1; i <= columns; i++)
        rowString.append(to_string(i) + "|");
    board.push_back(rowString);

    // Create each row of board
    for (int i = 1; i <= rows; i++) {
        // Add rows player will input into
        if (i != 10)
            rowString = to_string(i) + "|";
        else
            rowString = "0|";
        for (int j = 1; j <= columns; j++)
            rowString.append(" |");
        board.push_back(rowString);

        // Add row which will display results
        rowString = " |";
        for (int j = 1; j <= columns; j++)
            rowString.append(" |");
        board.push_back(rowString);
    }
}

// Check input from player if it input is part of selections
bool Board::checkInput(char input, Code code) {
    for (int i = 0; i < code.getSelections().size(); i++)
        if (toupper(input) == code.getSelections()[i])
            return true;
    return false;
}

// Check if input matches code
char Board::checkCode(Code code, int row, int column) {
    column *= 2;
    row = 2 * row - 1;
    for (int i = 0; i < code.getKey().size(); i++) 
        if (board[row][column] == code.getKey()[i])
            if (column / 2 == i + 1)
                return 'Y';
            else
                return 'O';
    return 'X';
}

// Check if code has been decrypted
void Board::checkDecryption(int row) {
    isDecrypted = true;
    for (int i = 2; i < board[row * 2].size(); i += 2)
        if (board[row * 2][i] != 'Y') {
            isDecrypted = false;
            break;
        }
}

// Print board
void Board::displayBoard() {
    for (int i = 0; i < board.size(); i++)
        cout << board[i] << "\n";
}

// Get decryption bool
bool Board::getIsDecrypted() {
    return isDecrypted;
}

// Enters player input onto board
void Board::setBoard(char input, double row, double column) {
    column *= 2;
    row = 2 * row - 1;
    board[row][column] = toupper(input);
}