//NotBindingOfIsaac     A Shitgaem made by a noob
#pragma once
#include "Entity.h"

class Actor : public Entity
{
    protected:
        //movement
        float speed;


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
        Actor(float posX, float posY,float Aspeed, int attack, int defense, int health, bool invincible, int h, int i);
        ~Actor();
    
        //public function declarations
        void Move(float deltaX, float deltaY);
        void TakeDamage(int value);
        void ModifySpeed(int power);
        void ModifyDamage(int power);
        void ModifyHealth(int power);
        void ModifyDefense(int power);

        int GetBaseHealth() const;
        int GetBaseDefense() const;
        int GetBaseAttack() const;
        float GetSpeed() const;

        bool CheckInvincibility() const;
        


};