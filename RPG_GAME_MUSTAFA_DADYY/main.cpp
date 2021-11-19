#include <iostream >
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Player.h"

//normalizing function
sf::Vector2f NormalizeVector(sf::Vector2f vector)
{
    float m = sqrt(vector.x * vector.x + vector.y + vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;
    return normalizedVector;
}

int main()
{
    //---------------------------INITIALIZE-------------------------------------------------------------


    //Turning On anti-aliasing
    sf::ContextSettings aa;
    aa.antialiasingLevel = 8;

    //Create window object from RenderWindow class, takes 2 arguments into constructor
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, aa);

    //---------------------------INITIALIZE-------------------------------------------------------------

    Player player;

    // --------------------------LOAD-------------------------------------------------------------------
    
    //Loading Player Sprite

    player.Load();

    
   

    //Loading Enemy Skeleton Sprite
    sf::Texture enemySkeletonTexture;
    sf::Sprite enemySkeletonSprite;
    int EXIndex = 0;
    int EYIndex = 0;
    float skeletonPX = 896;
    float skeletonPY = 476;
    enemySkeletonTexture.loadFromFile("Assets/Skeleton_Enemy/PlayerSkeleton.png");
    enemySkeletonSprite.setTexture(enemySkeletonTexture);
    enemySkeletonSprite.setTextureRect(sf::IntRect(64 * EXIndex, 64 * EYIndex, 64, 64));
    enemySkeletonSprite.setPosition(sf::Vector2f(skeletonPX, skeletonPY));

    // --------------------------LOAD-------------------------------------------------------------------

    //Bullet
    
    std::vector <sf::RectangleShape> bullets;
    float bulletSpeed = 1;
   
    
    

    //---------------------------UPDATE-------------------------------------------------------------

     //Run as long as the window object isOpen, this is the main game loop
    while (window.isOpen())
    {

        //event from the event class, anything that happens with the window
        sf::Event event;

        //if any event occurs within the loop, it gets saved to the "event" variable above
        //pollEvent checks for events
        while (window.pollEvent(event))
        {

            //if the event has the closed type, it closes the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }

        //----------------------------UPDATE-----------------------------------------------------------

        //Player Movement
        player.Update();

        //Bullet 
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(20.f, 10.f)));
            int bulletIndex = bullets.size() - 1;
            sf::Vector2f playerPosition = player.sprite.getPosition();
            sf::Vector2f bulletPosition;
            bulletPosition.x = playerPosition.x + 64.f;
            bulletPosition.y = playerPosition.y + 64.f;
            bullets[bulletIndex].setPosition(bulletPosition);
        }

        for (size_t i = 0; i < bullets.size(); i++)
        {
           
            sf::Vector2f bDirection = enemySkeletonSprite.getPosition() - bullets[i].getPosition();
            bDirection = NormalizeVector(bDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bDirection * bulletSpeed);
        }
        

        //----------------------------DRAW-------------------------------------------------------------
        //clear function, uses the SFML color class
        window.clear(sf::Color::Black);


        window.draw(enemySkeletonSprite);
        window.draw(player.sprite);
        player.Draw();

            for (size_t i = 0; i < bullets.size(); i++)
            {

                window.draw(bullets[i]);

            }

        //displays the frame in the window and ends the current frame
        window.display();
        //----------------------------DRAW------------------------------------------------------------
    }


    return 0;
}