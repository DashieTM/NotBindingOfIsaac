//NotBindingOfIsaac     A Shitgaem made by a noob

#include "Item.h"
#include "stdlib.h"
#include "ctime"

/*Item::Item()
    : value(0), weight(0), droprate(0), IsUsable(false)
    {}*/

Item::Item(int a, int b, int c, bool d, bool e)
    : value(a), weight(b), droprate(c), IsUsable(d), hasEffect(e)
    {
        if (hasEffect) GenerateEffect();
    }

int Item::GetDroprate()
{
    return droprate;
}

int Item::GetUsablestatus()
{
    return IsUsable;
}

int Item::GetValue()
{
    return value;
}

int Item::GetWeight()
{
    return weight;
}

void Item::GenerateEffect() {

    srand(time(0)); 
    int randomEffect = rand() % 3;
    int randomPower = rand() % 200 + 50;
    
    switch(randomEffect){
        case 0: ApplyDamageEffect(randomPower);
                break;
        case 1: ApplyDefenseEffect(randomPower);
                break;
        case 2: ApplyHealthEffect(randomPower);
                break;
        case 3: ApplySpeedEffect(randomPower);
                break;
        default: break;
    }
}

void Item::ApplyDamageEffect(int power) {
    buff.effect = Damage;
    buff.power = power;
}

void Item::ApplyDefenseEffect(int power) {
    buff.effect = Defense;
    buff.power = power;
}

void Item::ApplyHealthEffect(int power) {
    buff.effect = Health;
    buff.power = power;
}

void Item::ApplySpeedEffect(int power) {
    buff.effect = Speed;
    buff.power = power;
}

Item::Buff Item::GetEffect() {
    return buff;
}