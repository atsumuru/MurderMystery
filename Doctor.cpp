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

    catchphrase[0] = "              \"DOCTOR Catchphrase #1\"";
    catchphrase[1] = "              \"DOCTOR Catchphrase #2\"";
    catchphrase[2] = "              \"DOCTOR Catchphrase #3\"";

    motive[0] = "DOCTOR Positive Motive";
    motive[1] = "DOCTOR Neutral Motive";
    motive[2] = "DOCTOR Negative Motive";
}

void Doctor::displayAlibi(CharacterFile* characters[], int count)
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
