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
    catchphrase[2] = "\"Yes, sir?\"";

    motive[0] = R"(
            "How could you suggest such a thing? My husband may not have been the best person, but I loved
             him with all my heart! I can only imagine when I can begin to move on..."
            )";
    motive[1] = "\"BARONESS Neutral Motive\"";
    motive[2] = "\"BARONESS Negative Motive\"";
} 
// //Use this as an outline -Esra P.
// friend ostream& operator <<(const ostream& os, const Baroness& b) {
//     os << b.name << endl << b.ascii << endl; 
//     return os;
// }

// didn't end up using operator overload --Payton P.
