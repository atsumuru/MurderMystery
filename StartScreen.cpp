/********************************************************
* Created: 10/26
* Edit: 10/27 Update formatting
* Edit: 11/12 Add nickName and displayAlibi
* Edit: 11/13 Add GameManager
* Edit: 11/14 Add input handling
* 
* Contributers: Payton Phillips and Gabrielle de Leeuw
********************************************************/

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
    
    // convert option to lowercase
    for (int i = 0; i < option.length(); i++)
    {
        option[i] = tolower(option[i]);
    }
    
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
