//NotBindingOfIsaac     A Shitgaem made by a noob
#include "Player.h"

Player::Player()
: Actor(960,540,10,10,10,100,1,1,false)
{}

Player::Player(int a, int b, int c)
: money(a), level(b), kills(c), Actor(960,540,10,10,10,100,1,1,false)
{}

int Player::GetMoney()
{
    return money;
}

int Player::GetLevel()
{
    return level;
}

int Player::GetKills()
{
    return kills;
}

int Player::GetEXP()
{
    return currentexp;
}

int Player::GetEXPneeded()
{
    return expneeded;
}

void Player::AddMoney(int value)
{
    money += value;
}

void Player::AddEXP(int amount)
{
    currentexp += amount;
    LevelUp(currentexp / expneeded);
    currentexp -= expneeded;
}

void Player::LevelUp(int value)
{
    level += value;
    expneeded *= 2;
}
