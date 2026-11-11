#include "Investigator.h"

Investigator::Investigator()
{
    name = "PI PRESTON JONES";

    ascii = R"(
                    *%%###%%%**                   
              @#@@%#######*#*###%@:               
              @%##++**###%#*#+*##*#%.             
           @#%%#**####+**##%*+*###*#%:            
            #@######%+*###%+++=--#%##%            
            *#*###%%*#@%*#+        *#%            
            %+*#%#*%#@+%%%*     +@%*@%            
            %*#=+#%##@+=#=.    :==--##            
            .#*  =#=-@-=%==   .=+**++             
           ###* - #-  ::       .:. :=             
             *#=  =*                              
              @#*+=.           =    -             
                %##-      :*#%%%.  --             
              -@%%##:   -%###*#%#=:               
                  @#=:      ::   =                
                  =:: :+:      .:                 
                 -+#*   -=++==+                   
               *=-****++  .:*+==*                 
             ==---****==    *#*==+:               
           +*-::---****-#   ##%*=--*+=            
        *=-:-+-.:--+####:*.+#%#*+---*+==-         
      =---:.::=+-=++**###==*%#***+++++-==*        
     +:.:---::-=*=--+#***#=+#****--=*+-===*       
    +:::.:--=-:=+:.:-*#***+.#****:.-+=---==+
    )";

    catchphrase[0] = "\"INVESTIGATOR Catchphrase #1\"";
    catchphrase[1] = "\"INVESTIGATOR Catchphrase #2\"";
    catchphrase[2] = "\"INVESTIGATOR Catchphrase #3\"";

    motive[0] = "INVESTIGATOR Positive Motive";
    motive[1] = "INVESTIGATOR Neutral Motive";
    motive[2] = "INVESTIGATOR Negative Motive";
}
