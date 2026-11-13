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
