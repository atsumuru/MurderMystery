#include "Prologue.h"
#include "SelectionScreen.h"

// created 11/9/2026
// by Payton Phillips

// this is where the prologue will go
// it's a intro to the game, explaining the
// setting, what brought everyone here, and 
// who the victim is. 

// this is just a stand-in right now
// the prologue text will be added later
// this is just here so we can test.

void prologue()
{
    cout << "   Here is the prologue." << endl;
    cout << "   This one guy died." << endl;
    cout << "   Find out who don' it." << endl;
}

void gameContinue()
{
    string choice;
    
    cout << "   READY TO START? (YES OR NO) ";
    cin >> choice;
    
    if(choice == "yes" || choice == "y")
    {
        // pull selectionscreen function
    }
    else
    {
        cout << "   How dare you." << endl;
        cout << endl;
        exit(0);
    }
}

void prologueMain()
{
    prologue();
    gameContinue();
}
