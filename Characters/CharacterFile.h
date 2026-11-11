#ifndef CHARACTERFILE_H
#define CHARACTERFILE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class CharacterFile {
protected:
    string ascii = "ASCII PLACEHOLDER"; 
    string name = "HONORIFIC FIRST LAST";
    string catchphrase[3] =
        {
            "\"DEFAULT Catchphrase #1\"",
            "\"DEFAULT Catchphrase #2\"",
            "\"DEFAULT Catchphrase #3\""
        };
    string motive[3] =
        {
            "DEFAULT Positive Motive",
            "DEFAULT Neutral Motive",
            "DEFAULT Negative Motive"
        };
public:
    void displayCharacter();
    void displayName();
    void displayCatchphrase();
    void displayMotive();
};

#endif
