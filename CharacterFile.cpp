#include "CharacterFile.h"
#include "GameManager_v2.h"
#include "Alibi.h"

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
CharacterFile::~CharacterFile() {
    delete npc;
}
// Got rid of displayName and Ascii - Esra P.
void CharacterFile::displayCatchphrase()
{
    // checks if character is dead or alive
    if (npc->getAlive() == false)
    {
        cout << "..." << endl;
        return;
    }
    
    // randomly pull one of the three catchphrases
    int i = rand() % 3;
    cout << catchphrase[i] << endl;
}
    
void CharacterFile::displayMotive()
{
    // checks if character is dead or alive
    if (npc->getAlive() == false)
    {
        cout << "..." << endl;
        return;
    }
    
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
    // checks if character is dead or alive
    if (npc->getAlive() == false)
    {
        cout << "..." << endl;
        return;
    }
    
    string room = getRoom();
    int roomCount = countPeopleInRoom(characters, count, room, this);
    string secondPerson = getSecondPerson(characters, count, room, this);

    cout << endl;
    
    // dialogue for each room
    if (room == "Engine Car")
    {
        cout << "I was in the Engine Car.";
    }
    else if (room == "Baggage Car")
    {
        cout << "I was in the Baggage Car.";
    }
    else if (room == "Dining Car")
    {
        cout << "I was in the Dining Car.";
    }
    else if (room == "Parlor Car")
    {
        cout << "I was in the Parlor Car.";
    }
    else if (room == "Observation Car")
    {
        cout << "I was in the Observation Car.";
    }
    else if (room == "Compartment Coach")
    {
        cout << "I was in the Compartment Coach.";
    }
    else
    {
        cout << "I can't remember where I was.";
    }

    // checks if this character is the murderer
    if (npc->getInnocent() == false)
    {
        if (roomCount == 0)
        {
            cout << " I was by myself." << endl;
        }
        else
        {
            // murderer only names the first person in the room
            cout << " I was with " << secondPerson << "." << endl;
        }
    }
    
    // regular character alibi
    else
    {
        if (roomCount == 0)
        {
            cout << " I was by myself." << endl;
        }
        else if (roomCount == 1)
        {
            cout << " I was with " << secondPerson << ". They can confirm." << endl;
        }
    }
}

void CharacterFile::displayAccuse() {
    
    // checks if character is dead or alive
    if (npc->getAlive() == false)
    {
        cout << name << " IS DEAD." << endl;
        cout << "THEY CANNOT RESPOND TO YOUR ACCUSATION." << endl << endl;
        return;
    }
    
    // checks if you didn't already falsely accuse them
    if (npc->getTalksToForgiveness() != 0)
    {
        cout << "YOU FALSELY ACCUSED THIS PERSON. THEY WON'T TALK TO YOU RIGHT NOW." << endl;
        return;
    }
    
    cout << endl;
    cout << "\"How dare you! Of course I am not the murderer.\"" << endl << "YOU HAVE ACCUSED AN INNOCENT BYSTANDER." << endl;
    npc->accuseTalks();
    gm->incrementTalks();
    
    // if innocent, go back to selectionScreen
    // need to test
}
