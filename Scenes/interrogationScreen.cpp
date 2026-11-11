#include <iostream>
using namespace std;

#include "characterFile.h"
#include "interrogationScreen.h"
// #include "NPCClass_v2.h"

void characterInfo()
{
    CharacterFile test;
    test.displayCharacter();
    cout << endl;
    test.displayName();
    cout << endl;
    test.displayCatchphrase();
    cout << endl;
}

void interrogateOptions()
{
    cout << "Alibi" << endl;
    cout << "Motive" << endl;
    cout << "Notes" << endl;
    cout << "Back" << endl;
    cout << endl;
}

void interrogateChoice()
{
    CharacterFile test;
    string choice;
    
    // do error checking to take either B or b
    // or defaut to lowercase
    
    while (choice != "Back" && choice != "b")
    {
        cout << "Which would you like to do? ";
        cin >> choice;
        
        if (choice == "Alibi" || choice == "a")
        {
            // call alibi from NPC Class
        }
        else if (choice == "Motive" || choice == "m")
        {
            test.displayMotive();
            cout << endl;
        }
        else if (choice == "Notes" || choice == "n")
        {
            // not sure what I want to do here yet
        }
        else if (choice == "Back" || choice == "b")
        {
            // return you to selection screen
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
            cout << endl;
        }
        
        // after making choice, clear screen, then replace
        // catchphrase with motive/alibi text
    }
    
    // go through while loop so once you make a choice, you can chose something else
    // if statements for making the choices
}
