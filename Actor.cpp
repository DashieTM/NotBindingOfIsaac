//NotBindingOfIsaac     A Shitgaem made by a noob

#include "Actor.h"



Actor::Actor(int posX,int posY,int Aspeed, int attack, int defense, int health, bool invincible)
    : speed(Aspeed), baseAttack(attack), baseDefense(defense), baseHealth(health), b_IsInvincible(invincible), Entity(posX, posY)
    {}

 void Actor::Move(int deltaX, int deltaY)
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
} 