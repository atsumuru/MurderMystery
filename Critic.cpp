#include "Critic.h"

Critic::Critic()
{
    name = "MR. REGINALD SINCLAIR";

    ascii = R"(
                         .+@@@@@@@@++.                 
                      @@@%@@@@@%%@%%@@@@@              
                     @%#**#%%%%@@%%#%@%%%@             
                    @%%%##%%@@%%%@%##%@%%%@            
                  @@%#*%%%@@%@***@@%@**@@@%@@          
                  @%%#%@@%@@%-:.........:@%%@          
                  @%%%%%#@=@@............:@%%.         
                 :%%%%%@@++@%%%%#+...:%%%%@@%.         
                 :#%%..*@:%+*****#...*****%@%.         
                 @%%%::.::%:.+- .+%%%+*- :%@%.         
                 @%%%-=.:.:%%%%%%+...*%%%%*@%:         
               @##@%@@::*............-....*@%@         
             .@@@@%%%@@@%:........=*=+...-%@#%@        
               @@%##%@%@%=.....:@%%%%%@:.*%@@%%%@      
                @#*#%%%%%+-...@++===+++@+%#*#@@        
                 @#@%##%%:==**:...@@:.:@@#*%*@         
               @@@%%#*@@.%:::#@@%@%@%@@@*@%%*.         
                  @#*@%@=. .%#=*@@@@@@%**@ @%@         
                 :@@%%%%@......:::=%@%%=@              
                 :+%%%%%%#=:..   -%%+#@@@@             
              @@@%@+%%%%=@@+=#+::+%=%%@@@@@@@.         
          =@@%%%%%%@##%+@@+--- -..+:+#@@@%@%@@@=       
         @%##%%%%%#%%%@@@#@+:  :=.+=:+@%%@%%%%%@@      
        @%#%#%%%%%#%%%%%%#@=. .:+  += %%%@%%%%%%@.     
       @@##%#%%%%%@%##++++=@::=++-  %-=%%#%%%%%%@@     
    )";

    catchphrase[0] = "\"Such drab furnishings.\"";
    catchphrase[1] = "\"This carpet is absolutely dreadful\"";
    catchphrase[2] = "\"Yes, what is it?\"";

    motive[0] = R"(
            "What use has I for murder? The only death I implore is the death of businesses after
             my reviews. Could you imagine: Mr. Hudson hiring some amateur? Ridiculous."
            )";
    motive[1] = R"(
            "Me? A murderer? Don't be absurded. The only reason I am even here is that Mr. Hudson
             had almost made the abhorrent mistake of hiring some random reviewer who probably couldn't
             tell their mahagony from their walnut." 
            )";
    motive[2] = R"(
            "Mr. Hudson may have been a tasteless ne'er-do-well, but even a man of his caliber should 
             have had some standard. He had the AUDACITY to try to replace me with some green-skinned
             paperboy who barely hit puberty. If he were still with us, I would spit in his face."
            )";
}

void Conductor::displayAlibi(CharacterFile* characters[], int count)
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
