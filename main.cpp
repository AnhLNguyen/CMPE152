#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "token.h"
using namespace std;

class LexicalAnalyzer{
    public:
        LexicalAnalyzer();
        vector<Token> acceptedToken;
        vector<Token> getNextToken();
        void printOut();
        bool isSymbol(char c);
        vector<char> fileBuffer;
        int size;
};

//Check is the input character a symbol or not
bool LexicalAnalyzer::isSymbol(char c){
    if (c == '{' || c == '}' || c == '(' || c == ')' ||
        c == '<' || c == '>' || c == '+' || c == '-' ||
        c == '*' || c == '/' || c == '=' || c == '!' ||
        c == '\t'|| c == '\n'|| c == '"' || c == ';' ||
        c == '\''|| c == isspace(c)) 
        return true;
    else 
        return false;
    return 0;
}

//stream input file to characters function (getNextToken)
vector<Token> LexicalAnalyzer::getNextToken()
{
    //Scan all the character 
    ifstream inStream;
    char c;
    inStream.open("testInput.txt");
    if (!inStream) //Prompt error when cannot read the file
    {
        cout << "File is not available." <<endl;
        exit(1);
    }
    while(inStream.get(c))
    { //Push all the characters into fileBuffer vector to handle it later
        fileBuffer.push_back(c);
    }
    inStream.close();
    
    return acceptedToken;
}

void LexicalAnalyzer::printOut(){
    int vectorSize = acceptedToken.size();
    for (int i =1; i< vectorSize;i++){
        cout << acceptedToken[i].lexer << '\t' << acceptedToken[i].tokenValue << endl;
    }
}
int main(){
    int n
    cout << "enter a number: ";
while(true){
  cin >> n;
  if(number==1);
  else if(number==2);
  else if(number==3);
  else if(number==4)
    break;
  else
    cout << "try again: ";
    // this is just sample code (I think)
}
