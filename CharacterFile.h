#ifndef CHARACTERFILE_H
#define CHARACTERFILE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "NPCClass_v2.h"

class GameManager;

using namespace std;

class CharacterFile {
protected:
    string ascii; 
    string name;
    string nickName;
    string room;
    
    string catchphrase[3];
    string motive[3];
    
public:
    NPC* npc;
    GameManager* gm;
    CharacterFile();
    CharacterFile(GameManager* gm);
    // "virtual" allows the child objects to be properly destroyed
    virtual ~CharacterFile();
    // Got rid of displayAscii and displayName for cout override - Esra P.
    void displayCatchphrase();
    void displayMotive(); 
    bool displayAccuse();

    string getName() const;
    string getNickName() const;
    void setRoom(string newRoom);
    string getRoom() const;
    virtual void displayAlibi(CharacterFile* characters[], int count);
    
    friend ostream& operator <<(ostream& os, const CharacterFile&); // Prototype for override operator - Esra P.
};

#endif
