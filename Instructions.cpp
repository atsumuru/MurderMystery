#include "Instructions.h"
#include "StartScreen.h"

void instructions()
{
    cout << R"(
    Welcome to THE MURDER OF CHARLES HUDSON!
    
    You are a detective riding on the new fastest rail train in 1872.
    Everything is perfect- at least, until someone is murdered.
    Your goal is to solve the murder before you become the next target!
    
    Each round, you are able to interrogate 4 characters.
    You can ask about their alibi (where they were when the victim was murdered),
    their motive (what their relationship with the victim was),
    or a rumor (either a hint guiding you to the murderer, or a red herring).
    Be aware that the murderer can- and will- lie to you!
    All the information you gain is recorded in your notebook,
    which you can view throughout the game.
    
    At the end of every round, the murderer strikes again-
    killing either one or two characters. When characters die,
    you lose access to the information they know, making your job harder.
    Once all the characters have been killed but one, the remaining character-
    who must be the murderer- kills you and you lose the game.
    
    Once you think you know who the murderer is, you can make an accusation.
    If you are correct, you win the game!
    However, if you accuse an innocent character, they will be offended
    and will not speak to you for 4 “talking periods”. In addition, be advised-
    the murderer may feel threatened; they may kill more characters that round.
    
    Tips for playing:
    Check your notes regularly.
    Use your chances efficiently- it is easy to run out of time!
    Keep an eye out for stories that don’t make sense.
    If two characters both say they were in a room alone, one must be lying!
    Have fun!
    
    )";
}

void goBack()
{
    string choice;
    
    cout << "GO BACK? (YES.): ";
    cin >> choice;
  
    if(choice == "yes" || choice == "y")
    {
        startScreenMain();
    }
    else
    {
        prologueMain();
    }
    
}

void instructionsMain()
{
    instructions();
    goBack();
}
