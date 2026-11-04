#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// characterTemplate.cpp
// by Payton Phillips

// catchphrase: 3
// alibi: 5: 2 single, 3 multi (if w/ character)
// motives: 3: 1 positive, 1 neutral, 1 negative (SAME MOTIVE)

class Character {
private:
    
    
    string ascii; 
    string name;
    
    string catchphrase[3] =
        {
            "CHARACTER Catchphrase #1",
            "CHARACTER Catchphrase #2",
            "CHARACTER Catchphrase #3"
        };
        
    string alibi[5] =
        {
            "CHARACTER Single Alibi #1",
            "CHARACTER Single Alibi #2",
            "CHARACTER Single Alibi #3",
            "CHARACTER With Person Alibi #4",
            "CHARACTER With Person Alibi #5"
        };
        
    string motive[3] =
        {
            "CHARACTER Positive Motive",
            "CHARACTER Neutral Motive",
            "CHARACTER Negative Motive"
        };
public:
    void displayCharacter()
    {
    ascii = R"(insert ascii here)";
        cout << ascii << endl;
    }
    
    void displayName()
    {
        name = "John Doe";
        cout << name << endl;
    }
    
    void displayCatchphrase()
    {
        // randomly pull one of the three catchphrases
        int i = rand() % 3;
        cout << catchphrase[i] << endl;
    }
    
    void displayAlibi()
    {
        // randomly pull one of the five alibis
        // prolly other logic to figure out how to pick multi
        // if statements (maybe randomly pick room, if someone else is
        // in it then it will saywith characterName) maybe??
        
        // cout << "I was in " << room << "with" << otherCharacter;
        // or something like that
        
        int i = rand() % 5;
        cout << alibi[i] << endl;
    }
    
    void displayMotive()
    {
        // randomly pull one of the three motives
        int i = rand() % 3;
        cout << motive[i] << endl;
    }
};

int main()
{
    srand(time(0));

    Character character;

    character.displayCharacter();
    character.displayName();
    character.displayCatchphrase();
    character.displayAlibi();
    character.displayMotive();

    return 0;
}
