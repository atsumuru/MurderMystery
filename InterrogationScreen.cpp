#include "CharacterFile.h"
#include "InterrogationScreen.h"
#include "SelectionScreen.h"
// #include "NPCClass_v2.h"

// displays selected character information
void characterInfo(CharacterFile* character)
{
    if (character == nullptr) { return; }
    
    cout << character << endl; // Adapted for cout override - Esra P.
    character->displayCatchphrase();
    cout << endl;
}

void interrogateOptions()
{
    cout << endl;
    
    cout << "ALIBI" << endl;
    cout << "MOTIVE" << endl;
    cout << "NOTES" << endl;
    cout << "BACK" << endl;
    cout << endl;
}

// gets choice
void interrogateChoice(CharacterFile* character)
{
    string choice;
    
    // do error checking to take either B or b
    // or defaut to lowercase
    
    while (choice != "back" && choice != "b")
    {
        // display options
        interrogateOptions();
        
        cout << "WHAT WOULD YOU LIKE TO DO? ";
        cin >> choice;
        
        if (choice == "alibi" || choice == "a")
        {
            // call alibi from NPC Class
        }
        else if (choice == "motive" || choice == "m")
        {
            character->displayMotive();
            cout << endl;
        }
        else if (choice == "notes" || choice == "n")
        {
            // not sure what I want to do here yet
        }
        else if (choice == "back" || choice == "b")
        {
            selectionScreenMain();
        }
        else
        {
            cout << "INVALID CHOICE. TRY AGAIN." << endl;
            cout << endl;
        }
        
        // after making choice, clear screen, then replace (mayhaps)
        // catchphrase with motive/alibi text
    }
    
    // go through while loop so once you make a choice, you can chose something else
    // if statements for making the choices
}

void interrogationScreenMain(CharacterFile* character)
{
    // checks if a character is selected
    if (character == nullptr) { return; }
    
    characterInfo(character);
    interrogateChoice(character);
}
