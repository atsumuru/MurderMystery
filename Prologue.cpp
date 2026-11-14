#include "Prologue.h"
#include "SelectionScreen.h"
#include "GameManager_v2.h"

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
    
    cout << R"(
            Mr. Charles Hudson was a wealthy railway tycoon.
            While immoral, he did love to show off.
            In September 1872, he revealed the fastest
            train ever created to the public
            and invited many other wealthy/famous figures to ride
            in style across the new transcontinental railway.
            However, after the first milestone, a scream
            rings out through the train.
            The Body of Charles Hudson was found…
        
            Murdered. 
            
            Now it's your turn to figure out Whodunit
            before the murderer gets away with it.
        )";
        
    cout << endl;
}

void gameContinue(GameManager& gm)
{
    string choice;
    
    cout << "   READY TO START? (YES OR NO) ";
    cin >> choice;
    
    if(choice == "yes" || choice == "y")
    {
        selectionScreenMain(gm);
    }
    else if (choice == "no" || choice == "n")
    {
        cout << "   How dare you." << endl;
        cout << endl;
        exit(0);
    }
}

void prologueMain(GameManager& gm)
{
    prologue();
    gameContinue(gm);
}
