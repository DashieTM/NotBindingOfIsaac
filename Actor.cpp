//NotBindingOfIsaac     A Shitgaem made by a noob

#include "Actor.h"



Actor::Actor(float posX,float posY,float Aspeed, float attack, float defense, float health, bool invincible, int h, int i)
    : speed(Aspeed), baseAttack(attack), baseDefense(defense), baseHealth(health), b_IsInvincible(invincible), width(h), length(i), Entity(posX, posY), inv(Inventory(5,false))
    {}

Actor::~Actor()
{
    delete this;
}

 void Actor::Move(float deltaX, float deltaY)
{
    x += deltaX * speed;
    y += deltaY * speed;
}  

float Actor::GetBaseHealth() const
{
    return baseHealth;
}

float Actor::GetBaseDefense() const
{
    return baseDefense;
}

float Actor::GetBaseAttack() const
{
    return baseAttack;
}

float Actor::GetSpeed() const
{
    return speed;
}

Inventory* Actor::GetInventory() {
    return &inv;
}

bool Actor::CheckInvincibility() const
{
    return b_IsInvincible;
}

void Actor::TakeDamage(float value)
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

void Actor::ModifyDamage(float power) {
    baseAttack *= power;
}

void Actor::ModifyHealth(float power) {
    baseHealth *= power;
}

void Actor::ModifyDefense(float power) {
    baseDefense *= power;
}

void Actor::ModifySpeed(float power) {
    speed *= power;
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
        case Item::None:    break;
    }

}

void Actor::AddItem(Item &item) {
    inv.addItem(item);
}

void Actor::RemoveItem(Item &item) {
    inv.removeLastItem();
}

void Actor::UseLastItem() {
    if (!inv.isEmpty()) {
        UseItem(*inv.returnLastItem());
        inv.removeLastItem();
    }
}