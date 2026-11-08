#include "CharacterFile.h"

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
