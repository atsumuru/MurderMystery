#ifndef CHARACTERFILE_H
#define CHARACTERFILE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class CharacterFile {
protected:
    string ascii; 
    string name;
    
    string catchphrase[3];
    string motive[3];
public:
    CharacterFile();
    // "virtual" allows the child objects to be properly destroyed
    virtual ~CharacterFile();
    // Got rid of displayAscii and displayName for cout override - Esra P.
    void displayCatchphrase();
    void displayMotive(); 

    friend ostream& operator <<(ostream& os, const CharacterFile&); // Prototype for override operator - Esra P.
};

#endif
