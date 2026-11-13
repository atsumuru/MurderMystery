#ifndef INTERROGATIONSCREEN_H
#define INTERROGATIONSCREEN_H

#include <iostream>
using namespace std;

#include "CharacterFile.h"
#include "GameManager_v2.h"

// CharacterFile* character points to selected character file

void characterInfo(CharacterFile* characters);
void interrogateOptions();
void interrogateChoice(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm);
void interrogationScreenMain(CharacterFile* character, CharacterFile* characters[], int count, GameManager& gm);

#endif
