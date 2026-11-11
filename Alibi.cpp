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

string setAlibi(Class* chars[10], int me) {
	if (checkOtherInAlibi(chars, int me) == 0) {
		//chars[me]->alibi = chars[me]->name " was in room " + chars[me]->room + " by themselves.";
	}
	else {
		//chars[me]->alibi = chars[me]->name " was in room " + chars[me]->room + " with " + c[checkOtherInAlibi(int* chars[10])]->name + ".";
	}
}

int  checkOtherInAlibi(Class* chars[10], int me) {
	for (int i = 0; i < 10; i++) {
			if (chars[i]->room == chars[me]->room) {
					if (i != me) {
							return i;
					}
			}
		return -1;
	}
}

#endif
