#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "token.h"
#include <stack>
using namespace std;
typedef bool Bool;

class LexicalAnalyzer{
    int size

public:
    LexicalAnalyzer(int=0);
    vector<Token> acceptedToken;
    vector<Token> getNextToken();
    void printOut();
    Bool isSymbol(char);
    Bool isOperator(string);
    vector<char> fileBuffer;
};

int main(int syntax, char** error){
    LexicalAnalyzer object; /*placeholder*/
    string file;
    ifstream ll;
    cout << "enter name of file (like txt): ";
    getline(cin, file);
    ll.open(file);
    if(ll.is_open() and !ll.fail())
        cout << "done\n";
    else{
        cout << "it didn't work\n";
        exit(1);
    }
    
    return 0;
    // this is just sample code (I think)
    /* just to double check:
    cin.getline(cstring, number) is for c-strings/char arrays
    getline(cin, stringname) is for std strings
    */
}

LexicalAnalyzer::LexicalAnalyzer(int eger){ /*default constructor*/
    size = eger;
}

//Check is the input character a symbol or not
Bool LexicalAnalyzer::isSymbol(char c){
    if (c == '{' or c == '}' or c == '(' or c == ')' or
        c == '<' or c == '>' or c == '+' or c == '-' or
        c == '*' or c == '/' or c == '=' or c == '!' or
        c == '\t'or c == '\n'or c == '"' or c == ';' or
        c == '\''or c == isspace(c)) 
        return true;
    else 
        return false;
}

//Conditional Statements
Bool LexicalAnalyzer::isOperator(string s){
    if(s == "&&" or s=="and" or s == "||" or s == "or" or s == "==" or s == "!=" or s == "<="
    or s == ">=" or s == "+"  or s == "-" or s == "*"  or s == "/"  or s == "<"  or s == ">"){
        cout << "Operator:  " << s << endl;
        return true;
    }else
        return false;
}

//stream input file to characters function (getNextToken)
vector<Token> LexicalAnalyzer::getNextToken(){
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
<<<<<<< HEAD


=======
>>>>>>> 44a616a002244b481a9550fc810572ad31a3890a
