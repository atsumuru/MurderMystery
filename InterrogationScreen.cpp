#include "CharacterFile.h"
#include "InterrogationScreen.h"
#include "SelectionScreen.h"
#include "GameManager_v2.h"
#include "ClearScreen.h"

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
bool interrogateChoice(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm)
{
    string choice;
    bool interrogated = false;

    // creates infinite loop until it is explicitly stopped
    while (true)
    {
        characterInfo(character);
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
            clearScreen();
            cout << endl;
            character->displayAlibi(characters, count);
            cout << endl;
            
            gm.incrementTalks();
        }
        else if (choice == "motive")
        {
            clearScreen();
            cout << endl;
            character->displayMotive();
            cout << endl;
            
            gm.incrementTalks();
        }
        else if (choice == "notes")
        {
            ifstream fin("NotePad.txt");
            clearScreen(); 
            cout << endl; 
            string line;
            while(getline(fin, line)) 
                cout << line << '\n'; 
            fin.close(); 

            cout << endl;
            
        }
        else if (choice == "back")
        {
            return interrogated;
        }
        else if(choice == "accuse")
        {
            // true = correct accusation
            // false = incorrect accusation
            clearScreen();
            if (character->displayAccuse())
            {
                return interrogated;
            }
            else
            {
                cout << "CONTINUE INVESTIGATING." << endl;
            }
        }
        else
        {
            cout << "INVALID CHOICE. TRY AGAIN." << endl;
            clearScreen();
        }
    }
}

bool interrogationScreenMain(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm)
{
    clearScreen();
    // checks if a character is selected
    if (characters == nullptr) { return false; }

    bool interrogated = interrogateChoice(character, characters, count, gm);

    // if inccorectly guess character, 
    if (gm.getIsWin() == true)
    {
        gm.winScreen();
    }
    
    return interrogated;
}
