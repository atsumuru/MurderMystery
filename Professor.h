#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "CharacterFile.h"
#include "Alibi.h"

class Professor : public CharacterFile
{
public:
    Professor();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
