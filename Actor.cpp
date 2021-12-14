#include "Actor.h"



Actor::Actor(int PosX, int PosY, int Aspeed, int attack, int defense, int health, bool invincible)
{
    x = PosX;
    y = PosY;
    speed = Aspeed;
    baseAttack = attack;
    baseDefense = defense;
    baseHealth = health;
    b_IsInvincible = invincible;
}

 void Actor::Move(int deltaX, int deltaY)
{
    x += deltaX * speed;
    y += deltaY * speed;
}  

std::tuple<int,int> Actor::GetPos() const
{
    return std::make_tuple(x,y);
}

int Actor::GetPosX() const
{
    return x;
}

int Actor::GetPosY() const
{
    return y;
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

/*int Actor::GetPosZ() const
{
    return z;
}*/

void Actor::TakeDamage(int value)
{
    if(baseHealth > 0 && !b_IsInvincible)
    {
        baseHealth -= (value - baseDefense);
    }
} 