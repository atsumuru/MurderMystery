#ifndef BARONESS_H
#define BARONESS_H

#include "characterFile.h"

class Baroness : public CharacterFile
{
public:
    Baroness(); 
    friend ostream& operator <<(const& os, const& Baroness); //This is the prototype for the ostream override
};

#endif
