#include "StartScreen.h"
#include "Prologue.h"
#include "Instructions.h"

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

void gameOptions()
{
    string option;
    
    cout << endl;
    cout << "   CHOOSE AN OPTION: ";
    cin >> option;
    
    if(option == "start" || option == "s")
    {
        prologueMain();
    }
    if(option == "instructions" || option == "i")
    {
        instructionsMain();
    }
}

void startScreenMain()
{
    startScreen();
    gameOptions();
}
