#include "Bartender.h"

Bartender::Bartender()
{
    name = "MR. WILLIAM O'DOYLE";

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
