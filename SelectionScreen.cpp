#include "SelectionScreen.h"
#include "InterrogationScreen.h"

#include "CharacterFile.h"
#include "Baroness.h"
// add other character Files

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
    
}

void selectCharacter()
{
    int choice;
    
    // Creates a parent-class pointer
    // nullptr means that it does not point to a character yet
    CharacterFile* selectedCharacter = nullptr;
    
    cout << "PLEASE SELECT A CHARACTER (ENTER INTEGER): ";
    cin >> choice;

    // character files *should* work, tho i could not test it all together
    // due to OnlineGDB limitations
    switch (choice)
    {
        case 1:
            // dynamically allocates the memory
            // baroness is accessibly cause it inherits from CharacterFile
            selectedCharacter = new Baroness();
            break;
            
        case 2:
            selectedCharacter = new FemmeFatale();
            break;
            
        case 3:
            selectedCharacter = new Engineer();
            break;
            
        case 4:
            selectedCharacter = new Doctor();
            break;
            
        case 5:
            selectedCharacter = new Critic();
            break;
            
        case 6:
            selectedCharacter = new Professor();
            break;
            
        case 7:
            selectedCharacter = new Servant();
            break;
            
        case 8:
            selectedCharacter = new Investigator();
            break;
            
        case 9:
            selectedCharacter = new Bartender();
            break;
            
        case 10:
            selectedCharacter = new Conductor();
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
        interrogationScreenMain(selectedCharacter);
        // releases dynamically allocated memory
        delete selectedCharacter;
        // resets pointer
        selectedCharacter = nullptr;
    }
}

void selectionScreenMain()
{
    selectionScreen();
    selectCharacter();
}
