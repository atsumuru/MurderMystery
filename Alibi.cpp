#ifndef ALIBI_CPP
#define ALIBI_CPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int setRoom() {
	int room = rand() % 6 + 1; // temporary, will currently lead to 2+ in a room. This will not be the case with file io :)
	return room;
}

string setAlibi(Character* chars[10], int me) {
	if (checkOtherInAlibi(chars, me) == 0) {
		string temp = chars[me]->getName() + " was in room " + chars[me]->getRoom() + " by themselves.";
		return temp;
	}
	else {
		string temp = chars[me]->getName() + " was in room " + chars[me]->getRoom() + " with " + c[checkOtherInAlibi(int* chars[10])]->name + ".";
		return temp;
	}
}

int  checkOtherInAlibi(Character* chars[10], int me) {
	for (int i = 0; i < 10; i++) {
			if (chars[i]->getRoom() == chars[me]->getRoom() {
					if (i != me) {
							return i;
					}
			}
		return -1;
	}
}

#endif
