#include <iostream >
#include <SFML/Graphics.hpp>

int main()
{

    //Turning On anti-aliasing
    sf::ContextSettings aa;
    aa.antialiasingLevel = 8;

    //Create window object from RenderWindow class, takes 2 arguments into constructor
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, aa);

    //Circle
    sf::CircleShape circle(50.f);
    float xCircle = 10;
    float yCircle = 10;
    circle.setPosition(xCircle, yCircle);
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color::Red);

    //Rectangle
    sf::Vector2f vRectangle;
    vRectangle.x = 0.f;
    vRectangle.y = 0.f;
    sf::RectangleShape rectangle(sf::Vector2f(10.f, 10.f));
    rectangle.setOutlineThickness(10);
    rectangle.setPosition(vRectangle);
    rectangle.setOutlineColor(sf::Color::Blue);
    
    //Polygon
    sf::CircleShape polygon(60.f, 5);
    polygon.setFillColor(sf::Color::Red);
    polygon.setPosition(sf::Vector2f(60.f, 60.f));

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

           /* Move Attempt
           rectangle.move(1.f, 1.f);
            if (vRectangle.x > 800.f || vRectangle.y > 600.f)
            {
                std::cout << "Joe Mama";
                vRectangle.x = 0.f;
                vRectangle.y = 0.f;
            }
            */
        } 
        
        //----------------------------UPDATE-----------------------------------------------------------

        //----------------------------DRAW-------------------------------------------------------------
        //clear function, uses the SFML color class
        window.clear(sf::Color::Black);

        window.draw(circle);
        window.draw(rectangle);
        window.draw(polygon);

        //displays the frame in the window and ends the current frame
        window.display();
        //----------------------------DRAW------------------------------------------------------------
    }

    return 0;
}