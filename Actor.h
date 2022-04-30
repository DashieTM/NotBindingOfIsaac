//NotBindingOfIsaac     A Shitgaem made by a noob
#pragma once
#include "Entity.h"
#include "Inventory.h"
#include <string>



class Actor : public Entity
{
    protected:
        //movement
        float speed;


        //combat
        float baseAttack;
        float baseDefense;
        float baseHealth;
        bool b_IsInvincible;
        bool b_isAlive = true;

        //figure
        int width;
        int length;

        //inventory
        Inventory inv;

        std::string sprite;

    public:
        Actor();
        Actor(float posX, float posY,float Aspeed, float attack, float defense, float health, bool invincible, int h, int i, std::string pic);
        ~Actor();
    
        //public function declarations
        void Move(float deltaX, float deltaY);
        void TakeDamage(float value);
        void ModifySpeed(float power);
        void ModifyDamage(float power);
        void ModifyHealth(float power);
        void ModifyDefense(float power);
        void UseItem(Item &item);
        void AddItem(Item &item);
        void RemoveItem(Item &item);
        void UseLastItem();
        void SetSprite(std::string pic);
        void Destroy();



        float GetBaseHealth() const;
        float GetBaseDefense() const;
        float GetBaseAttack() const;
        float GetSpeed() const;
        Inventory* GetInventory();
        std::string GetSprite();

        bool CheckInvincibility() const;
        bool GetAliveStatus() const;
        


};