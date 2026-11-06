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
    character.displayMotive();

    return 0;
}
