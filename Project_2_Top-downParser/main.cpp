#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "parser.h"
using namespace std;

int main(int argc, char** argv){
    char reading[100];
    unsigned count = 0;
    ifstream fin;
    fin.open("test.txt");
    if(fin and !fin.fail())
        cout << "File opened successfully\n";
    else{
        cout << "File could not be opened. Aborting system";
        exit(1);
    }
    
    while(!fin.eof()){
        fin >> reading[count];
        count++;
    }fin.close();
    
    argc = 0;
    return argc;
}
