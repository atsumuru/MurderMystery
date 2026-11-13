/*  
\    Esra P.
\    11/6/26 [Created Main file] 
\    The "Main" file for our code
\    
*/


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
	startScreenMain();
	// run instructions
	// run prologue
	while( gm.getIsWin() == false && gm.getNPCsLeft() > 1 ) {
	    gm.run();
	}
	if( gm.getIsWin() == true ) {
	    cout << "You win!" << endl;
	    //run win condition
	} else {
	    cout << "You lose." << endl;
	    // run fail condition
	} 

	fout.close();
    return 0;
}
