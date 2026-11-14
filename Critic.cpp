#include "Critic.h"

Critic::Critic()
{
    name = "                MR. REGINALD SINCLAIR";
    nickName = "Mr. Sinclair";

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

    catchphrase[0] = "              \"Such drab furnishings.\"";
    catchphrase[1] = "              \"This carpet is absolutely dreadful\"";
    catchphrase[2] = "              \"Yes, what is it?\"";

    motive[0] = R"(
            "What use have I for murder? The only death I implore is the death of businesses after
             my reviews. Could you imagine: Mr. Hudson hiring some amateur? Ridiculous."
            )";
    motive[1] = R"(
            "Me? A murderer? Don't be absurd. The only reason I am even here is that Mr. Hudson
             had almost made the abhorrent mistake of hiring some random reviewer who probably couldn't
             tell their mahogany from their walnut." 
            )";
    motive[2] = R"(
            "Mr. Hudson may have been a tasteless ne'er-do-well, but even a man of his caliber should 
             have had some standard. He had the AUDACITY to try to replace me with some green-skinned
             paperboy who barely hit puberty. If he were still with us, I would spit in his face."
            )";
}

void Critic::displayAlibi(CharacterFile* characters[], int count)
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
        fout << "Critic was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Critic can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Critic was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Critic was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
