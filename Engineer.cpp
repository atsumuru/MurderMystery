#include "Engineer.h"

Engineer::Engineer()
{
    name = "                MS. CASSIE (CASSANDRA) HARDWELL";
    nickName = "Ms. Hardwell";

    ascii = R"(
                    +%%##%%%%++                   
                =%%######*##*#%%##**              
              :%**+**+==**+-###+:=*#--            
             =###*+*#+==###-##*+ ###*=            
            .%#*+##*###*:-=##%#%*=:-%%            
            .#**##*##**#%*#=--==##%*%#%=+.        
            %#*##*%##*#*##*-----#%%*%%#@          
            %@###%#####***#*---+#*#%#%@%+         
           *###*%%#=+#%%%:==---#%-*%%%@           
          %*###=+-=-=# *+  ----*+  *#%%           
         =####%*=-=-----------------+%%           
          %#*#%##*+---------- -*----**#%-         
          %#**###%%+----------=----+#***+         
        =%%%#*%###%#+----==++**=--+#%%#%          
          ##*#%%#*##++=----=**=--+#*%#*@          
          %*#%@%##%%+=+*+------=####%#%           
           %%: -%#%-.*++++****#%%#%@%%#%*         
            %%   #+..    ...* %  %                
              ..- .         *:-- ..               
           +%##-          .      :#%:=            
        +:  :#*+                 .##*   -         
      -      +*#:                 =##:   -        
     :        %*#:                +##+    +       
    +        :%#: %#************##. %%=    =      
    )";

    catchphrase[0] = "              \"ENGINEER Catchphrase #1\"";
    catchphrase[1] = "              \"ENGINEER Catchphrase #2\"";
    catchphrase[2] = "              \"ENGINEER Catchphrase #3\"";

    motive[0] = "ENGINEER Positive Motive";
    motive[1] = "ENGINEER Neutral Motive";
    motive[2] = "ENGINEER Negative Motive";
}

void Engineer::displayAlibi(CharacterFile* characters[], int count)
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
        fout << "Engineer was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Engineer can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Engineer was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Engineer was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
