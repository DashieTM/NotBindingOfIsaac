//NotBindingOfIsaac     A Shitgaem made by a noob
#include "Entity.h"

Entity::Entity(float posX, float posY)
    : x(posX), y(posY)
    {}

Entity::Entity() 
: x(-1), y(-1)
{}

Entity::~Entity()
{
    delete this;
}

std::tuple<int,int> Entity::GetPos() const
{
    return std::make_tuple(x,y);
}

float Entity::GetPosX() const
{
    return x;
}

float Entity::GetPosY() const
{
    return y;
}