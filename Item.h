//NotBindingOfIsaac     A Shitgaem made by a noob

#include "Entity.h"

class Item : public Entity
{
public:

    enum Effect {Health, Damage, Defense, Speed};

    struct Buff {Effect effect; int power;};

protected:

    int value;
    int weight;
    int droprate;
    bool IsUsable;
    bool hasEffect;
    
    Buff buff;

private:

    void GenerateEffect();
    void ApplyHealthEffect(int power);
    void ApplyDamageEffect(int power);
    void ApplyDefenseEffect(int power);
    void ApplySpeedEffect(int power);

public:

    

    Item(int a, int b, int c, bool d, bool e);
   // Item();
    ~Item();

    int GetValue();
    int GetWeight();
    int GetDroprate();
    int GetUsablestatus();
    Buff GetEffect();


};