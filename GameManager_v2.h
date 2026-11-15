// Gabrielle de Leeuw
// 10/28/2026 [created class]
// Header file for GameManager class

#ifndef GAMEMANAGER_V2_H
#define GAMEMANAGER_V2_H

#include <iostream>
#include <string>
#include <fstream>
#include "NPCClass_v2.h"
#include "CharacterFile.h"

using namespace std;

class CharacterFile;

class GameManager {
protected:
	int numOfChars;
	int whichIsMurderer;
	int NPCsLeft;
	int roundsDone;
	int talksInRound;
	int talksLeft;
	bool isWin;
	
	bool talkedTo[10];    // tracks which characters have been interrogated (t/f)
	int peopleInterrogated; // tracks the number of different characters you've interrogated
public:
    CharacterFile* characters[10];
	GameManager(int charNum);
	~GameManager();
	void incrementTalks();
	void setCharacterFiles();
	void startRound();
	void checkAlives();
	void endRound();
	void run();
	
	bool countInterrogation(int charIndex); // count each interrogation
	bool getCompletedInterrogation(); // tells you when you interrogated 4 people
	
	int getRoundsDone();
	int getTalksLeft();
	int getNPCsLeft();
	NPC* getNPC(int i);
	bool getIsWin();
    void setIsWin(bool value); //
	void winScreen();
	void loseScreen();
	int getWhichIsMurderer();
};

#endif
