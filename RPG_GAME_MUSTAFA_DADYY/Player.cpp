#include "Player.h"
#include <iostream>


void Player::Initialize()
{
}

void Player::Load()
{

    int XIndex = 4;
    int YIndex = 2;
    texture.loadFromFile("Assets/Player/Textures/PlayerSkeleton.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(64 * XIndex, 64 * YIndex, 64, 64));
    sprite.setScale(sf::Vector2f(2.f, 2.f));
    sprite.setPosition(sf::Vector2f(20.f, 20.f));

}

void Player::Draw()
{

}

void Player::Update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {


        sprite.move(sf::Vector2f(0.1, 0.f));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {


        sprite.move(sf::Vector2f(-0.1, 0.f));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {


        sprite.move(sf::Vector2f(0.f, -0.1));

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {


        sprite.move(sf::Vector2f(0.f, 0.1));

    }
}
