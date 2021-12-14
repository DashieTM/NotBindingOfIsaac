#include "Entity.h"

Entity::Entity(int posX, int posY)
    : x(posX), y(posY)
    {}

std::tuple<int,int> Entity::GetPos() const
{
    return std::make_tuple(x,y);
}

int Entity::GetPosX() const
{
    return x;
}

int Entity::GetPosY() const
{
    return y;
}