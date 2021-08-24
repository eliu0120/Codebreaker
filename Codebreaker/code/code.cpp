#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "code.hpp"
using namespace std;

// Default constructor
Code::Code() {
    key.push_back('A');
    selections.push_back('A');
}

// Constructor
Code::Code(int length) {

    // Create selection of chars player can use
    if (length >= 3) {
        selections.push_back('A');
        selections.push_back('B');
        selections.push_back('C');
        selections.push_back('D');
    }
    if (length >= 4) {
        selections.push_back('E');
        selections.push_back('F');
    }
    if (length >= 5) {
        selections.push_back('G');
        selections.push_back('H');
    }
    if (length == 6) {
        selections.push_back('I');
        selections.push_back('J');
    }

    // Create key to puzzle
    key = selections;
    srand(time(0));
    for (int i = 0; i < 50; i++) {
        int pos1 = rand() % key.size(), pos2 = rand() % key.size();
        char storage = key[pos1];
        key[pos1] = key[pos2];
        key[pos2] = storage;
    }
    key.erase(key.begin() + length, key.begin() + selections.size());
}

// Print key to puzzle
void Code::printKey() {
    cout << "Key: ";
    for (int i = 0; i < key.size(); i++) {
        cout << key[i];
        if (i + 1 < key.size())
            cout << " ";
    }
    cout << "\n";
}

// Print seleciton of chars player can use
void Code::printSelections() {
    cout << "Character selections: ";
    for (int i = 0; i < selections.size(); i++) {
        cout << selections[i];
        if (i + 1 < selections.size())
            cout << ", ";
    }
    cout << "\n";
}

// Getter functions
vector<char> Code::getKey() {
    return key;
}

vector<char> Code::getSelections() {
    return selections;
}

// Setter functions (testing purposes only)
void Code::setKey(string newKey) {
    for (int i = 0; i < newKey.size(); i++)
        key[i] = newKey[i];
}