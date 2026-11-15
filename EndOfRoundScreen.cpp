#ifndef ENDOFROUNDSCREEN_CPP
#define ENDOFROUNDSCREEN_CPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "NPCClass_v2.h"
#include "EndOfRoundScreen.h"
#include "ClearScreen.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

void endOfRoundScreen(int rounds, NPC* char1, NPC*char2) {
    clearScreen();
    cout << endl << endl << endl << endl;
    string toSay = "END OF HOUR " + to_string(rounds);
    cout << "\t" << "\t"<< "\t"<< "\t"<< "\t"<< "\t" << toSay << endl << endl << endl;
    sleep_for(seconds(5));
    cout << endl << endl;
    cout << R"(
                                                _____
                                             _.'_____`._
                                           .'.-'  12 `-.`.
                                          /,' 11      1 `.\
                                         // 10      /   2 \\
                                        ;;         /       ::
                                        || 9  ----O      3 ||
                                        ::                 ;;
                                         \\ 8           4 //
                                          \`. 7       5 ,'/
                                           '.`-.__6__.-'.'
                                            ((-._____.-))
                                            _))       ((_
                                           '--'SSt    '--'

    )" << endl << endl; //https://www.asciiart.eu/art/e1929916d5eb95e7
    
    cout << " THE MURDERER STRIKES AGAIN" << endl<<endl;
    
    if (char1 != nullptr)
    {
        cout << "" << char1->getName();
        
        if (char2 != nullptr) {
            cout << " and " << char2->getName() << " have been found dead.";
        } else {
            cout << " has been found dead.";
        }
    }
    else
    {
        cout << "NO ONE DIED TONIGHT.";
    }

    cout << endl << endl << endl;
    sleep_for(seconds(7));
}

#endif
