#ifndef DOCTOR_H
#define DOCTOR_H

#include "CharacterFile.h"
#include "Alibi.h"

class Doctor : public CharacterFile
{
public:
    Doctor();
    void displayAlibi(CharacterFile* characters[], int count) override;
};

#endif
