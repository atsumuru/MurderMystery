#ifndef GAMEMANAGER_CPP
#define GAMEMANAGER_CPP

#include <iostream>
#include <fstream>

#include "GameManager_v2.h"

GameManager::GameManager(int charNum) : numOfChars(charNum) {
	cout << "Initialized!" << endl;
	// put file io to import the array of names and files
	string names[10] = { "Anna", "Bobby", "Cora", "Dan", "Eve", "Fred", "George", "Henry", "Isabelle", "Jake" };
	string files[10] = { "Anna", "Bobby", "Cora", "Dan", "Eve", "Fred", "George", "Henry", "Isabelle", "Jake" };
	whichIsMurderer = rand() % 10 + 1;
	for (int i = 0; i < charNum; i++) {
		if (i == whichIsMurderer) {
			characters[i] = new Murderer(names[i]);
			cout << "Murderer created!" << endl;
		}
		else {
			characters[i] = new NPC(names[i]);
			cout << "NPC created!" << endl;
		}
	}
	cout << "end of for loop" << endl;
	NPCsLeft = charNum - 1;
	roundsDone = 0;
	talksInRound = 0;
	talksLeft = 0;
	cout << talksLeft << endl;
	switch (charNum) {
	case 10: talksInRound = 4; break;
	default: talksInRound = 4; break;
	}
	talksLeft = talksInRound;
	isWin = false;
	cout << talksLeft << endl;
}
GameManager::~GameManager() {
	for (int i = 0; i < 10; i++) {
		delete characters[i];
	}
	//delete[] characters;
}
void GameManager::incrementTalks() { talksLeft--; }
void GameManager::startRound() { talksLeft = talksInRound; }
void GameManager::checkAlives() {
	int x = 0;
	for (int i = 0; i < numOfChars; i++) {
		if (characters[i]->getAlive()) {
			x++;
		}
	}
	NPCsLeft = x;
}
void GameManager::endRound() { 
	roundsDone++;
	characters[whichIsMurderer]->newChance();
	characters[whichIsMurderer]->doesKill(characters);
	checkAlives();
}
void GameManager::run() {
	// start screen
	// select screen
	cout << "rounds: " << roundsDone << endl;
	cout << "characters: " << NPCsLeft << endl;
	startRound();
	cout << "talks: " << talksLeft << endl;
	while (talksLeft > 0) {
		// operate logic
		incrementTalks();
		cout << "talks: " << talksLeft << endl;
	}
	endRound();
	cout << "rounds: " << roundsDone << endl;
	cout << "characters: " << NPCsLeft << endl;
	cout << "talks: " << talksLeft << endl;
}
int GameManager::getRoundsDone() { return roundsDone; }
int GameManager::getTalksLeft() { return talksLeft; }
int GameManager::getNPCsLeft() { return NPCsLeft; }
NPC* GameManager::getNPC(int i) { return characters[i]; }

#endif