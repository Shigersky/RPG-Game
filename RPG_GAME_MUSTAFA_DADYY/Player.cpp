#include "Player.h"
#include "Math.h"

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

void Player::Draw(sf::RenderWindow &window)
{
    //Drawing Player Sprite
    window.draw(sprite);

    //Drawing Bullets
    for (size_t i = 0; i < bullets.size(); i++)
    {

        window.draw(bullets[i]);

    }
}

void Player::Update(Skeleton& skeleton)

    //Player Movement
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

    // Bullet Movement 

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(20.f, 10.f)));
        int bulletIndex = bullets.size() - 1;
        sf::Vector2f playerPosition = sprite.getPosition();
        sf::Vector2f bulletPosition;
        bulletPosition.x = playerPosition.x + 64.f;
        bulletPosition.y = playerPosition.y + 64.f;
        bullets[bulletIndex].setPosition(bulletPosition);
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {

        sf::Vector2f bDirection = skeleton.enemySkeletonSprite.getPosition() - bullets[i].getPosition();
        bDirection = Math::NormalizeVector(bDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bDirection * bulletSpeed);
    }


}
