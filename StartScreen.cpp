#include "StartScreen.h"
#include "Prologue.h"
#include "Instructions.h"
#include "GameManager_v2.h"

void startScreen()
{
    cout << R"(
    -----------------------------------------------------------------------------------------------------------------------------------
    
        ##      ##  ##   ##  #####    ######   ######  #####        ##      ##  ##    ##   #####  ######  ######  #####   ##    ##
        ####  ####  ##   ##  ##  ##   ##   ##  ##      ##  ##       ####  ####  ##    ##  ##        ##    ##      ##  ##  ##    ##
        ##  ##  ##  ##   ##  ##  ##   ##   ##  ##      ##  ##       ##  ##  ##   ##  ##   ##        ##    ##      ##  ##   ##  ## 
        ##  ##  ##  ##   ##  #####    ##   ##  #####   #####        ##  ##  ##     ##      ####     ##    #####   #####      ##  
        ##      ##  ##   ##  ## ##    ##   ##  ##      ## ##        ##      ##     ##         ##    ##    ##      ## ##      ##  
        ##      ##  ##   ##  ##  ##   ##   ##  ##      ##  ##       ##      ##     ##         ##    ##    ##      ##  ##     ##  
        ##      ##   #####   ##   ##  ######   ######  ##   ##      ##      ##     ##     #####     ##    ######  ##   ##    ##  
    
                                                    THE MURDER OF CHARLES HUDSON

    -----------------------------------------------------------------------------------------------------------------------------------
    )";
    
    cout << endl;
    
    cout << "   START" << endl;
    cout << "   INSTRUCTIONS" << endl;
}

void gameOptions(GameManager& gm)
{
    string option;
    
    cout << endl;
    cout << "   CHOOSE AN OPTION: ";
    cin >> option;
    
    if(option == "start" || option == "s")
    {
        prologueMain(gm);
    }
    if(option == "instructions" || option == "i")
    {
        instructionsMain(gm);
    }
}

void startScreenMain(GameManager& gm)
{
    startScreen();
    gameOptions(gm);
}
