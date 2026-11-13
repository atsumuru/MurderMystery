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
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
    }
}
