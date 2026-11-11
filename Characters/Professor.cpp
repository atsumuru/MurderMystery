#include "Professor.h"

Professor::Professor()
{
    name = "PROFESSOR ARCHWIN STEIN";

    ascii = R"(
                   :++=--=+++++                   
                -*=:-====::-.-==+*:               
              -=..  ....:--:: :=::-+:             
             =-=:  ::..:--==. .:=:.:+-            
            :=:. .::===::::-+==:::==-+.           
            =-:.:-*:.              :==.           
           .+:.-+--=.=#%%%*:   :#%#=*=.           
           .+-=+=-+:.======.   -===+*+            
            :-*  -:.++-+:--+. =++:-+*             
           +=-*.- . =.:::..=..=:::::+             
             +=+. .            .    .             
              *=++=           .-   .+             
               .====         .::  .*              
              -*+=-+=.    .-=-=:  +               
                  *+=--.   .==:  -:               
                  =:-.:==.     :=                 
                   +.  .:=++++-                   
                 *-=     .::*#-                   
              :-*-.-=       =+-*:::               
           +=:.  *:...*-.   +: -*..:=+.           
       .*=        -=.    :##:  .*    ..:=         
     .=.           .-=   +###=:.*     ...=        
    .=                -**=###*..  .  .....*       
    *.       -.          :##*#:    ..:=.. .+      
    )";

    catchphrase[0] = "\"PROFESSOR Catchphrase #1\"";
    catchphrase[1] = "\"PROFESSOR Catchphrase #2\"";
    catchphrase[2] = "\"PROFESSOR Catchphrase #3\"";

    motive[0] = "PROFESSOR Positive Motive";
    motive[1] = "PROFESSOR Neutral Motive";
    motive[2] = "PROFESSOR Negative Motive";
}
