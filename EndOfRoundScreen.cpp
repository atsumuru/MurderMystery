#ifndef ENDOFROUNDSCREEN_CPP
#define ENDOFROUNDSCREEN_CPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "NPCClass_v2.h"
#include "EndOfRoundScreen.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


void clearScreenRound() {
    // \033[2J clears the entire screen
    // \033[H moves the cursor to the top-left position (row 1, column 1)
    std::cout << "\033[2J\033[H";
    std::cout.flush(); // Forces the output to display immediately
}

void endOfRoundScreen(int rounds, NPC* char1, NPC*char2) {
    clearScreenRound();
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
    
    cout << "\t\t\t\t\t THE MURDERER STRIKES AGAIN" << endl<<endl;
    cout << "\t\t\t\t\t" << char1->getName();
    if (char2 != NULL) {
        cout << " and " << char2->getName() << " have been found dead.";
    } else {
        cout << " has been found dead.";
    }
    cout << endl << endl << endl;
    sleep_for(seconds(7));
}

// int main() {
//     NPC firstKill("Charlie");
//     NPC secondKill("Fred");
//     endOfRoundScreen(1, &firstKill);
//     sleep_for(seconds(5));
//     endOfRoundScreen(2, &firstKill, &secondKill);
// }

#endif
