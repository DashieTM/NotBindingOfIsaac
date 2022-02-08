//NotBindingOfIsaac     A Shitgaem made by a noob
#include "Entity.h"

Entity::Entity(int posX, int posY)
    : x(posX), y(posY)
    {}

Entity::~Entity()
{
    delete this;
}

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