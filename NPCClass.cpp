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

#include "NPCClass_v2.h"

using namespace std;

inline NPC::NPC() {
		isAlive = true;
		isInnocent = true;
		talksToForgiveness = 0;
}
inline NPC::~NPC() {
    delete this;
}
inline NPC::NPC(string name) : name(name) {
	isAlive = true;
	isInnocent = true;
	talksToForgiveness = 0;
	// insert here later: file input/output to initialize motive, alibi, and dialogue based on file name
	room = rand() % 6 + 1; // temporary, will currently lead to 2+ in a room. This will not be the case with file io :)
	alibi = name + " was in train car " + std::to_string(room);
}
void inline NPC::setAlibi(NPC* c[10]) {
	if( this->checkOtherInAlibi(c) == 0 ) {
		alibi = alibi + " by themselves.";
	} else {
		alibi = alibi + " with " + c[this->checkOtherInAlibi(c)]->name + ".";
	}
}
string inline NPC::getAlibi() { return alibi; }
void inline NPC::kill() { 
    isAlive = false; 
}
void inline NPC::accuse() { 
    talksToForgiveness = 3; 
}
string inline NPC::dialogueLine() {
	int x = rand() % 5;
	return dialogue[x];
}
bool inline NPC::getAlive() { return isAlive; }
bool inline NPC::getInnocent() { return isInnocent; }
int inline NPC::getTalksToForgiveness() { return talksToForgiveness; }
string inline NPC::getName() { return name; }
string inline NPC::getAlibi() { return alibi; }
string inline NPC::getMotive(int n) { return motive[n]; }
void inline NPC::newChance() {}
void inline NPC::doesKill(NPC* c[10]) {}
int inline NPC::checkOtherInAlibi(NPC* c[10]) {
	for (int i = 0; i < 10; i ++) {
		if(c[i]->getRoom() == room) {
			return i;
		}
	}
	return 0;
}
int inline NPC::getRoom() { return room; }

inline Murderer::Murderer(string n) {
		name = n;
		isAlive = true;
		talksToForgiveness = 0;
		isInnocent = false;
		lastWrongAccuse = false;
		numberToKill = 0;
		this->name = name;
			// insert here later: file input/output to initialize motive, alibi, and dialogue based on file name
}
inline Murderer::~Murderer() {
    delete this;
}
void inline Murderer::newChance() { // calculate chance of second kill, should be executed after last talk of the round but before round end
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
void inline Murderer::doesKill(NPC* n[10]) { // input array of characters
		for (int i = 0; i < numberToKill; i++) { // kill number of times determined by numberToKill
			int x = rand() % 10 + 1;
			while (n[x]->getInnocent() == false) { // make sure murderer does not target themselves
				x = rand() % 10 + 1;
			}
			n[x]->kill();
		}
}
bool inline Murderer::getInnocent() { return isInnocent; }
#endif
