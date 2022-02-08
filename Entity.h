//NotBindingOfIsaac     A Shitgaem made by a noob
#pragma once
#include <tuple>


class Entity
{
    protected:
        int x;
        int y;

    public:
        Entity(int x, int y);
        ~Entity();

        std::tuple<int, int> GetPos() const;
        int GetPosX() const;
        int GetPosY() const;



};