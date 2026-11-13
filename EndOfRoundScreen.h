#ifndef ENDOFROUNDSCREEN_H
#define ENDOFROUNDSCREEN_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "NPCClass_v2.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


void clearScreenRound();

void endOfRoundScreen(int rounds, NPC* char1, NPC*char2 = NULL);
// int main() {
//     NPC firstKill("Charlie");
//     NPC secondKill("Fred");
//     endOfRoundScreen(1, &firstKill);
//     sleep_for(seconds(5));
//     endOfRoundScreen(2, &firstKill, &secondKill);
// }

#endif
