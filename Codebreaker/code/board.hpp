#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Board {
    private:
        vector<string> board;
        bool isDecrypted;
    public:
        Board();
        Board(int codeLength);
        bool checkInput(char input, Code code);
        char checkCode(Code code, int row, int column);
        void checkDecryption(int row);
        void displayBoard();        
        bool getIsDecrypted();
        void setBoard(char input, double row, double column);
};