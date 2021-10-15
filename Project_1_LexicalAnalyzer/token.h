#ifndef TOKEN_H
#define TOKEN_H

#include<iostream>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;

class Token{
    public:
    Token();
    Token(string input, string attr);
    string lexer;
    string tokenValue;
};

Token::Token(){
    lexer = "";
    tokenValue = "";

}
Token::Token(string input, string attr){
    lexer = input;
    tokenValue = attr;
}

#endif