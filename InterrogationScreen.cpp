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

    // will tweak selection to only the word so it can access all options

    while (true)
    {
        // display options
        interrogateOptions();
        
        cout << "WHAT WOULD YOU LIKE TO DO? (TYPE FULL WORD): ";
        cin >> choice;
        
        // convert choice to lowercase
        for (int i = 0; i < choice.length(); i++)
        {
            choice[i] = tolower(choice[i]);
        }
        
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
            // true = correct accusation
            // false = incorrect accusation

            if (character->displayAccuse())
            {
                return;
            }
            else
            {
                cout << "CONTINUE INVESTIGATING." << endl;

                // redisplay selected character information
                characterInfo(character);
            }
        }
        else
        {
            cout << "INVALID CHOICE. TRY AGAIN." << endl;
        }
    }
}

void interrogationScreenMain(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm)
{
    // checks if a character is selected
    if (characters == nullptr) { return; }
    
    characterInfo(character);
    interrogateChoice(character, characters, count, gm);
    
    if (gm.getIsWin() == true)
    {
        gm.winScreen();
    }
}
