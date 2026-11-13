#include "Bartender.h"

Bartender::Bartender()
{
    name = "MR. WILLIAM O'DOYLE";
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

    catchphrase[0] = "\"Oi.\"";
    catchphrase[1] = "\"Do ya need something?\"";
    catchphrase[2] = "\"What can I do ya for?\"";

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
    string room = getRoom();
    
    int roomCount = countPeopleInRoom(characters, count, room);

    string secondPerson = "";

    for (int i = 0; i < count; i++)
    {
        if (characters[i] != this && characters[i]->getRoom() == room)
        {
            secondPerson = characters[i]->getNickName();
            break;
        }
    }

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
    if (roomCount == 1)
    {
        cout << "I was by myself." << endl;
    }
    else if (roomCount == 2)
    {
        cout << "I was with " << secondPerson << ". They can confirm." << endl;
    }
}
