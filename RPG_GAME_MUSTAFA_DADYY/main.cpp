#include <iostream >
#include <SFML/Graphics.hpp>

int main()
{
    //---------------------------INITIALIZE-------------------------------------------------------------
            
    //Turning On anti-aliasing
    sf::ContextSettings aa;
    aa.antialiasingLevel = 8;

    //Create window object from RenderWindow class, takes 2 arguments into constructor
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, aa);

    //Loading Player Sprite
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    int XIndex = 4;
    int YIndex = 2;
    playerTexture.loadFromFile("Assets/Player/Textures/PlayerSkeleton.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(64 * XIndex, 64 * YIndex, 64, 64));
    playerSprite.setScale(sf::Vector2f(2.f, 2.f));

    //Movement Funcs
   

    //---------------------------INITIALIZE-------------------------------------------------------------

    //Run as long as the window object isOpen, this is the main game loop
    while (window.isOpen())
    {

        //---------------------------UPDATE-------------------------------------------------------------
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

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
              
              
               playerSprite.move(sf::Vector2f(0.1, 0.f));

            }

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
           {


               playerSprite.move(sf::Vector2f(-0.1, 0.f));

           }

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
           {


               playerSprite.move(sf::Vector2f(0.f, -0.1));

           }

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
           {


               playerSprite.move(sf::Vector2f(0.f, 0.1));

           }


        //----------------------------DRAW-------------------------------------------------------------
        //clear function, uses the SFML color class
        window.clear(sf::Color::Black);

        window.draw(playerSprite);

        //displays the frame in the window and ends the current frame
        window.display();
        //----------------------------DRAW------------------------------------------------------------
    }

    return 0;
}