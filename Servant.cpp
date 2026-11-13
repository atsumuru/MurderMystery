#include "Servant.h"

Servant::Servant()
{
    name = "                MR. JACKSON (HANDY) CONROY";
    nickName = "Mr. Conroy";

    ascii = R"(
                   .*#******#**                   
                =%*++****+=*=+**#%-               
              -*=----+*+---=+***+==#:             
             ++*+--=*+--=*##+==+*#+-=*            
            -*+-:==*+==+#***#+*+*##*-=#.          
            ++=-++*+=+==.         .++==*:         
            #+=+**+=+=#%@@#.    =@%##=+=+         
            #+*++*++++===-:    .--=+#++=+         
            -*#  =:. %+%=++   .*%-*@#+**+         
           #*+#.- .   .::.     .::..***#          
             **+. .                 :.            
              %***=         .  +    -             
               .***-      :++***.  -=             
              =%#*++.   -***#+##+=-:              
                  %*=.     .::.  -:               
                  =:-::-.      :=                 
                   +    -+*++=.                   
                 *-=      .:##-                   
              -=#-.-=       =*-*:--               
           *#%#%=*:  .*-    +. -*%%%%*            
        *- #####%::=     .##:   *-%#%+ :=         
     .=.   .%####%= -=   =##%=: *-%###. .=        
     =      -#*####+  :*#-%##*.. -%##%=   *       
    *        *######%-   .%#*#:  %####%    +      
    )";

    catchphrase[0] = "              \"Good day, Investigator!\"";
    catchphrase[1] = "              \"Can I fetch you a cup of tea?\"";
    catchphrase[2] = "              \"My, this is a right mess we are in!\"";

    motive[0] = "I have the deepest sympathy for the pain of my Mistress, the Baroness. I would never do anything to hurt her; She has been very good to me. I would never kill her husband. ";
    motive[1] = "Preposterous- it is not in the Buter Code of Conduct to kill their Masters.";
    motive[2] = "The Baron is... well, was... a vazey, pidgeon-livered hornswoggler, pardoning my language. He did badly by my Mistress, and that is something I cannot forgive. He didn't pay well either; I doubt anyone would miss him."; // https://www.thrillist.com/lifestyle/nation/1800s-insults-slang-from-the-victorian-era, this combination of insults means a cowardly, stupid cheat/fraud
}

void Servant::displayAlibi(CharacterFile* characters[], int count)
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
