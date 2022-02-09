//NotBindingOfIsaac     A Shitgaem made by a noob
#pragma once
#include <tuple>


class Entity
{
    protected:
        float x;
        float y;

    public:
        Entity(float x, float y);
        ~Entity();

        std::tuple<int, int> GetPos() const;
        float GetPosX() const;
        float GetPosY() const;



};