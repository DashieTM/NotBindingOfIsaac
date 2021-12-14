#include "Actor.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf"))
        return EXIT_FAILURE;
    

    std::cout << "Henlo birb." << std::endl;

    Actor* gurri = new Actor(5,5,10,20,10,50,false);

    //sf::Text text((char)gurri->GetPosX() + ", " +  (char)gurri->GetPosY(), font, 50);
    gurri->Move(3,0);
    sf::Text text2(std::to_string(gurri->GetPosX()) + ", " +  std::to_string(gurri->GetPosY()) , font, 50);
    //sf::Text text3("Henlo Birb.", font, 50);
    

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the string
        //window.draw(text);
        //window.draw(text2);
        window.draw(text2);
        // Update the window
        window.display();
    }
}

