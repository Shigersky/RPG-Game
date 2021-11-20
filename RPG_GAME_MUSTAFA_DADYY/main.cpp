#include <iostream >
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Player.h"
#include "Skeleton.h"

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

    player.Initialize();

    Skeleton skeleton;

    skeleton.Initialize();

    // --------------------------LOAD-------------------------------------------------------------------
    
    //Loading Player Sprite

    player.Load();

    //Loading Enemy Skeleton Sprite
  
    skeleton.Load();

    // --------------------------LOAD-------------------------------------------------------------------

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
        player.Update(skeleton);

        //----------------------------DRAW-------------------------------------------------------------
        //clear function, uses the SFML color class
        window.clear(sf::Color::Black);

        skeleton.Draw(window);
        player.Draw(window);

    
        

        //displays the frame in the window and ends the current frame
        window.display();
        //----------------------------DRAW------------------------------------------------------------
    }

    return 0;
}