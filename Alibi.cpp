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
    for(int i = 0; i < count; i++)
    {
        int randomRoom = rand() % 6;
        characters[i]->setRoom(rooms[randomRoom]);
    }
}

// count how many people are in the room
int countPeopleInRoom(CharacterFile* characters[], int count, string room)
{
    int roomCount = 0;
    for (int i = 0; i < count; i++)
    {
        if (characters[i]->getRoom() == room)
        {
            roomCount++;
        }
    }
    
    return roomCount;
}

