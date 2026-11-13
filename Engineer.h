#ifndef ENGINEER_H
#define ENGINEER_H

#include "CharacterFile.h"
#include "Alibi.h"

class Engineer : public CharacterFile
{
public:
    Engineer();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
