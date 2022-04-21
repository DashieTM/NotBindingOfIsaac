//NotBindingOfIsaac     A Shitgaem made by a noob
#include "Player.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <X11/Xlib.h>

int main() 
{
    Display* disp = XOpenDisplay(NULL);
    Screen*  scrn = DefaultScreenOfDisplay(disp);
    int height = scrn->height;
    int width  = scrn->width;
    
    sf::Vector2f MiddleofScreen(960,540);

    sf::RenderWindow window(sf::VideoMode(width, height), "Not Binding Of Isaac");
    
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf"))
        return EXIT_FAILURE;
    

    sf::Texture playersprite;
    if (!playersprite.loadFromFile("bestpone.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(playersprite);
    sprite.setPosition(MiddleofScreen);

    sf::RectangleShape upperbound(sf::Vector2f(1000,5));
    upperbound.setPosition(MiddleofScreen + sf::Vector2f(-500,500));
    upperbound.setFillColor(sf::Color(255,255,255));
    sf::RectangleShape leftbound(sf::Vector2f(1000,5));
    leftbound.rotate(90);
    leftbound.setPosition(MiddleofScreen + sf::Vector2f(-500,-500));
    leftbound.setFillColor(sf::Color(255,255,255));
    sf::RectangleShape rightbound(sf::Vector2f(1000,5));
    rightbound.rotate(90);
    rightbound.setPosition(MiddleofScreen + sf::Vector2f(500,-500));
    rightbound.setFillColor(sf::Color(255,255,255));
    sf::RectangleShape lowerbound(sf::Vector2f(1000,5));
    lowerbound.setPosition(MiddleofScreen + sf::Vector2f(-500,-500));
    lowerbound.setFillColor(sf::Color(255,255,255));

    
    Player* gurri = new Player();

    //sf::Text text((char)gurri->GetPosX() + ", " +  (char)gurri->GetPosY(), font, 50);
    //gurri->Move(3,0);
    //sf::Text text2(std::to_string(gurri->GetPosX()) + ", " +  std::to_string(gurri->GetPosY()) , font, 50);
    //sf::Text text3(std::to_string(width), font, 50);
    

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::KeyPressed)
            {
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    gurri->Move(-1,0);
                    sprite.setPosition(gurri->GetPosX(),gurri->GetPosY());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    gurri->Move(0,1);
                    sprite.setPosition(gurri->GetPosX(),gurri->GetPosY());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    gurri->Move(0,-1);
                    sprite.setPosition(gurri->GetPosX(),gurri->GetPosY());
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    gurri->Move(1,0);
                    sprite.setPosition(gurri->GetPosX(),gurri->GetPosY());
                }
            }
        }
        // Clear screen
        window.clear();
        // Draw the string
        //window.draw(text);
        //window.draw(text2);
        window.draw(upperbound);
        window.draw(lowerbound);
        window.draw(leftbound);
        window.draw(rightbound);
        window.draw(sprite);
        //window.draw(text3);
        // Update the window
        window.display();
    }
}

