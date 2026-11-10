/*  
\    Esra p.
\    11/6/26 [Created Main file] 
\    The "Main" file for our code
\    
*/


#include <iostream> 
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "GameManager.cpp" 
#include "NPCClass.cpp"
//#include "StartScreen.cpp"

using namespace std;


int main()
{
    int numberOfCharacters = 10;
    srand(time(NULL));
	GameManager gm(numberOfCharacters);
	//startScreen();
	
	while( gm.getIsWin() == false && gm.getNPCsLeft() > 1 ) {
	    gm.run();
	}
	if( gm.getIsWin() == true ) {
		gm.winScreen();
	} else {
		gm.loseScreen();
	}
    return 0;
}
