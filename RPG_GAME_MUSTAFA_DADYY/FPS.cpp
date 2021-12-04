#include "FPS.h"

FPS::FPS() : timer(0)
{
    
}

void FPS::Initialize()
{
    fpsText.setFont(fpsFont);
    fpsText.setScale(1.f, 1.f);
    fpsText.setPosition(sf::Vector2f(20.f, 20.f));
}

void FPS::Load()
{
    fpsFont.loadFromFile("Assets/Fonts/arial.ttf");

}

void FPS::Update(sf::Clock clock, float deltaTime)
{
    timer += deltaTime;
    if(timer >= 250.0f)
    {

        float fps = 1000.0f / deltaTime;
        std::string fpsString = "FPS :" + std::to_string((int)fps);
        fpsText.setString(fpsString);
        timer = 0;
    }
    
}

void FPS::Draw(sf::RenderWindow& window)
{
    window.draw(fpsText);
}