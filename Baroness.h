#ifndef BARONESS_H
#define BARONESS_H

#include "CharacterFile.h"
#include "Alibi.h"

class Baroness : public CharacterFile
{
public:
    Baroness(); 
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif 
