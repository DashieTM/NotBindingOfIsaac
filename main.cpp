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
#include "math.h"

double calculateAbsDistance(sf::Vector2f &frst, sf::Vector2f &scnd);


int main() 
{
    Player* gurri = new Player();

    Display* disp = XOpenDisplay(NULL);
    //Screen*  scrn = DefaultScreenOfDisplay(disp);
    //int height = scrn->height;
    //int width  = scrn->width;
    int height = 1080;
    int width = 1920;

    sf::Vector2f MiddleofScreen(960,540);

    sf::RenderWindow window(sf::VideoMode(width, height), "Not Binding Of Isaac");
    
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf"))
        return EXIT_FAILURE;
    

    sf::Texture playersprite;
    if (!playersprite.loadFromFile(gurri->GetSprite()))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(playersprite);
    sprite.setPosition(MiddleofScreen);

    sf::Texture buff;
    if (!buff.loadFromFile("buff.jpg"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite buffsprite(buff);
    buffsprite.setPosition(MiddleofScreen + sf::Vector2f(200,200));

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

    
  
    

    sf::Vector2f upperboundPos = upperbound.getPosition();
    sf::Vector2f lowerboundPos = lowerbound.getPosition(); 
    sf::Vector2f rightboundPos = rightbound.getPosition(); 
    sf::Vector2f leftboundPos = leftbound.getPosition(); 
    sf::Vector2f buffLocation = buffsprite.getPosition();

    bool buffUsed = false;
    bool isDead = false;

    //sf::Text text((char)gurri->GetPosX() + ", " +  (char)gurri->GetPosY(), font, 50);
    //gurri->Move(3,0);
    //sf::Text text(std::to_string(gurri->GetPosX()) + ", " +  std::to_string(gurri->GetPosY()) , font, 10);
    //sf::Text text3(std::to_string(width), font, 50);
    

    while (window.isOpen())
    {
        sf::Vector2f playerLocation = sprite.getPosition();
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {

            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if ( calculateAbsDistance(playerLocation, buffLocation) < 20.0 && !buffUsed)
            {
                if (!gurri->GetInventory()->isFull()) {
                    Item* sonic = new Item(1,1,1,false,true);
                    gurri->AddItem(*sonic);
                }
            }
            if ( calculateAbsDistance(playerLocation, upperboundPos) < 5.0 || calculateAbsDistance(playerLocation, lowerboundPos) < 5.0 || calculateAbsDistance(playerLocation, rightboundPos) < 5.0 || calculateAbsDistance(playerLocation, leftboundPos) < 5.0) {
                isDead = true;
               // delete gurri;
            }
            
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
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                {
                    if (!gurri->GetInventory()->isEmpty()) {
                        gurri->UseLastItem();
                        buffUsed = false;
                    }
                }
                 if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
                {
                  
                }
            }
        }
        sf::Text text(std::to_string(gurri->GetBaseAttack()), font, 12);
        sf::Text text2(std::to_string(gurri->GetBaseDefense()), font, 12);
        sf::Text text3(std::to_string(gurri->GetBaseHealth()), font, 12);
        sf::Text text4(std::to_string(gurri->GetSpeed()), font, 12);
        sf::Text text5(std::to_string(gurri->GetInventory()->returnSize()), font, 12);
        text2.setPosition(sf::Vector2f(text2.getPosition().x,text.getPosition().y + 20));
        text3.setPosition(sf::Vector2f(text3.getPosition().x,text2.getPosition().y + 20));
        text4.setPosition(sf::Vector2f(text4.getPosition().x,text3.getPosition().y + 20));
        text5.setPosition(sf::Vector2f(text5.getPosition().x,text4.getPosition().y + 20));
        // Clear screen
        window.clear();
        // Draw the string
        window.draw(text);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        //window.draw(text2);
        window.draw(upperbound);
        window.draw(lowerbound);
        window.draw(leftbound);
        window.draw(rightbound);
        if (!isDead) {
            window.draw(sprite);
        }
        window.draw(buffsprite);
        //window.draw(text3);
        // Update the window
        window.display();
    }
}

double calculateAbsDistance(sf::Vector2f &frst, sf::Vector2f &scnd) {
    sf::Vector2f distance = frst - scnd;
    return abs(sqrt((distance.x * distance.x) + (distance.y * distance.y)));
}

//double calculateWallDistance(sf::Vector2f &player) {
//    if
//}
