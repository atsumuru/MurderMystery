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

    catchphrase[0] = "              \"INVESTIGATOR Catchphrase #1\"";
    catchphrase[1] = "              \"INVESTIGATOR Catchphrase #2\"";
    catchphrase[2] = "              \"INVESTIGATOR Catchphrase #3\"";

    motive[0] = "INVESTIGATOR Positive Motive";
    motive[1] = "INVESTIGATOR Neutral Motive";
    motive[2] = "INVESTIGATOR Negative Motive";
}

void Investigator::displayAlibi(CharacterFile* characters[], int count)
{
    ofstream fout("NotePad.txt", ios::app);
    string room = getRoom();
    int roomCount = countPeopleInRoom(characters, count, room, this);
    string secondPerson = getSecondPerson(characters, count, room, this);

    cout << endl;
    // dialogue for each room
    if(room != null)
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
