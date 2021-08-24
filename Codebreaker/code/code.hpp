#include <iostream>
#include <vector>
using namespace std;

class Code {
    private:
        vector<char> key;
        vector<char> selections;
    public:
        Code();
        Code(int length);
        void printKey();
        void printSelections();
        vector<char> getKey();
        vector<char> getSelections();
        void setKey(string newKey);
};