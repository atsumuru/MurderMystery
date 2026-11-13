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
    string room = getRoom();
    int roomCount = countPeopleInRoom(characters, count, room, this);
    string secondPerson = getSecondPerson(characters, count, room, this);

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
    if (roomCount == 0)
    {
        cout << " I was by myself." << endl;
    }
    else if (roomCount == 1)
    {
        cout << " I was with " << secondPerson << ". They can confirm." << endl;
    }
}
