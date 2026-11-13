#ifndef BARTENDER_H
#define BARTENDER_H

#include "CharacterFile.h"
#include "Alibi.h"

class Bartender : public CharacterFile
{
public:
    Bartender();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
