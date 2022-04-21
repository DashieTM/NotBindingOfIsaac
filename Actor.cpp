//NotBindingOfIsaac     A Shitgaem made by a noob

#include "Actor.h"



Actor::Actor(float posX,float posY,float Aspeed, int attack, int defense, int health, bool invincible, int h, int i)
    : speed(Aspeed), baseAttack(attack), baseDefense(defense), baseHealth(health), b_IsInvincible(invincible), width(h), length(i), Entity(posX, posY)
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
    baseAttack += baseAttack * (power / 100);
}

void Actor::ModifyHealth(int power) {
    baseHealth += baseHealth * (power / 100);
}

void Actor::ModifyDefense(int power) {
    baseDefense += baseDefense * (power / 100);
}

void Actor::ModifySpeed(int power) {
    speed += speed * ((float)power / 100.f);
}