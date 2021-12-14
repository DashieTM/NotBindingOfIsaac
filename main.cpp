#include "Actor.h"
#include <iostream>
#include <string>

int main() 
{
    std::cout << "Henlo birb." << std::endl;

    Actor* gurri = new Actor(5,5,10,20,10,50,false);

    std::cout << gurri->GetPosX() << ", " << gurri->GetPosY() << std::endl;
    gurri->Move(3,0);
    std::cout << gurri->GetPosX() << ", " << gurri->GetPosY() << std::endl;
    

}