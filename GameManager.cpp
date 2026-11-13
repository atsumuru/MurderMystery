#ifndef GAMEMANAGER_CPP
#define GAMEMANAGER_CPP

#include <iostream>
#include <fstream>

#include "GameManager_v2.h"
#include "CharacterFile.h"

GameManager::GameManager(int charNum){
	numOfChars = charNum;
	whichIsMurderer = rand() % 10 + 1;
	for(int i = 0; i < 10; i++) {
	    characters[i] = new CharacterFile(this);
	    characters[i]->gm = this;
	}
	for (int i = 0; i < charNum; i++) {
		if (i == whichIsMurderer) {
			characters[i]->npc = new Murderer();
		}
		else {
			characters[i]->npc = new NPC();
		}
	}
	NPCsLeft = charNum - 1;
	roundsDone = 0;
	talksInRound = 0;
	talksLeft = 0;
	switch (charNum) {
	case 10: talksInRound = 4; break;
	default: talksInRound = 4; break;
	}
	talksLeft = talksInRound;
	isWin = false;
}
GameManager::~GameManager() {
	for (int i = 0; i < 10; i++) {
		delete characters[i];
	}
}
void GameManager::incrementTalks() { talksLeft--; }
void GameManager::startRound() { talksLeft = talksInRound; }
void GameManager::checkAlives() {
	int x = 0;
	for (int i = 0; i < numOfChars; i++) {
		if (characters[i]->npc->getAlive()) {
			x++;
		}
	}
	NPCsLeft = x;
}
void GameManager::endRound() { 
	roundsDone++;
	characters[whichIsMurderer]->npc->newChance();
	NPC* c[10];
	for(int i = 0; i < 10; i++) {
	    c[i] = characters[i]->npc;
	}
	if(NPCsLeft > 1) {
	    characters[whichIsMurderer]->npc->doesKill(c, whichIsMurderer);
	}
	checkAlives();
	// display, end of round screen
}
void GameManager::run() {
	// start round screen
	// select screen
	startRound();
	cout << "Starting round " << roundsDone << endl;
	cout << "Talks left: " << talksLeft << " ";
	while (talksLeft > 0) {
		// operate logic, interrogation screen
		incrementTalks();
		cout << talksLeft << " ";
	}
	cout << endl;
	endRound();
}
int GameManager::getRoundsDone() { return roundsDone; }
int GameManager::getTalksLeft() { return talksLeft; }
int GameManager::getNPCsLeft() { return NPCsLeft; }
NPC* GameManager::getNPC(int i) { return characters[i]->npc; }
bool GameManager::getIsWin() { return isWin;}
void GameManager::winScreen() {
	cout << R"(
	    ⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣴⠾⠛⢉⣹⣧⣤⣤⠦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣽⠷⠾⠛⠉⠀⠸⣧⣄⡈⢹⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣰⣿⣄⠀⠀⠀⠀⠀⠀⠙⠛⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢿⡀⠙⢷⣄⠀⠀⠀⠀⠀⣴⠟⠷⢀⣤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠈⠻⢦⡴⣿⣀⡀⠀⠀⠀⠛⢂⣴⡿⢿⣿⣷⣶⣶⣶⣶⣤⣀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠛⠉⢻⡆⠀⠀⠀⠙⢿⣷⣶⡿⠋⠉⠀⠈⠙⢿⣿⣷⡀⠀
⠀⠀⠀⠀⠀⠀⢀⣿⣷⢶⣤⣤⠀⠀⠀⠀⢀⠙⠋⠀⠀⠀⠀⠀⠀⠀⢹⣿⣧⠀
⠀⠀⠀⢀⣤⠀⣼⣿⣧⣰⣿⡇⠀⠀⠀⠀⢸⣷⡄⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀
⠀⠀⣴⣿⡿⠀⠀⠉⠉⠛⢿⣿⣦⠀⠀⠀⠈⢿⣿⣄⠀⠀⠀⠀⠀⠀⣾⣿⠇⠀
⠀⣸⣿⡏⠀⠀⠀⠀⠀⠀⠀⢻⣿⡆⠀⠀⠀⠈⠻⣿⣿⣶⣶⣶⣷⣄⠉⠉⠀⠀
⠀⢿⣿⡇⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⠀⠉⠉⠛⠋⠉⠁⠀⠀⠀⠀
⠀⠸⣿⣷⣄⠀⠀⠀⠀⠀⣠⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠘⠿⠏⢠⣶⣶⣶⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠙⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
	    )" << endl; // https://emojicombos.com/handcuffs
	cout << R"(
		  __   __  _______  __   __    _     _  ___   __    _ 
		 |  | |  ||       ||  | |  |  | | _ | ||   | |  |  | |
		 |  |_|  ||   _   ||  | |  |  | || || ||   | |   |_| |
		 |       ||  | |  ||  |_|  |  |       ||   | |       |
		 |_     _||  |_|  ||       |  |       ||   | |  _    |
		   |   |  |       ||       |  |   _   ||   | | | |   |
		   |___|  |_______||_______|  |__| |__||___| |_|  |__| )" << endl; // https://patorjk.com/software/taag/#p=display&f=Modular&t=YOU+WIN&x=none&v=4&h=4&w=80&we=false
	cout << "Hours Completed: " << roundsDone << endl;
	if (NPCsLeft == 10) {
		cout << "You solved the murder without any deaths!" << endl;
	}
	else {
		cout << "You solved the murder; however, " << 10 - NPCsLeft << " characters died." << endl;
	}
	cout << "The real murderer was " << characters[whichIsMurderer]->getName() << "." << endl;
};
 
void GameManager::loseScreen() {
	cout << R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠄⢤⣠⢷⣝⢦⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠒⣲⣦⣺⣳⣤⡿⠛⠃⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠉⠢⣣⣁⠀⣀⠙⢧⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⡎⠑⢤⡼⡩⡪⠷⠀⠀⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⣶⡞⢯⣠⡻⠼⡇⠀⠀⠀⡇⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡷⢌⠻⣶⡟⡄⠈⠁⠀⠀⠐⢣⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⡴⣷⣿⡗⠀⣡⠊⠻⠋⠒⢄⠀⠀⢀⠔⠙⢦⡀⠀
⠀⠀⠀⠀⠀⠀⡠⠊⠁⢺⣿⢇⠜⠁⠀⠀⠀⠀⣠⠗⠊⠀⠀⣠⡺⠆⠀
⠀⠀⠀⠀⣠⣾⡗⠀⠀⢸⡿⠋⠀⠀⠀⠀⠀⠀⠻⣆⠛⣠⣞⢕⢽⣆⠀
⠀⠀⠀⣴⣿⣿⡇⠀⢀⠞⠁⠀⠀⠀⠀⠀⠀⠀⢐⡯⡪⡫⡢⣑⣕⢕⠀
⠀⠀⣼⣿⣿⣿⠇⡰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢮⡺⣾⣮⡪⡳⠀
⢀⣼⣿⣿⣿⠿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠺⣷⣝⢮⠀
⠾⠿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠪⣻⡇

)" << endl; // https://emojicombos.com/knife

	cout << R"(
 __   __  _______  __   __    ___      _______  _______  _______ 
|  | |  ||       ||  | |  |  |   |    |       ||       ||       |
|  |_|  ||   _   ||  | |  |  |   |    |   _   ||  _____||    ___|
|       ||  | |  ||  |_|  |  |   |    |  | |  || |_____ |   |___ 
|_     _||  |_|  ||       |  |   |___ |  |_|  ||_____  ||    ___|
  |   |  |       ||       |  |       ||       | _____| ||   |___ 
  |___|  |_______||_______|  |_______||_______||_______||_______|

)" << endl;
	cout << "All characters died, leaving only you and the murderer. You were killed." << endl;
	cout << "Hours Completed: " << roundsDone << endl;
	cout << "The real murderer was " << characters[whichIsMurderer]->getName() << "." << endl;
	};

#endif
