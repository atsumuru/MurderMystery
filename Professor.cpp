#include "Professor.h"

Professor::Professor()
{
    name = "                PROFESSOR ARCHWIN STEIN";
    nickName = "Professor Stein";

    ascii = R"(
                   :++=--=+++++                   
                -*=:-====::-.-==+*:               
              -=..  ....:--:: :=::-+:             
             =-=:  ::..:--==. .:=:.:+-            
            :=:. .::===::::-+==:::==-+.           
            =-:.:-*:.              :==.           
           .+:.-+--=.=#%%%*:   :#%#=*=.           
           .+-=+=-+:.======.   -===+*+            
            :-*  -:.++-+:--+. =++:-+*             
           +=-*.- . =.:::..=..=:::::+             
             +=+. .            .    .             
              *=++=           .-   .+             
               .====         .::  .*              
              -*+=-+=.    .-=-=:  +               
                  *+=--.   .==:  -:               
                  =:-.:==.     :=                 
                   +.  .:=++++-                   
                 *-=     .::*#-                   
              :-*-.-=       =+-*:::               
           +=:.  *:...*-.   +: -*..:=+.           
       .*=        -=.    :##:  .*    ..:=         
     .=.           .-=   +###=:.*     ...=        
    .=                -**=###*..  .  .....*       
    *.       -.          :##*#:    ..:=.. .+      
    )";

    catchphrase[0] = "              \"My, what a mystery you have on your hands!\"";
    catchphrase[1] = "              \"This locomotive really is quite the marvel of modern science.\"";
    catchphrase[2] = "              \"Do you have a hypothesis yet as to the identity of the murderer?\"";

    motive[0] = R"(
            "I feel so badly for poor Madame Rouge- it must be so hard for her to have the Baron die so suddenly. And no, 
             of course I did not kill him."
            )";
    motive[1] = R"(
            "Charles and I weren't the closest back in school- I was the better student. Why would I want to kill him?"
            )";
    motive[2] = R"(
            "Charles always was a leech, even back in school. Margaux deserves better than being his second choice. I 
             don't mourn his loss."
            )";
}

void Professor::displayAlibi(CharacterFile* characters[], int count)
{
    ofstream fout("NotePad.txt", ios::app);
    string room = getRoom();
    int roomCount = countPeopleInRoom(characters, count, room, this);
    string secondPerson = getSecondPerson(characters, count, room, this);

    cout << endl;
    // dialogue for each room
    if(!room.empty())
    {
        cout << "I was in the " << room << ".";
        fout << "Professor was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Professor can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Professor was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Professor was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
