// Gabrielle de Leeuw
// 10/27/26 [created NPC class], 10/28/26 [created Murderer class, added a bit of fio to NPC and Murderer], 
// 10/29/2026 [removed file io], 10/31/2026 [fixed errors]
// Header file for NPC and Murderer classes

#ifndef NPCCLASS_H
#define NPCCLASS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//#include "NPCClass.cpp"

using namespace std;

class NPC {
protected:
	bool isAlive;
	bool isInnocent;
	int talksToForgiveness;
	string name;
	//string motive[9];
	//string alibi;
	//string dialogue[5];
	//int room;
public:
	NPC();
    virtual	~NPC();
	NPC(string name);
	void kill();
	void accuse();
	//string dialogueLine();
	bool getAlive();
	bool getInnocent();
	int getTalksToForgiveness();
	string getName();
	//string getMotive(int n);
	virtual void newChance(); // to make murderer work
	virtual vector<int> doesKill(NPC* c[10], int me); // to make murderer work
	//int checkOtherInAlibi(NPC* c[10], int me);
	//int getRoom();
};

class Murderer : public NPC {
protected:
	bool killTwice;
	bool lastWrongAccuse;
	int numberToKill;
public:
	Murderer(string n);
	~Murderer();
	void newChance();
	vector<int> doesKill(NPC* n[10], int me);
	bool getInnocent();
};

#endif
