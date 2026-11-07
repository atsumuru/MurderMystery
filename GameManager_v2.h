// Gabrielle de Leeuw
// 10/28/2026 [created class]
// Header file for GameManager class

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "NPCClass.cpp"
#include "NPCClass_v2.h"

using namespace std;

class GameManager {
protected:
	NPC* characters[10];
	int numOfChars;
	int whichIsMurderer;
	int NPCsLeft;
	int roundsDone;
	int talksInRound;
	int talksLeft;
	bool isWin;
public:
	GameManager(int charNum);
	~GameManager();
	void incrementTalks();
	void startRound();
	void checkAlives();
	void endRound();
	void run();
	int getRoundsDone();
	int getTalksLeft();
	int getNPCsLeft();
	NPC* getNPC(int i);
};

#endif
