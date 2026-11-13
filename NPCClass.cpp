// Gabrielle de Leeuw
// 10/31/26 [moved function defenitions from .h to .cpp]
// .cpp file for NPC and Murderer classes

#ifndef NPCCLASS_CPP
#define NPCCLASS_CPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

#include "NPCClass_v2.h"
//#include "Alibi.cpp"

using namespace std;

NPC::NPC() {
		isAlive = true;
		isInnocent = true;
		talksToForgiveness = 0;
}
NPC::~NPC() {
    delete this;
}
NPC::NPC(string name) : name(name) {
	isAlive = true;
	isInnocent = true;
	talksToForgiveness = 0;
	// insert here later: file input/output to initialize motive, alibi, and dialogue based on file name
	room = getRoom();
	alibi = name + " was in train car " + std::to_string(room);
}

void NPC::accuse() { 
    talksToForgiveness = 3; 
}

bool NPC::getAlive() { return isAlive; }
bool NPC::getInnocent() { return isInnocent; }
int NPC::getTalksToForgiveness() { return talksToForgiveness; }
string NPC::getName() { return name; }

void NPC::newChance() {}
vector<int> NPC::doesKill(NPC* c[10], int me) { return {-1};}

void NPC::kill() { isAlive = false; }

Murderer::Murderer(string n) {
		name = n;
		isAlive = true;
		talksToForgiveness = 0;
		isInnocent = false;
		lastWrongAccuse = false;
		numberToKill = 0;
		killTwice = false;
		this->name = name;
		room = rand() % 6 + 1; // temporary, will currently lead to 2+ in a room. This will not be the case with file io :)
	    alibi = name + " was in train car " + std::to_string(room);
			// insert here later: file input/output to initialize motive, alibi, and dialogue based on file name
}
Murderer::~Murderer() {
    delete this;
}
void Murderer::newChance() { // calculate chance of second kill, should be executed after last talk of the round but before round end
		int chanceToKillTwice = rand() % 100 + 1;
		int bar;
		if (lastWrongAccuse) {
			bar = 90;
		}
		else {
			bar = 45;
		}

		if (chanceToKillTwice <= bar) {
			numberToKill = 2;
		}
		else {
			numberToKill = 1;
		}
}
vector<int> Murderer::doesKill(NPC* n[10], int me) { // input array of characters
        int killNumber = 0;
        vector<int> kills = {-1, -1};
		for (int i = 0; i < numberToKill; i++) { // kill number of times determined by numberToKill
			int x = rand() % 10;
			while (x == me || n[x]->getAlive() == false ) { // make sure murderer does not target themselves or a dead person
				x = rand() % 10;
			}
			n[x]->kill();
			kills[killNumber] = x;
			killNumber++;
		}
		return kills;
}
bool Murderer::getInnocent() { return isInnocent; }
#endif
