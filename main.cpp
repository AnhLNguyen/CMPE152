#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "token.h"
#include <stack>
using namespace std;

class LexicalAnalyzer{
    public:
        LexicalAnalyzer();
        vector<Token> acceptedToken;
        vector<Token> getNextToken();
        void printOut();
        bool isSymbol(char c);
        bool isOperator(string s);
        vector<char> fileBuffer;
        int size;
};

//Check is the input character a symbol or not
bool LexicalAnalyzer::isSymbol(char c){
    if (c == '{' or c == '}' or c == '(' or c == ')' or
        c == '<' or c == '>' or c == '+' or c == '-' or
        c == '*' or c == '/' or c == '=' or c == '!' or
        c == '\t'or c == '\n'or c == '"' or c == ';' or
        c == '\''or c == isspace(c)) 
        return true;
    else 
        return false;
}

//stream input file to characters function (getNextToken)
vector<Token> LexicalAnalyzer::getNextToken()
{
    //Scan all the character 
    ifstream inStream;
    char c;
    inStream.open("testInput.txt");
    if (!inStream.is_open() or inStream.fail()){ //Prompt error when cannot read the file
        cout << "File is not available.\n" ;
        exit(1);
    }
    else
        cout << "Success\n";
    
    while(inStream.get(c)) //Push all the characters into fileBuffer vector to handle it later
        fileBuffer.push_back(c);

    inStream.close();
    
    return acceptedToken;
}

void LexicalAnalyzer::printOut(){
    int vectorSize = acceptedToken.size();
    for (int i =1; i< vectorSize;i++){
        cout << acceptedToken[i].lexer << '\t' << acceptedToken[i].tokenValue << endl;
    }
}

//Conditional Statements
bool LexicalAnalyzer::isOperator(string s)
{
    if(s == '&&' || s == '||' || s == '==' || s == '!=' || s == '<=' || s == '>=' || s == '+'  || s == '-'  || s == "*"  || s == '/'  || s == '<'  || s == '>'  ||)
    {
        cout << "Operator:  " << s << endl;
        return true;
    }else
        return false;
}

int main(int syntax, char** error){
    LexicalAnalyzer object; /*placeholder*/
    string file;
    ifstream ll;
    cout << "enter name of file (like txt): ";
    getline(cin, file);
    ll.open(string);
    if(ll.is_open() and !ll.fail())
        cout << "done\n";
    else
        cout << "it didn't work\n";
    
    return 0;
    // this is just sample code (I think)
    /* just to double check:
    cin.getline(cstring, number) is for c-strings/char arrays
    getline(cin,stringname) is for std strings
    */
}
