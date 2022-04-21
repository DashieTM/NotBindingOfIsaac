//NotBindingOfIsaac     A Shitgaem made by a noob
#pragma once
#include "Entity.h"
#include "Inventory.h"



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

        //inventory
        Inventory *inv;

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
        void UseItem(Item &item);
        void AddItem(Item &item);
        void RemoveItem(Item &item);


        int GetBaseHealth() const;
        int GetBaseDefense() const;
        int GetBaseAttack() const;
        float GetSpeed() const;
        Inventory GetInventory();

        bool CheckInvincibility() const;
        


};