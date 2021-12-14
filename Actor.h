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



    public:
        Actor();
        Actor(int posX, int posY,int Aspeed, int attack, int defense, int health, bool invincible);
        ~Actor();
    
        //public function declarations
        void Move(int deltaX, int deltaY);
        void TakeDamage(int value);

        int GetBaseHealth() const;
        int GetBaseDefense() const;
        int GetBaseAttack() const;

        bool CheckInvincibility() const;
        


};