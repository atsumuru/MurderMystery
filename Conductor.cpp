#include "Conductor.h"

Conductor::Conductor()
{
    name = "                MR. ARNOLD HARRIS";
    nickName = "Mr. Harris";

    ascii = R"(
                *%#####%%#%%========-             
               .%##**#*####*##########%           
                *##***#################%          
                -#****#####*##########%           
                -#*#**################            
          :--   -###**##############%-            
        #######*#%##################*             
        %####%%%%%######%%##########*             
        =%#%#.  .:.:*%##*#######%%%%%%+====       
           %+  .  .+:-*%%%#**###############      
            = -=--=. .---::=+++*#########+=       
           =:.#  -.. %+@==+    +%-+@#=+           
          + : # : :   ..:.     ::.. *-+           
         - :: -=  ..                :-+           
          +- :=:++-        .   +    - .=:         
          +   ..-=*:               :+   =         
        -++*  =.::-+      .:-:-.  :--- =          
          +. :=-: .=-.      ::   :- -- *          
          *  =*+..-#:.:==...:: :-+::---           
           =-: :*##=+   :=+=:==**:+**+--+         
            ** %###    +  .:*%%%%*.               
             ######    =    *.*##%=               
           #%##*###=    *   ..=####%#*            
        %%###%#**##%+.  .+.. + +%###%%#%+         
      #####*##%%##%%%  .:-==-   %%%%%%###%        
     %***#######%###%.     -    %###%%####%       
    %#*#**####*#%#*##%     .=   %#*#%%####%#      
    )";

    catchphrase[0] = "              \"Hmm.\"";
    catchphrase[1] = "              \"What?\"";
    catchphrase[2] = "              \"I hate my job...\"";

    motive[0] = R"(
            "I don't want to be here. Not just because of the murder, but because I need a break from smelling
             coal and soot. The only reason I came in the first place was that Mr. Hudson promised three times 
             my usual wage. Now, look at him."
            )";
    motive[1] = R"(
            "I don't want to be here. I was supposed to be on my one layoff a year, but then Smith got sick
             and took his layoff before me. Now, I have to work his shift. This is a bunch of bollocks."
            )";
    motive[2] = R"(
            "I don't want to be here. I wasn't supposed to come in today. I've worked for 14 hours straight,
             and yet, Mr. Hudson told me to drive this damned train. Now, the man's dead! Who's going to 
             pay me now!"
            )";
}

void Conductor::displayAlibi(CharacterFile* characters[], int count)
{
    ofstream fout("NotePad.txt", ios::app);
    string room = getRoom();
    int roomCount = countPeopleInRoom(characters, count, room, this);
    string secondPerson = getSecondPerson(characters, count, room, this);

    cout << endl;
    
    if(!room.empty())
    {
        cout << "I was in the " << room << ".";
        fout << "Conductor was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Conductor can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Conductor was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Conductor was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
