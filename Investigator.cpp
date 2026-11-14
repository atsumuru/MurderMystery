#include "Investigator.h"

Investigator::Investigator()
{
    name = "                PI PRESTON JONES";
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

    catchphrase[0] = "              \"Pass me a cigarette, won't you?\"";
    catchphrase[1] = "              \"I can't find my fedora anywhere.\"";
    catchphrase[2] = "              \"Curious.\"";

    motive[0] = "I have certainly not killed the Baron; I could not widow a lady as innocent as the Baroness. So why is the Detective in front of me asking this?";
    motive[1] = "I know where the Baron lives, the bars he goes to on a Tuesday night, and the woman he spends time with who is not his wife. But I don't know the identity of his killer.";
    motive[2] = "I can see you meaning nothing but trouble. Not only was the low-life that was Baron Hudson lying to his wife, but he was planning to tell the police that I shot that annoying police chief in Topeka.";
}

void Investigator::displayAlibi(CharacterFile* characters[], int count)
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
        fout << "Investigator was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Investigator can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Investigator was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Investigator was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
