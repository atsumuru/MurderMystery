#include "CharacterFile.h"
#include "GameManager_v2.h"

// holds default values for testing
CharacterFile::CharacterFile()
{
    ascii = "ASCII PLACEHOLDER";
    
    name = "HONORIFIC FIRST LAST";
    nickName = "HONORIFIC LAST";
    
    catchphrase[0] = "\"CHARACTER Catchphrase #1\"";
    catchphrase[1] = "\"CHARACTER Catchphrase #2\"";
    catchphrase[2] = "\"CHARACTER Catchphrase #3\"";
    
    motive[0] = "DEFAULT Positive Motive";
    motive[1] = "DEFAULT Neutral Motive";
    motive[2] = "DEFAULT Negative Motive";
    
    npc = new NPC();
}

CharacterFile::CharacterFile(GameManager* gm) {
    ascii = "ASCII PLACEHOLDER";
    
    name = "HONORIFIC FIRST LAST";
    nickName = "HONORIFIC LAST";
    
    catchphrase[0] = "\"CHARACTER Catchphrase #1\"";
    catchphrase[1] = "\"CHARACTER Catchphrase #2\"";
    catchphrase[2] = "\"CHARACTER Catchphrase #3\"";
    
    motive[0] = "DEFAULT Positive Motive";
    motive[1] = "DEFAULT Neutral Motive";
    motive[2] = "DEFAULT Negative Motive";
    
    this->gm = gm;
    npc = new NPC();
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
    // randomly pull one of the three motives
    int i = rand() % 3;
    cout << motive[i] << endl;
} 
// Added by Esra
ostream& operator <<(ostream& os, const CharacterFile& cf) {
    os << cf.name << endl << cf.ascii << endl; 
    return os;
}

string CharacterFile::getName() const
{
    return name;
}

string CharacterFile::getNickName() const
{
    return nickName;
}

void CharacterFile::setRoom(string newRoom)
{
    room = newRoom;
}

string CharacterFile::getRoom() const
{
    return room;
}

void CharacterFile::displayAlibi(CharacterFile* characters[], int count)
{
    cout << "I was in the " << room << "." << endl;
}

void CharacterFile::accuse() {
    cout << "\"How dare you! Of course I am not the murderer.\"" << endl << "YOU HAVE ACCUSED AN INNOCENT BYSTANDER." << endl;
    npc->accuseTalks();
    gm->incrementTalks();
}
