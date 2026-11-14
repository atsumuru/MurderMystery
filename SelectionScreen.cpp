// Consulted ChatGPT for alibi integration for selectionScreen

#include "SelectionScreen.h"
#include "InterrogationScreen.h"
#include "Alibi.h"
#include "GameManager_v2.h"

#include "CharacterFile.h"
#include "Baroness.h"
#include "FemmeFatale.h"
#include "Engineer.h"
#include "Doctor.h"
#include "Critic.h"
#include "Professor.h"
#include "Servant.h"
#include "Investigator.h"
#include "Bartender.h"
#include "Conductor.h"

void selectionScreen()
{
    cout << endl;
    cout << "   WHO WILL YOU INTERROGATE?" << endl;
    
    cout << endl;
    
    cout << "   OPTION 1:    " << endl;
    cout << "       THE BARONESS" << endl;
    
    cout << endl;
     
    cout << "   OPTION 2:    " << endl;
    cout << "       THE FEMME FATALE" << endl;
    
    cout << endl;
    
    cout << "   OPTION 3:  " << endl;
    cout << "       THE ENGINEER" << endl;
    
    cout << endl;
    
    cout << "   OPTION 4:   " << endl;
    cout << "       THE DOCTOR" << endl;
    
    cout << endl;
    
    cout << "   OPTION 5:   " << endl;
    cout << "       THE CRITIC" << endl;
    
    cout << endl;
    
    cout << "   OPTION 6:    " << endl;
    cout << "       THE PROFESSOR" << endl;
    
    cout << endl;
    
    cout << "   OPTION 7:  " << endl;
    cout << "       THE SERVANT" << endl;
    
    cout << endl;
    
    cout << "   OPTION 8:  " << endl;
    cout << "       THE INVESTIGATOR" << endl;
    
    cout << endl;
    
    cout << "   OPTION 9:   " << endl;
    cout << "       THE BARTENDER" << endl;
    
    cout << endl;
    
    cout << "   OPTION 10:    " << endl;
    cout << "       THE CONDUCTOR" << endl;
    
    cout << endl;
    
}

void selectCharacter(GameManager& gm, int count)
{
    int choice;
    
    // Creates a parent-class pointer
    // nullptr means that it does not point to a character yet
    CharacterFile* selectedCharacter = nullptr;
    
    cout << "PLEASE SELECT A CHARACTER (ENTER INTEGER): ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            selectedCharacter = gm.characters[0];
            break;
            
        case 2:
            selectedCharacter = gm.characters[1];
            break;
            
        case 3:
            selectedCharacter = gm.characters[2];
            break;
            
        case 4:
            selectedCharacter = gm.characters[3];
            break;
            
        case 5:
            selectedCharacter = gm.characters[4];
            break;
            
        case 6:
            selectedCharacter = gm.characters[5];
            break;
            
        case 7:
            selectedCharacter = gm.characters[6];
            break;
            
        case 8:
            selectedCharacter = gm.characters[7];
            break;
            
        case 9:
            selectedCharacter = gm.characters[8];
            break;
            
        case 10:
            selectedCharacter = gm.characters[9];
            break;
            
        default:
            cout << "   INVALID CHOICE. PLEASE TRY AGAIN." << endl;
            break;
    }

    // checks if the character object was created
    // if the pointer isnt nullptr, a character is selected
    if (selectedCharacter != nullptr)
    {
        // used the pointer to access the selected character file,
        // and pull it to the interrogation screen
        interrogationScreenMain(selectedCharacter, gm.characters, count, gm);
    }
}

void selectionScreenMain(GameManager& gm)
{
    // for(int i = 0; i < 10; i++) {
    //     try{
    //     gm.characters[i]->npc->setName(gm.characters[i]->getName());
    //     throw(gm.characters[i]->getName());
    //     }
    //     catch(string n) {
    //         cout << "Error with " << n << endl;
    //     }
    // }
    
    // this whole section is needed because if you choice to go back in interrogation,
    // it will either close the program (with just a return statement),
    // or create new character objects and mess up the alibis (if you call selectionScreenMain again)
    char choice = 'y';

    while (choice == 'y' || choice == 'Y')
    {
        selectionScreen();
        selectCharacter(gm, 10);

        cout << endl;
        cout << "RETURN TO CHARACTER SELECTION? (YES.): ";
        cin >> choice;
        
        // keeps asking until the user enters y
        while (choice != 'y' && choice != 'Y')
        {
            cout << "INVALID. IT WASN'T A QUESTION. :P" << endl;
    
            cout << endl;
            cout << "RETURN TO CHARACTER SELECTION? (YES.): ";
            cin >> choice;
        }
    }
    
    // // deletes allocated memory
    // for (int i = 0; i < 10; i++)
    // {
    //     delete characters[i];
    //     characters[i] = nullptr;
    // }
}
