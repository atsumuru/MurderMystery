#include "Investigator.h"

Investigator::Investigator()
{
    name = "PI PRESTON JONES";
    nickName = "Mr. Jones";

    ascii = R"(
                    *%%###%%%**                   
              @#@@%#######*#*###%@:               
              @%##++**###%#*#+*##*#%.             
           @#%%#**####+**##%*+*###*#%:            
            #@######%+*###%+++=--#%##%            
            *#*###%%*#@%*#+        *#%            
            %+*#%#*%#@+%%%*     +@%*@%            
            %*#=+#%##@+=#=.    :==--##            
            .#*  =#=-@-=%==   .=+**++             
           ###* - #-  ::       .:. :=             
             *#=  =*                              
              @#*+=.           =    -             
                %##-      :*#%%%.  --             
              -@%%##:   -%###*#%#=:               
                  @#=:      ::   =                
                  =:: :+:      .:                 
                 -+#*   -=++==+                   
               *=-****++  .:*+==*                 
             ==---****==    *#*==+:               
           +*-::---****-#   ##%*=--*+=            
        *=-:-+-.:--+####:*.+#%#*+---*+==-         
      =---:.::=+-=++**###==*%#***+++++-==*        
     +:.:---::-=*=--+#***#=+#****--=*+-===*       
    +:::.:--=-:=+:.:-*#***+.#****:.-+=---==+
    )";

    catchphrase[0] = "\"INVESTIGATOR Catchphrase #1\"";
    catchphrase[1] = "\"INVESTIGATOR Catchphrase #2\"";
    catchphrase[2] = "\"INVESTIGATOR Catchphrase #3\"";

    motive[0] = "INVESTIGATOR Positive Motive";
    motive[1] = "INVESTIGATOR Neutral Motive";
    motive[2] = "INVESTIGATOR Negative Motive";
}

void Investigator::displayAlibi(CharacterFile* characters[], int count)
{
    string room = getRoom();
    
    int roomCount = countPeopleInRoom(characters, count, room);

    string secondPerson = "";

    for (int i = 0; i < count; i++)
    {
        if (characters[i] != this && characters[i]->getRoom() == room)
        {
            secondPerson = characters[i]->getNickName();
            break;
        }
    }

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
    
    //if they end up with someone
    if (roomCount == 1)
    {
        cout << "I was by myself." << endl;
    }
    else if (roomCount == 2)
    {
        cout << "I was with " << secondPerson << ". They can confirm." << endl;
    }
}
