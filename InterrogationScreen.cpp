#include "CharacterFile.h"
#include "InterrogationScreen.h"
#include "SelectionScreen.h"
#include "GameManager_v2.h"

// displays selected character information
void characterInfo(CharacterFile* character)
{
    if (character == nullptr) { return; }
    
    cout << *character << endl; // Adapted for cout override - Esra P.
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
    cout << "ACCUSE" << endl;
    cout << endl;
}

// gets choice
void interrogateChoice(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm)
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
            character->displayAlibi(characters, count);
            gm.incrementTalks();
        }
        else if (choice == "motive" || choice == "m")
        {
            character->displayMotive();
            cout << endl;
            gm.incrementTalks();
        }
        else if (choice == "notes" || choice == "n")
        {
            // not sure what I want to do here yet
        }
        else if (choice == "back" || choice == "b")
        {
            return;
        }
        else if(choice == "accuse" || choice == "a")
        {
            character->accuse();
            gm.incrementTalks();
        }
        else
        {
            cout << "INVALID CHOICE. TRY AGAIN." << endl;
            cout << endl;
        }
        
        // after making choice, clear screen, then replace (mayhaps)
        // catchphrase with motive/alibi text
    }
}

void interrogationScreenMain(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm)
{
    // checks if a character is selected
    if (characters == nullptr) { return; }
    
    characterInfo(character);
    interrogateChoice(character, characters, count, gm);
}
