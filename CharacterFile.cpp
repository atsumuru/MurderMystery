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
// Got rid of displayName and Ascii - Esra P.
void CharacterFile::displayCatchphrase()
{
    // randomly pull one of the three catchphrases
    int i = rand() % 3;
    cout << catchphrase[i] << endl;
}
    
void CharacterFile::displayMotive()
{ 
    ofstream fout("NotePad.txt", ios::app);
    // randomly pull one of the three motives
    int i = rand() % 3;
    cout << motive[i] << endl; 
    fout << motive[i] << endl; 
    fout.close();
} 
// Added by Esra
ostream& operator <<(ostream& os, const CharacterFile& cf) {
    os << cf.name << endl << cf.ascii << endl; 
    return os;
}
