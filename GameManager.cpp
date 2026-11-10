#ifndef GAMEMANAGER_CPP
#define GAMEMANAGER_CPP

#include <iostream>
#include <fstream>

#include "GameManager_v2.h"

inline GameManager::GameManager(int charNum){
	numOfChars = charNum;
	// put file io to import the array of names and files
	string names[10] = { "Anna", "Bobby", "Cora", "Dan", "Eve", "Fred", "George", "Henry", "Isabelle", "Jake" };
	string files[10] = { "Anna", "Bobby", "Cora", "Dan", "Eve", "Fred", "George", "Henry", "Isabelle", "Jake" };
	whichIsMurderer = rand() % 10 + 1;
	for (int i = 0; i < charNum; i++) {
		if (i == whichIsMurderer) {
			characters[i] = new Murderer(names[i]);
		}
		else {
			characters[i] = new NPC(names[i]);
		}
	}
	for (int i = 0; i < 10; i++) {
	    characters[i]->setAlibi(characters, i);
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
inline GameManager::~GameManager() {
	for (int i = 0; i < 10; i++) {
		delete characters[i];
	}
}
void inline GameManager::incrementTalks() { talksLeft--; }
void inline GameManager::startRound() { talksLeft = talksInRound; }
void inline GameManager::checkAlives() {
	int x = 0;
	for (int i = 0; i < numOfChars; i++) {
		if (characters[i]->getAlive()) {
			x++;
		}
	}
	NPCsLeft = x;
}
void inline GameManager::endRound() { 
	roundsDone++;
	characters[whichIsMurderer]->newChance();
	if(NPCsLeft > 1) {
	    characters[whichIsMurderer]->doesKill(characters, whichIsMurderer);
	}
	checkAlives();
	// display, end of round screen
}
void inline GameManager::run() {
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
int inline GameManager::getRoundsDone() { return roundsDone; }
int inline GameManager::getTalksLeft() { return talksLeft; }
int inline GameManager::getNPCsLeft() { return NPCsLeft; }
inline NPC* GameManager::getNPC(int i) { return characters[i]; }
bool inline GameManager::getIsWin() { return isWin;}
void inline GameManager::winScreen() {
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
	cout << "Hours Played: " << roundsDone << endl;
	if (NPCsLeft == 10) {
		cout << "You solved the murder without any deaths!" << endl;
	}
	else {
		cout << "You solved the murder; however, " << 10 - NPCsLeft << " characters died." << endl;
	}
	cout << "The real murderer was " << characters[whichIsMurderer]->getName() << "." << endl;
};
 
void inline GameManager::loseScreen() {
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
	cout << "Hours Played: " << roundsDone << endl;
	cout << "The real murderer was " << characters[whichIsMurderer]->getName() << "." << endl;
	};

#endif
