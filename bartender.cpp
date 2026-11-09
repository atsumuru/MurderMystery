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

    catchphrase[0] = "\"BARTENDER Catchphrase #1\"";
    catchphrase[1] = "\"BARTENDER Catchphrase #2\"";
    catchphrase[2] = "\"BARTENDER Catchphrase #3\"";

    motive[0] = "BARTENDER Positive Motive";
    motive[1] = "BARTENDER Neutral Motive";
    motive[2] = "BARTENDER Negative Motive";
}
