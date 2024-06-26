#include <fstream>
#include <iostream>

#include "Interpritator.h"

using namespace std;

int main()
{
    Interpritator lang;
    ifstream file;
    short memory[36000]{ 0 };
    string code;
    string input;

    cin >> input;
    file.open(input);
 
    while (!file.eof())
    {
        string temp;
        getline(file, temp);
        code.append(temp);
    }
    
    lang.parse(code, memory);
}