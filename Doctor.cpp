#include "Doctor.h"

Doctor::Doctor()
{
    name = "                DOCTOR ANDREW REYNOLDS";
    nickName = "Dr. Reynolds";

    ascii = R"(
               #**#:-                             
            :*=+++**##                            
           =##**+++***######==                    
           #***=**#**+=++++*+***#                 
          .*++**#**+=+++=+*+*++*+**.              
            #****+=++=++****+=+**++*+             
             =**++***+=:::::++=:::=*#:            
             ***+=#:.              :##            
             ****+*+.-+*##=.   .-*#+##            
             **==**:.:----:    :----*#            
             #+  -*=.#-#::=.  .*#.-#*#            
             =+.- *=  :::.    .::::.-             
              #=. ==       .. ..    .             
               #+=#+.      .  .=   .-             
                 ##*:     :+****: .+              
                  .**=  -****+***+=               
                  =.#*****..::. :#                
                   .-+***++******-                
                 -*=.  +#****+**#                 
               **+*-     .=####**                 
             +*++=*:-       -==*+*:               
           +*++++++-  =-.   =  ++++#*=            
        **+++*+++++*      +=   -*++*****-         
      +++++=++#+++***.   :. ::  #*****++**        
     *==+++++++***++*  ==       #+++*++++*#       
    *+++==+++++**++++#          #+=++*+++**+      
    )";

    catchphrase[0] = "              \"Hello again.\"";
    catchphrase[1] = "              \"Did you want to take about my diagnosis again?\"";
    catchphrase[2] = "              \"He's gone full rigor by now.\"";

    motive[0] = R"(
            "As Charles' physician, I've sworn the hippocratic oath. I would never try to take
             control of a paitent's life like that. What am I, some 'angel of death'?"
            )";
    motive[1] = R"(
            "Charles was my most valued paitent. We both had a great bond. However, he may have
             caught me dipping into his funds. But, as his doctor, I need to prescribe him the 
             medicine he needs. Surely, you understand."
            )";
    motive[2] = R"(
            "I've done my best to do what's right for Charles, but he's been adamant on hiring a 
             different physician. I know it's not my place to question the decision of my paitent,
             but I don't believe my carrerr would've survived if Charles had fired me." 
            )";
}

void Doctor::displayAlibi(CharacterFile* characters[], int count)
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
        fout << "Doctor was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Doctor can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Doctor was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Doctor was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
