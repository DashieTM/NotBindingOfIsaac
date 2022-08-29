//NotBindingOfIsaac     A Shitgaem made by a noob
#include "Actor.h"

class Player : public Actor
{
protected:

    int money = 0;
    int level = 0;
    int kills = 0;
    int expneeded = 100;
    int currentexp = 0;




public:

    Player();
    Player(int a, int b, int c);

    int GetMoney();
    int GetLevel();
    int GetKills();
    int GetEXPneeded();
    int GetEXP();
    void AddMoney(int value);
    void AddEXP(int amount);
    void TakeDamage();
    void LevelUp(int value);

};
