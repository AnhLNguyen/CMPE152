#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "token.h"
#include <stack>
using namespace std;

class LexicalAnalyzer{
    int size;
    public:
        LexicalAnalyzer();
        vector<Token> acceptedToken;
        vector<Token> getNextToken();
        void ReadFile();
        void printOut();
        bool isSymbol(char);
        bool isOperator(string);
        vector<char> fileBuffer;
};

LexicalAnalyzer::LexicalAnalyzer()
{

}

void LexicalAnalyzer::ReadFile() {
    //Scan all the character 
    ifstream inStream;
    char c;
    inStream.open("testInput.txt");
    if (!inStream.is_open() || inStream.fail()){ //Prompt error when cannot read the file
        cout << "File is not available.\n" ;
        exit(1);
    }
    else
        cout << "Success\n";
    
    while(inStream.get(c)) {
        //Push all the characters into fileBuffer vector to handle it later
        fileBuffer.push_back(c);
    }

    inStream.close();

    for(int i=0; i<fileBuffer.size(); i++) {
        cout << fileBuffer[i];
    }
    cout << endl;
}

//stream input file to characters function (getNextToken)
vector<Token> LexicalAnalyzer::getNextToken(){
    
    
    return acceptedToken;
}

//Check is the input character a symbol or not
bool LexicalAnalyzer::isSymbol(char c){
    if (c == '{' || c == '}' || c == '(' || c == ')' ||
        c == '<' || c == '>' || c == '+' || c == '-' ||
        c == '*' || c == '/' || c == '=' || c == '!' ||
        c == '\t'|| c == '\n'|| c == '"' || c == ';' ||
        c == '\''|| c == ' ') 
        return true;
    else 
        return false;
}

//Conditional Statements
bool LexicalAnalyzer::isOperator(string s)
{
    if(s == "&&" || s == "||" || s == "==" || s == "!=" || s == "<=" || s == ">=" || s == "+"  || s == "-"  || s == "*"  || s == "/"  || s == "<"  || s == ">")
    {
        cout << "Operator:  " << s << endl;
        return true;
    }else
        return false;
}

void LexicalAnalyzer::printOut(){
    int vectorSize = acceptedToken.size();
    for (int i =1; i< vectorSize;i++){
        cout << acceptedToken[i].lexer << '\t' << acceptedToken[i].tokenValue << endl;
    }
}

int main(int syntax, char** error){
    LexicalAnalyzer Lex;
    Lex.ReadFile();

    return 0;
}