#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "CharacterFile.h"
#include "Alibi.h"

class Conductor : public CharacterFile
{
public:
    Conductor();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
