#ifndef ENDOFROUNDSCREEN_H
#define ENDOFROUNDSCREEN_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "NPCClass_v2.h"
#include "ClearScreen.h"

using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

void endOfRoundScreen(int rounds, NPC* char1, NPC*char2 = nullptr);

#endif
