// Gabrielle de Leeuw
// 10/27/26 [created NPC class], 10/28/26 [created Murderer class, added a bit of fio to NPC and Murderer]
// Header file for NPC and Murderer classes

#ifndef NPCCLASS_H
#define NPCCLASS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class NPC {
protected:
	bool isAlive;
	bool isInnocent;
	int talksToForgiveness;
	string name;
	string motive[9];
	string alibi;
	string dialogue[5];
public:
	NPC() {
		isAlive = true;
		isInnocent = true;
		talksToForgiveness = 0;
	}
	NPC(string name, string file) : name(name) {
		isAlive = true;
		isInnocent = true;
		talksToForgiveness = 0;
		ifstream fin(file);
		if (fin.is_open()) {
			// insert here later: file input/output to initialize motive, alibi, and dialogue based on file name
		}
		fin.close();
	}
	void kill() { isAlive = false; }
	void accuse() { talksToForgiveness = 3; }
	string dialogueLine() {
		int x = rand() % 5;
		return dialogue[x];
	}
	bool getAlive() { return isAlive; }
	bool getInnocent() { return isInnocent; }
	int getTalksToForgiveness() { return talksToForgiveness; }
	string getName() { return name; }
	string getAlibi() { return alibi; }
	string getMotive(int n) { return motive[n]; }
};

class Murderer : public NPC {
protected:
	bool killTwice;
	bool lastWrongAccuse;
	int numberToKill;
public:
	Murderer(string name, string file) : NPC() {
		isInnocent = false;
		lastWrongAccuse = false;
		numberToKill = 0;
		this->name = name;
		ifstream fin(file);
		if (fin.is_open()) {
			// insert here later: file input/output to initialize motive, alibi, and dialogue based on file name
		}
		fin.close();
	}
	void newChance() { // calculate chance of second kill, should be executed after last talk of the round but before round end
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
	void doesKill(NPC* n) { // input array of characters
		for (int i = 0; i < numberToKill; i++) { // kill number of times determined by numberToKill
			int x = rand() % 10 + 1;
			while (n[x].getInnocent() == false) { // make sure murderer does not target themselves
				x = rand() % 10 + 1;
			}
			n[x].kill();
		}
	}
};

#endif
