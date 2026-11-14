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

    motive[0] = R"(
            "I have the deepest sympathy for the pain of my Mistress, the Baroness. I would never do anything to hurt 
             her; She has been very good to me. I would never kill her husband." 
            )";
    motive[1] = R"(
            "Preposterous- it is not in the Butler Code of Conduct to kill their Masters."
            )";
    motive[2] = R"(
            "The Baron is... well, was... a vazey, pidgeon-livered hornswoggler, pardoning my language. He did badly by 
             my Mistress, and that is something I cannot forgive. He didn't pay well either; I doubt anyone would miss him."
            )"; // https://www.thrillist.com/lifestyle/nation/1800s-insults-slang-from-the-victorian-era, this combination of insults means a cowardly, stupid cheat/fraud
}

void Servant::displayAlibi(CharacterFile* characters[], int count)
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
        fout << "Servant was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Servant can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Servant was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Servant was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
