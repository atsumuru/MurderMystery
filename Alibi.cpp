#include "Alibi.h"

string rooms[6] =
{
    "Engine Car",
    "Baggage Car",
    "Dining Car",
    "Parlor Car",
    "Observation Car",
    "Compartment Coach"
};

// assign room location
void assignRoom(CharacterFile* characters[], int count)
{
    // start every room at 0
    int roomCount[6] = {0};
    
    // goes through character array
    for(int i = 0; i < count; i++)
    {
        int randomRoom = rand() % 6;
        
        // find a room with fewer than two characters
        while (roomCount[randomRoom] >= 2)
        {
            randomRoom = rand() % 6;
        }
        
        // assigns characters a room
        characters[i]->setRoom(rooms[randomRoom]);
        roomCount[randomRoom]++;
    }
}

// count how many other people are in the room
int countPeopleInRoom(CharacterFile* characters[], int count, string room, CharacterFile* currentCharacter)
{
    int roomCount = 0;
    for (int i = 0; i < count; i++)
    {
        // checks another character exists and is assigned in the same room
        // does not include itself
        if (characters[i] != nullptr && characters[i] != currentCharacter && characters[i]->getRoom() == room)
        {
            roomCount++;
        }
    }
    
    return roomCount;
}

// used AI to getSecondPerson to integrate with the rest of the characterFiles
// also helped figure out there was a big issue with creating new objects in selection screen


// find nickname for the character in the other room
string getSecondPerson(CharacterFile* characters[], int count, string room, CharacterFile* currentCharacter)
{
    for (int i = 0; i < count; i++)
    {
        if (characters[i] != nullptr && characters[i] != currentCharacter && characters[i]->getRoom() == room)
        {
            return characters[i]->getNickName();
        }
    }

    return "";
}

