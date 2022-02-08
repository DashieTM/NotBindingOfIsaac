//NotBindingOfIsaac     A Shitgaem made by a noob
#pragma once
#include "Entity.h"

class Actor : public Entity
{
    protected:
        //movement
        int speed;


        //combat
        int baseAttack;
        int baseDefense;
        int baseHealth;
        bool b_IsInvincible;

        //figure
        int width;
        int length;



    public:
        Actor();
        Actor(int posX, int posY,int Aspeed, int attack, int defense, int health, bool invincible, int h, int i);
        ~Actor();
    
        //public function declarations
        void Move(int deltaX, int deltaY);
        void TakeDamage(int value);


        int GetBaseHealth() const;
        int GetBaseDefense() const;
        int GetBaseAttack() const;

        bool CheckInvincibility() const;
        


};