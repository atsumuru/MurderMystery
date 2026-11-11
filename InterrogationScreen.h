#ifndef INTERROGATIONSCREEN_H
#define INTERROGATIONSCREEN_H

#include <iostream>
using namespace std;

#include "CharacterFile.h"

// CharacterFile* character points to selected character file

void characterInfo(CharacterFile* character);
void interrogateOptions();
void interrogateChoice(CharacterFile* character);
void interrogationScreenMain(CharacterFile* character);

#endif
