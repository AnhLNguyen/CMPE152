#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include "parser.h"
using namespace std;

int main(int argc, char** argv){
    ifstream fin;
    fin.open("test.txt");
    if(fin and !fin.fail())
        cout << "File opened successfully\n";
    else
        exit(1);
    
    return argc;
}
