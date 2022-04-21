//NotBindingOfIsaac     A Shitgaem made by a noob

#include "Actor.h"



Actor::Actor(float posX,float posY,float Aspeed, int attack, int defense, int health, bool invincible, int h, int i)
    : speed(Aspeed), baseAttack(attack), baseDefense(defense), baseHealth(health), b_IsInvincible(invincible), width(h), length(i), Entity(posX, posY)
    {
        //Inventory(3,false);
    }

Actor::~Actor()
{
    delete this;
}

 void Actor::Move(float deltaX, float deltaY)
{
    x += deltaX * speed;
    y += deltaY * speed;
}  

int Actor::GetBaseHealth() const
{
    return baseHealth;
}

int Actor::GetBaseDefense() const
{
    return baseDefense;
}

int Actor::GetBaseAttack() const
{
    return baseAttack;
}

float Actor::GetSpeed() const
{
    return speed;
}

Inventory Actor::GetInventory() {
    return *inv;
}

bool Actor::CheckInvincibility() const
{
    return b_IsInvincible;
}

void Actor::TakeDamage(int value)
{
    if(baseHealth > 0 && !b_IsInvincible)
    {
        baseHealth -= (value - baseDefense);
    }
    else 
    {
       this->~Actor();
    }
}

void Actor::ModifyDamage(int power) {
    baseAttack *= (power / 100);
}

void Actor::ModifyHealth(int power) {
    baseHealth *= (power / 100);
}

void Actor::ModifyDefense(int power) {
    baseDefense *= (power / 100);
}

void Actor::ModifySpeed(int power) {
    speed *= ((float)power / 100.f);
}

void Actor::UseItem(Item &item) {
    Item::Buff buff = item.GetEffect();
    switch (buff.effect) {
        case Item::Health:  ModifyHealth(buff.power);
                            break;
        case Item::Defense: ModifyDefense(buff.power);
                            break;
        case Item::Damage:  ModifyDamage(buff.power);
                            break;
        case Item::Speed:   ModifySpeed(buff.power);
                            break;
    }

}

void Actor::AddItem(Item &item) {
    inv->addItem(item);
}

void Actor::RemoveItem(Item &item) {
    inv->removeItem(item);
}