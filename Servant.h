#ifndef SERVANT_H
#define SERVANT_H

#include "CharacterFile.h"
#include "Alibi.h"

class Servant : public CharacterFile
{
public:
    Servant();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
