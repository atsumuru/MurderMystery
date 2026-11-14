#include "FemmeFatale.h"

FemmeFatale::FemmeFatale()
{
    name = "                MADAME MARGAUX ROUGÊ";
    nickName = "Madame Rougê";

    ascii = R"(
                    -+#######*--                   
                 *##*####*+***####*                
               #*=---=+#*+=-+*%*#**#*              
              **#%%++**=+=*#%%**%*+**+             
             *%%%%%%#*=*=*%###%#*%#**#+            
             %%#%%%#%%*-+*.       .=#*%            
            :%%%##%%##*+*=         .-#*#           
           ##***%#%**#+*#*+-    :=+*##*#           
            %###%*==*+*%%%#=.  :*%%%##*#           
            %##***#++#:##:=:   :#::*=#*#           
          .#++##+++#+=:...      ... .**#           
         :*+*+***==-:           .   .+*%+          
         #+-+=***=+:         .-*-   :**# =*        
        .**+--=#*=+#:      -  .    .*++**   +      
      :- :#*+=-=*++#*.    :===*=. .##*++##= +      
      =  :*+**=-=#*#*::.    .:.  -####*++**#       
      =  -*++#*-=*##*..:*-.    :######+=#+##       
       =-#+++*#-=###.   .:++*########+*###*        
      -**++*#**+*%*:       .-%%#####**###+=        
     #++**#**###%%=:.       :+##%####++###..=      
    %++####*+:.-%#- .::      ..:##=..=**#*%.=      
    %**#+-.   .%#+      .:...:. .+#%:...-**#+      
    :#+.      +##+          :.    *##=....*#+      
     =        *##*:.             .:%*#-....*       
    *.       =#****###%%%%+--*%%##***#%+....=      
    )";

    catchphrase[0] = "              \"Oh, it's you again.\"";
    catchphrase[1] = "              \"Diamonds are a girl's best friend, didn't you know that?\"";
    catchphrase[2] = "              \"Make it quick- I'm a very busy woman.\"";

    motive[0] = "Such a shame to lose Charles. A man as handsome as that is wasted on death. Oh well; I suppose that's just how these things go.";
    motive[1] = "Isn't the wife usually the primary suspect? She's the one who got his money in the end, after all.";
    motive[2] = "It's really too bad that Charles is dead. Anyway, did I tell you about my recent shopping spree? My... um... third cousin twice removed sent me a fortune.";
}

void FemmeFatale::displayAlibi(CharacterFile* characters[], int count)
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
        fout << "Femme Fatale was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Femme Fatale can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Femme Fatale was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Femme Fatale was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
