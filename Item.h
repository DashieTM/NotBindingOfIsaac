//NotBindingOfIsaac     A Shitgaem made by a noob

#include "Entity.h"

class Item : public Entity
{
public:

    enum Effect {Health, Damage, Defense, Speed, None};

    struct Buff {Effect effect; float power;};

protected:

    int value;
    int weight;
    int droprate;
    bool IsUsable;
    bool hasEffect;
    int index;

    Buff buff;

private:

    void GenerateEffect();
    void ApplyHealthEffect(float power);
    void ApplyDamageEffect(float power);
    void ApplyDefenseEffect(float power);
    void ApplySpeedEffect(float power);

public:

    

    Item(int a, int b, int c, bool d, bool e);
    Item();
    ~Item();

    int GetValue();
    int GetWeight();
    int GetDroprate();
    int GetUsablestatus();
    int returnIndex();
    Buff GetEffect();
    
    void addIndex(int ind);
    void SetEffectNone();

};