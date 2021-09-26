#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "token.h"
using namespace std;

class LexicalAnalyzer {
public:
    LexicalAnalyzer(int=0);
    vector<Token> acceptedToken;
    vector<Token> getNextToken();
    void printOut();
    bool isSymbol(char c);
    vector<char> fileBuffer;
    int size;
    LexicalAnalyzer operator+;
    LexicalAnalyzer operator-;
    LexicalAnalyzer operator*;
    LexicalAnalyzer operator/;
};
//Default Constructor 
LexicalAnalyzer::LexicalAnalyzer(int Size)
{
    acceptedToken.push_back(Token("", ""));
    size = Size;
}

//Check is the input character a symbol or not
bool LexicalAnalyzer::isSymbol(char c) {
    if (c == '{' or c == '}' or c == '(' or c == ')' or c == '/' or c == '<'
        or c == '+' or c == '-' or c == '*' or c == '\t' or c == '>' or c == '='
        or c == '!' or c == ';' or c  == '"' or c =='\'' or isspace(c) or c == '\n')
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
            else if (temp == "int" || temp == "float" || temp == "bool")
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
        else if (fileBuffer[i] == '{' || fileBuffer[i] == '}')
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
        else if (fileBuffer[i] == ';' || fileBuffer[i] == '+')
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
        else if (fileBuffer[i] == '-' || fileBuffer[i] == '*')
        {
            string symbol(1, fileBuffer[i]);
            Token token(symbol, symbol);
            acceptedToken.push_back(token);
        }
        else if (fileBuffer[i] == '(' || fileBuffer[i] == ')')
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
        else if (fileBuffer[i] == '>' || fileBuffer[i] == '<')
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
    LexicalAnalyzer la;
    la.getNextToken();
    la.printOut();

    return 0;
}
