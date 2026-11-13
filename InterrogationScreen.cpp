#include "CharacterFile.h"
#include "InterrogationScreen.h"
#include "SelectionScreen.h"
#include "GameManager_v2.h"

// displays selected character information
void characterInfo(CharacterFile* character)
{
    cout << endl;
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
    
    // will tweak selection to only the word so it can access all options

    while (choice != "back" && choice != "b")
    {
        // display options
        interrogateOptions();
        
        cout << "WHAT WOULD YOU LIKE TO DO (TYPE FULL WORD)? ";
        cin >> choice;
        
        if (choice == "alibi")
        {
            character->displayAlibi(characters, count);
            cout << endl;
            gm.incrementTalks();
        }
        else if (choice == "motive")
        {
            character->displayMotive();
            cout << endl;
            gm.incrementTalks();
        }
        else if (choice == "notes")
        {
            // not sure what I want to do here yet
        }
        else if (choice == "back")
        {
            return;
        }
        else if(choice == "accuse")
        {
            character->displayAccuse();
            gm.incrementTalks();
            return;
        }
        else
        {
            cout << "INVALID CHOICE. TRY AGAIN." << endl;
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
