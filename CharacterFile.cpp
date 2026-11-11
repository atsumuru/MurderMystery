#include "CharacterFile.h"

// holds default values for testing
CharacterFile::CharacterFile()
{
    ascii = "ASCII PLACEHOLDER";
    
    name = "HONORIFIC FIRST LAST";
    
    catchphrase[0] = "\"CHARACTER Catchphrase #1\"";
    catchphrase[1] = "\"CHARACTER Catchphrase #2\"";
    catchphrase[2] = "\"CHARACTER Catchphrase #3\"";
    
    motive[0] = "DEFAULT Positive Motive";
    motive[1] = "DEFAULT Neutral Motive";
    motive[2] = "DEFAULT Negative Motive";
}

// runs when CharacterFile is destroyed
CharacterFile::~CharacterFile() {}

void CharacterFile::displayCharacter()
{
    cout << ascii << endl;
}
    
void CharacterFile::displayName()
{
    cout << name << endl;
}

void CharacterFile::displayCatchphrase()
{
    // randomly pull one of the three catchphrases
    int i = rand() % 3;
    cout << catchphrase[i] << endl;
}
    
void CharacterFile::displayMotive()
{
    // randomly pull one of the three motives
    int i = rand() % 3;
    cout << motive[i] << endl;
}

// friend os ...
// override
