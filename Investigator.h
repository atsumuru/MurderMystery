#ifndef INVESTIGATOR_H
#define INVESTIGATOR_H

#include "CharacterFile.h"
#include "Alibi.h"

class Investigator : public CharacterFile
{
public:
    Investigator();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
