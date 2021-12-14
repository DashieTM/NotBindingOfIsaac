#pragma once
#include <tuple>

class Actor
{
    private:
    
    //movement
    int speed;
    int x;
    int y;
    //int z; probably not needed


    //combat
    int baseAttack;
    int baseDefense;
    int baseHealth;
    bool b_IsInvincible;



    public:
    Actor();
    Actor(int PosX, int PosY, int Aspeed, int damage, int defense, int health, bool invincible);
    ~Actor();
   
    //public function declarations
    void Move(int deltaX, int deltaY);
    void TakeDamage(int value);

    std::tuple<int, int> GetPos() const;
    int GetPosX() const;
    int GetPosY() const;
    int GetBaseHealth() const;
    int GetBaseDefense() const;
    int GetBaseAttack() const;
    bool CheckInvincibility() const;
    //int GetPosZ() const; 
    


};