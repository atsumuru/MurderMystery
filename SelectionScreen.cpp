// Consulted ChatGPT for alibi integration for selectionScreen

#include "SelectionScreen.h"
#include "InterrogationScreen.h"
#include "Alibi.h"
#include "GameManager_v2.h"
#include "ClearScreen.h"

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
    clearScreen();
    cout << endl;
    cout << "   WHO WILL YOU INTERROGATE?" << endl;
    
    cout << endl;
    
    cout << "   OPTION 1:    ";
    cout << "       THE BARONESS, MRS. LENORA HUDSON" << endl;
    
    cout << endl;
     
    cout << "   OPTION 2:    ";
    cout << "       THE FEMME FATALE, MADAME MARGAUX ROUGE" << endl;
    
    cout << endl;
    
    cout << "   OPTION 3:  ";
    cout << "       THE ENGINEER, MS. CASSIE (CASSANDRA) HARDWELL" << endl;
    
    cout << endl;
    
    cout << "   OPTION 4:   ";
    cout << "       THE DOCTOR, DOCTOR ANDREW REYNOLDS" << endl;
    
    cout << endl;
    
    cout << "   OPTION 5:   ";
    cout << "       THE CRITIC, MR. REGINALD SINCLAIR" << endl;
    
    cout << endl;
    
    cout << "   OPTION 6:    ";
    cout << "       THE PROFESSOR, PROFESSOR ARCHWIN STEIN" << endl;
    
    cout << endl;
    
    cout << "   OPTION 7:  ";
    cout << "       THE SERVANT, MR. JACKSON (HANDY) CONROY" << endl;
    
    cout << endl;
    
    cout << "   OPTION 8:  ";
    cout << "       THE INVESTIGATOR, PI PRESTON JONES" << endl;
    
    cout << endl;
    
    cout << "   OPTION 9:   ";
    cout << "       THE BARTENDER, MR. WILLIAM O'DOYLE" << endl;
    
    cout << endl;
    
    cout << "   OPTION 10:    ";
    cout << "       THE CONDUCTOR, MR. ARNOLD HARRIS" << endl;
    
    cout << endl;
    
}

void selectCharacter(GameManager& gm, int count)
{
    int choice;
    
    // Creates a parent-class pointer
    // nullptr means that it does not point to a character yet
    CharacterFile* selectedCharacter = nullptr;
    
    cout << "for testing: the murderer is character " << gm.getWhichIsMurderer() + 1 << endl;
    
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
    
    if(gm.characters[choice - 1]->npc->getInnocent() == false) {
        murdererAssignNewRoom(gm.characters, count, choice - 1);
    }

    // checks if the character object was created
    // if the pointer isnt nullptr, a character is selected
    if (selectedCharacter != nullptr)
    {
        // checks if the selected character refuses to talk
        if (selectedCharacter->npc->getTalksToForgiveness() > 0)
        {
            cout << endl;
            cout << "YOU FALSELY ACCUSED THIS PERSON." << endl;
            cout << "THEY WON'T TALK TO YOU RIGHT NOW." << endl;

            return;
        }
        
        // decrease forgiveness counters for OTHER characters
        for (int i = 0; i < count; i++)
        {
            if (gm.characters[i] != selectedCharacter)
            {
                gm.characters[i]->npc->decreaseTalksToForgiveness();
            }
        }
        
        // used the pointer to access the selected character file,
        // and pull it to the interrogation screen
        interrogationScreenMain(selectedCharacter, gm.characters, count, gm);
    }
}

void selectionScreenMain(GameManager& gm)
{
    
    // this whole section is needed because if you choice to go back in interrogation,
    // it will either close the program (with just a return statement),
    // or create new character objects and mess up the alibis (if you call selectionScreenMain again)
    char choice = 'y';

    while ((choice == 'y' || choice == 'Y') && gm.getIsWin() == false)
    {
        selectionScreen();
        selectCharacter(gm, 10);

        cout << endl;
        cout << "RETURN TO CHARACTER SELECTION? (Type 'y' for yes): ";
        cin >> choice;
        
        // keeps asking until the user enters y
        while ((choice != 'y' && choice != 'Y') || !cin)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "INVALID. IT WASN'T A QUESTION. :P" << endl;
    
            cout << endl;
            cout << "CONTINUE? (Type 'y' for yes): ";
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
