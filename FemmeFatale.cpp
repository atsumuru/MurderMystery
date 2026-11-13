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

    catchphrase[0] = "              \"FEMME FATALE Catchphrase #1\"";
    catchphrase[1] = "              \"FEMME FATALE Catchphrase #2\"";
    catchphrase[2] = "              \"FEMME FATALE Catchphrase #3\"";

    motive[0] = "FEMME FATALE Positive Motive";
    motive[1] = "FEMME FATALE Neutral Motive";
    motive[2] = "FEMME FATALE Negative Motive";
}

void FemmeFatale::displayAlibi(CharacterFile* characters[], int count)
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
