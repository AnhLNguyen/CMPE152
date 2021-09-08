#include <iostream>
#include <string>
#include <vector>

class LexicalAnalyzer{
    public:
        LexicalAnalyzer();
        void printOut();
        bool isSymbol(char c);
        int size;
};