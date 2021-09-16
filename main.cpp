#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Token.h"
#include <stack>
using namespace std;

class LexicalAnalyzer {
    int size;
public:
    LexicalAnalyzer();
    vector<Token> acceptedToken;
    vector<Token> getNextToken();
    void ReadFile();
    void printOut();
    bool isSymbol(string);
    bool isOperator(string);
    string get_Op(string);
    bool isNumber(string);
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
    if (!inStream.is_open() || inStream.fail()) { //Prompt error when cannot read the file
        cout << "File is not available.\n";
        exit(1);
    }
    else
        cout << "Success\n\n";

    while (inStream.get(c)) {
        //Push all the characters into fileBuffer vector to handle it later
        fileBuffer.push_back(c);
    }

    inStream.close();

    /*for (int i = 0; i < fileBuffer.size(); i++) {
        cout << fileBuffer[i];
    }
    cout << endl;*/
}

//stream input file to characters function (getNextToken)
vector<Token> LexicalAnalyzer::getNextToken() {
    ReadFile();
    Token t;
    string s = "";
    
    for (int i = 0; i < fileBuffer.size(); i++) {
        if (s == "\t" || s == "\n" || s == " ") {
            s = "";
            continue;
        }
        else if (isSymbol(s)) {
            //cout << "String: " << s << endl;
            t.lexer = t.tokenValue = s;
            acceptedToken.push_back(t);
            s = "";
        }
        else if (isOperator(s)) {
            //cout << "String: " << s << endl;
            t.lexer = get_Op(s);
            t.tokenValue = s;
            acceptedToken.push_back(t);
            s = "";
        }
        else if (isNumber(s)) {
            //cout << "String: " << s << endl;
            t.lexer = "NUM";
            t.tokenValue = s;
            acceptedToken.push_back(t);
            s = "";
        }
        else if (s == "int" || s == "float" || s == "bool") {
            //cout << "String: " << s << endl;
            t.lexer = "BASE_TYPE";
            t.tokenValue = s;
            acceptedToken.push_back(t);
            s = "";
        }
        else if (s == "if" || s == "else" || s == "while" || s == "do" || s == "true" || s == "false") {
            //cout << "String: " << s << endl;
            string temp = "";
            for (int i = 0; i < s.size(); i++) {
                char x;
                x = s[i] - 32;
                temp += x;
            }
            t.lexer = t.tokenValue = temp;
            acceptedToken.push_back(t);
            s = "";
        }
        else if () {

        }

        s += fileBuffer[i];
    }

    for (int i = 0; i < acceptedToken.size(); i++) {
        cout << acceptedToken[i].lexer << "\t" << acceptedToken[i].tokenValue << endl;
    }
    cout << endl;

    return acceptedToken;
}

//Check is the input character a symbol or not
bool LexicalAnalyzer::isSymbol(string s) {
    if (s == "{" || s == "}" || s == "(" || s == ")" ||
        s == "<" || s == ">" || s == "+" || s == "-" ||
        s == "*" || s == "/" || s == "=" || s == "\"" ||
        s == ";" || s == "\'")
        return true;
    else
        return false;
}

//Conditional Statements
bool LexicalAnalyzer::isOperator(string s)
{
    if (s == "&&" || s == "||" || s == "==" || s == "!=" ||
        s == "<=" || s == ">=" || s == "+" || s == "-" ||
        s == "*" || s == "/" || s == "<" || s == ">")
    {
        return true;
    }
    else
        return false;
}

//Get Operator
string LexicalAnalyzer::get_Op(string s) {
    if (s == "&&") return "AND";
    else if (s == "||") return "OR";
    else if (s == "==") return "EQ";
    else if (s == "!=") return "NE";
    else if (s == "<=") return "LE";
    else if (s == ">=") return "GE";
}

//Check if a string is a number
bool LexicalAnalyzer::isNumber(string s) {
    if (s.size() == 0) return false;

    if (s[1] >= '0' && s[1] <= '9')
        return true;

    return false;
}

void LexicalAnalyzer::printOut() {
    int vectorSize = acceptedToken.size();
    for (int i = 1; i < vectorSize; i++) {
        cout << acceptedToken[i].lexer << '\t' << acceptedToken[i].tokenValue << endl;
    }
}

int main(int syntax, char** error) {
    LexicalAnalyzer Lex;
    Lex.getNextToken();
    Lex.printOut();

    return 0;
}