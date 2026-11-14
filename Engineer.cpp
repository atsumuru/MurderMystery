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

    catchphrase[0] = "              \"Hey-ya!\"";
    catchphrase[1] = "              \"This engine's purring something fierce.\"";
    catchphrase[2] = "              \"Can I help ya?\"";

    motive[0] = R"(
            "I was sent by High-Top Rail Co. to serve as Mistah Hudson's train mechanic! I 
             was reals excited to work on this beauty me and they boys help make, though
             I'll say, Mistah Hudson kinda gave me bad feels."
            )";
    motive[1] = R"(
            "I don't wanna gets in trouble, so keep this between us, k? Mistah Hudson was 
             a real scurvy fella. He had me and the boys make this here train for 'im, 
             but then he cut us our pay. It was downright dishonest!"
            )";
    motive[2] = R"(
            "My momma always taught me to stand up for myself, and I was so scared for the 
             longest time to stand up to wealthy fellas. But, what Mistah Hudson done is 
             too unfair. He treated us as free labours to make this train. I may not 
             know much, but I knows that this was prevented by Mistah Lincoln."
            )";
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
