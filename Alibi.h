#ifndef ALIBI_H
#define ALIBI_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "CharacterFile.h"

using namespace std;

void assignRoom(CharacterFile* characters[], int count);
int countPeopleInRoom(CharacterFile* characters[], int count, string room);

#endif
