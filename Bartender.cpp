#include "Bartender.h"

Bartender::Bartender()
{
    name = "                MR. WILLIAM O'DOYLE";
    nickName = "Mr. O'Doyle";

    ascii = R"(
                    =#******#==                   
                -#*+*****+=*=+**##.               
              .*-::::+*=-.:=+***+==#              
             -+*+::=*+::+###+==+*#+:=*            
            .*+:.-=*+==*#********##*:=*           
            .==:+**+=+==.         .++==*.         
            #*=*##+=+=#%@%*     =@%##=+==         
          :*++*=+**+++===-:    .--=+#+*==         
          ##=+*  =*- %=#.=+   .+%.+%****=         
          #*#+* - *-  ...       ... ****          
            *+#=  ==                .             
            ##+**+-.           =    :             
             =###+*:     .:+*++*:  :-             
                +##+   :*+=+-:-=*++.              
                   .-  -==+-**++++                
                    :.:=#==++**+#-                
                   +    -+#**###                  
                 +.-      .:**.                   
              .-#. .-       =+.* ..               
           +*###:+   #*-    +#*:+####+            
        +: ****## .-++-=*#+**==**.###=  -         
      -     #***##- :#==+**#+*++#.###*   -        
     :      :#+**##-  ##         .####:   +       
    +        +***#*##.           #*###%    =      
    )";

    catchphrase[0] = "              \"Oi.\"";
    catchphrase[1] = "              \"Do ya need something?\"";
    catchphrase[2] = "              \"What can I do ya for?\"";

    motive[0] = R"(
            "Hudson ain't exactly someone you'd share a pipe with, but he pays well enough. 
             Money is hard to come by for paddies, and I definitely wasn't gonna deny a large 
             sum. Any kind of payment that'd help me family is good payment.
            )";
    motive[1] = R"(
            "Hudson, and forgive me language, is gobshited arsehole. The man tried to buy me 
            family's heritage as a simple swig and then threatened to deport 'em if I 
            didn't. So, I came to work for him, not that I 'ad a choice..."
        )";
    motive[2] = R"(
            "The bastard had it comin', I'd say. Any man that has the gall to threaten another man's
            family more than what he got. The only thing I feel for Hudson is regret that I couldn't
            see him go out."
        )";
}

void Bartender::displayAlibi(CharacterFile* characters[], int count)
{
    ofstream fout("NotePad.txt", ios::app);
    string room = getRoom();
    int roomCount = countPeopleInRoom(characters, count, room, this);
    string secondPerson = getSecondPerson(characters, count, room, this);

    cout << endl;
    cout << "           ";
    
    if(!room.empty())
    {
        cout << "I was in the " << room << ".";
        fout << "Bartender was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Bartender can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Bartender was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Bartender was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
