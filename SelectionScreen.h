#ifndef SELECTIONSCREEN_H
#define SELECTIONSCREEN_H

#include <iostream>
#include <string>

#include "CharacterFile.h"
#include "GameManager_v2.h"

using namespace std;

void selectionScreen();
void selectCharacter(GameManager& gm, int count);
void selectionScreenMain(GameManager& gm);

#endif
