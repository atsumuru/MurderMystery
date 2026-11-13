#ifndef FEMMEFATALE_H
#define FEMMEFATALE_H

#include "CharacterFile.h"
#include "Alibi.h"

class FemmeFatale : public CharacterFile
{
public:
    FemmeFatale();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
