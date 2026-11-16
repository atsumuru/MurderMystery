#ifndef INTERROGATIONSCREEN_H
#define INTERROGATIONSCREEN_H

#include <iostream>
#include <cctype>
using namespace std;

#include "CharacterFile.h"
#include "GameManager_v2.h"

// CharacterFile* character points to selected character file

void characterInfo(CharacterFile* characters);
void interrogateOptions();

// changed to bool to keep track of interrogations
bool interrogateChoice(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm);
bool interrogationScreenMain(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm);

#endif
