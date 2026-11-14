#include "Baroness.h"

Baroness::Baroness()
{
    name = "                MRS. LENORA HUDSON";
    nickName = "Mrs. Hudson";

    ascii = R"(
                    ==@@@@*=
                  +@@@@@@@@@@@@  **
                 +@@@@@@@@...:@@@@@@@+
                -@@@...:@@@@@@@@@@@@@@@@@
                -@@@@@@@@@@@@@@@@@@@@@@@@@*
                 %@@@@@@@@@@@@@@@@@@@@@@@@@@
                -@@@@@@@@@@@@*=-------=#@@@@%
                -@@@@@@@@@@@-----------=*@@@@*
                -@@@@@@@@@@%%%%%+---+%%%@@@@@*
                -@@=@@@@*%@@@@@#=--=@@@@%@@@@*
                -@@-@@@@@%#%%+-#=--+%+-*%@@@%
                 +@**%@@@#=====-----====+%@%
                  =@**@@@=--------+=----=%@
                   -@@@@=--------=%#=---+@@@
                   @@@@%=---------=----=%= @%
                   *@@-+#=----+###%#=-=%  @*
                    =@+:%*+-----=+=--*+  *=
                     *+:%==+#+=---=+#     @
                      -%=---=*%%%%-
                    -**@-------=*@#*
                  *%*#==**-------#+=@%%%
              -%%=-::+#---*%+=--**--**--=*%--
           +#+-:::-:--=#*--:--%@@+--+*-----=+*-
         =#=:::-:-------=#=::*@@@@@-+*------==%
        -#-:-:-------------%@@@@@@@@%--=--===--%
        %=::-----++---------%@@@@@@@*-----+#=--=#-
        )";

    catchphrase[0] = "              \"Please tell me you found the one who killed my husband.\"";
    catchphrase[1] = "              \"This entire situation is terrifying.\"";
    catchphrase[2] = "              \"Yes?\"";

    motive[0] = R"(
            "How could you suggest such a thing? My husband may not have been the best person, but I loved
             him with all my heart! I can only imagine when I can begin to move on..."
            )";
    motive[1] = R"(
            "I would never kill my husband! But I will admit: Charles and I had gotten into a fight the 
            other day over an...affair. I was upset, but I didn't hate him, definitely not to the extent 
            of murder!"
            )";
    motive[2] = R"(
            "I loved my husband so much, but I simply couldn't ignore what he's done; I know it... He
            slept with that harlot, Ms. Rougê. I was so angry that night, and it's terrible that 
            he's passed. But now that he's gone, I'm ashamed to say a part of me is glad."
            )";
}

void Baroness::displayAlibi(CharacterFile* characters[], int count)
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
        fout << "Baroness was in the "<< room << ".";
    }
    else
    {
        cout << "I can't remember where I was.";
        fout << "Baroness can't remember where they were.";
    }
    
    //if they end up with someone
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
        fout << " Baroness was by themself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
        fout << " Baroness was with " << secondPerson << ". Or so they say." << endl;
    } 
    fout.close();
}
