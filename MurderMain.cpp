/********************************************************
* Created: 11/6
* Edit: 11/11 Include GameManager and NPCClass
* Edit: 11/12 Add comments and fout
* Edit: 11/13 Modify startScreenMain
* 
* Contributers: Esra Petty and Gabrielle de Leeuw
********************************************************/


#include <iostream> 
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "GameManager_v2.h" 
#include "NPCClass_v2.h"
#include "StartScreen.h"
#include "SelectionScreen.h"

using namespace std;


int main()
{  
	ofstream fout("NotePad.txt");
	
	srand(time(NULL));
    int numberOfCharacters = 10;
	GameManager gm(numberOfCharacters);
	startScreenMain(gm);
	// run instructions
	// run prologue
	if( gm.getIsWin() == true )
	{
	    cout << "You win!" << endl;
	    //run win condition
	}
	else
	{
	    cout << "You lose." << endl;
	    // run fail condition
	} 

	fout.close();
    return 0;
}
