#include "Baroness.h"

Baroness::Baroness()
{
    name = "MRS. LENORA HUDSON";

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

    catchphrase[0] = "\"Please tell me you found the one who killed my husband.\"";
    catchphrase[1] = "\"This entire situation is terrifying.\"";
    catchphrase[2] = "\"Yes?\"";

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
// //Use this as an outline -Esra P.
// friend ostream& operator <<(ostream& os, const Baroness& b) {
//     os << b.name << endl << b.ascii << endl; 
//     return os;
// }

// didn't end up using operator overload --Payton P.
