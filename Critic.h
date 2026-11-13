#ifndef CRITIC_H
#define CRITIC_H

#include "CharacterFile.h"
#include "Alibi.h"

class Critic : public CharacterFile
{
public:
    Critic();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
