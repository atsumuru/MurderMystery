#include "Servant.h"

Servant::Servant()
{
    name = "MR. JACKSON (HANDY) CONROY";

    ascii = R"(
                   .*#******#**                   
                =%*++****+=*=+**#%-               
              -*=----+*+---=+***+==#:             
             ++*+--=*+--=*##+==+*#+-=*            
            -*+-:==*+==+#***#+*+*##*-=#.          
            ++=-++*+=+==.         .++==*:         
            #+=+**+=+=#%@@#.    =@%##=+=+         
            #+*++*++++===-:    .--=+#++=+         
            -*#  =:. %+%=++   .*%-*@#+**+         
           #*+#.- .   .::.     .::..***#          
             **+. .                 :.            
              %***=         .  +    -             
               .***-      :++***.  -=             
              =%#*++.   -***#+##+=-:              
                  %*=.     .::.  -:               
                  =:-::-.      :=                 
                   +    -+*++=.                   
                 *-=      .:##-                   
              -=#-.-=       =*-*:--               
           *#%#%=*:  .*-    +. -*%%%%*            
        *- #####%::=     .##:   *-%#%+ :=         
     .=.   .%####%= -=   =##%=: *-%###. .=        
     =      -#*####+  :*#-%##*.. -%##%=   *       
    *        *######%-   .%#*#:  %####%    +      
    )";

    catchphrase[0] = "\"SERVANT Catchphrase #1\"";
    catchphrase[1] = "\"SERVANT Catchphrase #2\"";
    catchphrase[2] = "\"SERVANT Catchphrase #3\"";

    motive[0] = "SERVANT Positive Motive";
    motive[1] = "SERVANT Neutral Motive";
    motive[2] = "SERVANT Negative Motive";
}
