#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "token.h"
using namespace std;

<<<<<<< HEAD
class LexicalAnalyzer {
public:
    LexicalAnalyzer();
=======
class LexicalAnalyzer{
    int size;
    
public:
    LexicalAnalyzer(int=0);
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
    vector<Token> acceptedToken;
    vector<Token> getNextToken();
    void printOut();
    bool isSymbol(char c);
    vector<char> fileBuffer;
<<<<<<< HEAD
    int size;
};
//Default Constructor 
LexicalAnalyzer::LexicalAnalyzer()
{
    acceptedToken.push_back(Token("", ""));
    size = 0;
=======
    LexicalAnalyzer operator+(LexicalAnalyzer&);
    LexicalAnalyzer operator-(LexicalAnalyzer&);
    LexicalAnalyzer operator*(LexicalAnalyzer&);
    LexicalAnalyzer operator/(LexicalAnalyzer&);
    int get_size(); //accessor function
};
//Default Constructor 
LexicalAnalyzer::LexicalAnalyzer(int Size){
    acceptedToken.push_back(Token("", ""));
    size = Size;
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
}

//Check is the input character a symbol or not
bool LexicalAnalyzer::isSymbol(char c) {
<<<<<<< HEAD
    if (c == '{' || c == '}') {
        return true;
    }
    else if (c == '(' || c == ')') {
        return true;
    }
    else if (c == '/' || c == '<') {
        return true;
    }
    else if (c == '+' || c == '-') {
        return true;
    }
    else if (c == '*' || c == '\t') {
        return true;
    }
    else if (c == '>' || c == '=') {
        return true;
    }
    else if (c == '!' || c == ';') {
        return true;
    }
    else if (c == '"' || c == '\'') {
        return true;
    }
    else if (c == ' ' || c == '\n') {
        return true;
    }
    else {
        return false;
    }
    return 0;
=======
    try{
        if (c == '{' or c == '}' or c == '(' or c == ')' or c == '/' or c == '<'
            or c == '+' or c == '-' or c == '*' or c == '\t' or c == '>' or c == '='
            or c == '!' or c == ';' or c  == '"' or c =='\'' or isspace(c) or c == '\n')
            return true;

        else
            throw char;
    }
    catch(char){
        cout << "an exception occurred: " << char << endl;
        return false;
    }
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
}

//stream input file to characters function (getNextToken)
vector<Token> LexicalAnalyzer::getNextToken()
{
    //Scan all the character 
    ifstream inStream;
    char c;
    inStream.open("testInput.txt");
<<<<<<< HEAD
    if (!inStream) //Prompt error when cannot read the file
    {
=======
    if (!inStream or inStream.fail()){ //Prompt error when cannot read the file
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
        cout << "File is not available." << endl;
        exit(1);
    }
    while (inStream.get(c))
    { //Push all the characters into fileBuffer vector to handle it later
        fileBuffer.push_back(c);
    }
    inStream.close();

    //Check for keyword
    int size = fileBuffer.size();
    for (int i = 0; i < size; i++)
    {
        string temp = "";//used for storing symbols/letters
        if (isalpha(fileBuffer[i]))
        {
            int j = 0;
            for (j = i; j < size; j++)
            {
                if (!isalpha(fileBuffer[j]))
                {
                    if (!isSymbol(fileBuffer[j]))
                    {
                        temp += fileBuffer[j];
                    }
                    else
                        break;
                }
                else
                    temp += fileBuffer[j];
            }
            i = j - 1;
            if (temp == "while")
            {
                Token token(temp, "WHILE");
                acceptedToken.push_back(token);
            }
<<<<<<< HEAD
            else if (temp == "int" || temp == "float" || temp == "bool")
=======
            else if (temp == "int" or temp == "float" or temp == "bool")
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
            {
                Token token(temp, "BASE_TYPE");
                acceptedToken.push_back(token);
            }
            else if (temp == "true")
            {
                Token token(temp, "TRUE");
                acceptedToken.push_back(token);
            }
            else if (temp == "do")
            {
                Token token(temp, "DO");
                acceptedToken.push_back(token);
            }
            else if (temp == "false")
            {
                Token token(temp, "FALSE");
                acceptedToken.push_back(token);
            }
            else if (temp == "else")
            {
                Token token(temp, "ELSE");
                acceptedToken.push_back(token);
            }
            else if (temp == "break")
            {
                Token token(temp, "BREAK");
                acceptedToken.push_back(token);
            }
            else if (temp == "if")
            {
                Token token(temp, "IF");
                acceptedToken.push_back(token);
            }
            else if (temp == "for")
            {
                Token token(temp, "FOR");
                acceptedToken.push_back(token);
            }
            else
            {
                Token token(temp, "ID");
                acceptedToken.push_back(token);
            }
        }
        //check to see if the token is an identifier
        else if (isdigit(fileBuffer[i]))
        {
            int j = 0;
            for (j = i; j < size; j++)
            {
                if (!isdigit(fileBuffer[j])) // until reaching a character that is not number
                {
                    if (!isSymbol(fileBuffer[j])) {
                        temp += fileBuffer[j];
                    }
                    else break;
                }
                else temp += fileBuffer[j];
            }
            int found = temp.find('.');
            i = j - 1;
            if (found != -1)
            {
                Token token(temp, "REAL");
                acceptedToken.push_back(token);
            }
            else
            {
                Token token(temp, "NUM");
                acceptedToken.push_back(token);
            }
        }
<<<<<<< HEAD
        else if (fileBuffer[i] == '{' || fileBuffer[i] == '}')
=======
        else if (fileBuffer[i] == '{' or fileBuffer[i] == '}')
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
<<<<<<< HEAD
        else if (fileBuffer[i] == ';' || fileBuffer[i] == '+')
=======
        else if (fileBuffer[i] == ';' or fileBuffer[i] == '+')
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
<<<<<<< HEAD
        else if (fileBuffer[i] == '-' || fileBuffer[i] == '*')
=======
        else if (fileBuffer[i] == '-' or fileBuffer[i] == '*')
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
<<<<<<< HEAD
        else if (fileBuffer[i] == '(' || fileBuffer[i] == ')')
=======
        else if (fileBuffer[i] == '(' or fileBuffer[i] == ')')
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
        else if (fileBuffer[i] == '/')
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
        else if (fileBuffer[i] == '|')
        {
            temp += fileBuffer[i];
            if (fileBuffer[i + 1] == '|')
            {
                Token token(temp, "OR");
                acceptedToken.push_back(token);
            }
            else continue;
        }
        else if (fileBuffer[i] == '!')
        {
            temp += fileBuffer[i];
            if (fileBuffer[i + 1] == '=')
            {
                temp += fileBuffer[i + 1];
                Token token(temp, "NE");
                acceptedToken.push_back(token);
                i = i + 1;
            }
            else
            {
                Token token(temp, temp);
                acceptedToken.push_back(token);
            }
        }
<<<<<<< HEAD
        else if (fileBuffer[i] == '>' || fileBuffer[i] == '<')
=======
        else if (fileBuffer[i] == '>' or fileBuffer[i] == '<')
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
        {
            temp = fileBuffer[i];
            if (fileBuffer[i] == '>')
            {
                if (fileBuffer[i + 1] == '=')
                {
                    temp += fileBuffer[i + 1];
                    Token token(temp, "GE");
                    acceptedToken.push_back(token);
                    i = i + 1;
                }
                else
                {
                    Token token(temp, temp);
                    acceptedToken.push_back(token);
                }
            }
            else if (fileBuffer[i] == '<')
            {
                if (fileBuffer[i + 1] == '=')
                {
                    temp += fileBuffer[i + 1];
                    Token token(temp, "LE");
                    acceptedToken.push_back(token);
                    i = i + 1;
                }
                else
                {
                    string symbol(1, fileBuffer[i]);
                    Token token(symbol, symbol);
                    acceptedToken.push_back(token);
                }
            }
        }
        else if (fileBuffer[i] == '&')
        {
            temp += fileBuffer[i];
            if (fileBuffer[i + 1] == '&')
            {
                temp += fileBuffer[i + 1];
                Token token(temp, "AND");
                acceptedToken.push_back(token);
                i = i + 1;
            }
            else
            {
                Token token(temp, temp);
                acceptedToken.push_back(token);
            }
        }
        else if (fileBuffer[i] == '=')
        {
            temp += fileBuffer[i];
            if (fileBuffer[i + 1] == '=')
            {
                temp += fileBuffer[i + 1];
                Token token(temp, "EQ");
                acceptedToken.push_back(token);
                i = i + 1;
            }
            else
            {
                Token token(temp, temp);
                acceptedToken.push_back(token);
            }
        }
    }
    Token end("EOF", "EOF");
    acceptedToken.push_back(end);
    return acceptedToken;
}
//Display output function   
void LexicalAnalyzer::printOut() {
    int vectorSize = acceptedToken.size();
    for (int i = 1; i < vectorSize; i++) {
        cout << acceptedToken[i].tokenValue << '\t' << acceptedToken[i].lexer << endl;
    }

    ofstream outStream;
    outStream.open("testOutput.txt");

<<<<<<< HEAD
    if (!outStream) //Prompt error when cannot read the file
    {
        cout << "File is not available." << endl;
        exit(1);
    }
    else
    {
        for (int i = 1; i < vectorSize; i++) {
            outStream << acceptedToken[i].tokenValue << '\t' << acceptedToken[i].lexer << endl;
        }
    }
}
int main()
{
=======
    if(outStream and !outStream.fail())
        for (int C=1; C<=vectorSize-1; C++)
            outStream << acceptedToken[C].tokenValue << '\t' << acceptedToken[C].lexer << endl;
    
    else{
        cout << "File is not available." << endl; //Prompt error when cannot read the file
        exit(1);
    }
}

LexicalAnalyzer LexicalAnalyzer::operator+(LexicalAnalyzer& a){
    return LexicalAnalyzer(size+a.size);
}

LexicalAnalyzer LexicalAnalyzer::operator-(LexicalAnalyzer& A){
    return LexicalAnalyzer(size-A.size);
}

LexicalAnalyzer LexicalAnalyzer::operator*(LexicalAnalyzer& b){
    return LexicalAnalyzer(size*b.size);
}

LexicalAnalyzer LexicalAnalyzer::operator/(LexicalAnalyzer& B){
    return LexicalAnalyzer(size/B.size);
}

int LexicalAnalyzer::get_size(){
    return size;
}

int main(int foo, char** bar){
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
    LexicalAnalyzer la;
    la.getNextToken();
    la.printOut();

    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> a653067e0fade4eca26cfb97ca0fce0d226a3c88
