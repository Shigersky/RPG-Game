#include "Player.h"
#include "Math.h"

Player::Player() : bulletSpeed(0.5f), playerSpeed(3.0f), fireRate(200.f), fireRateTimer(0)
{

}

void Player::Initialize()
{
    //Initializng Player Sprite
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(64 * XIndex, 64 * YIndex, width, height));
    sprite.setScale(sf::Vector2f(2.f, 2.f));
    sprite.setPosition(sf::Vector2f(20.f, 20.f));

    //Initializng Player Hitbox
    
    hitBox.setSize(sf::Vector2f(width * sprite.getScale().x, height * sprite.getScale().y));
    hitBox.setOutlineColor(sf::Color::Red);
    hitBox.setFillColor(sf::Color::Transparent);
    hitBox.setOutlineThickness(1.f);
    hitBox.setPosition(sprite.getPosition());
}

void Player::Load()
{

    
    texture.loadFromFile("Assets/Player/Textures/PlayerSkeleton.png");


}

void Player::Draw(sf::RenderWindow &window)
{
    //Drawing Player Sprite
    window.draw(sprite);

    //Player Hitbox
    window.draw(Player::hitBox);

    //Drawing Bullets
    for (size_t i = 0; i < bullets.size(); i++)
    {

        window.draw(bullets[i]);

    }
}

void Player::Update(float deltaTime, Skeleton& skeleton)

    //Player Movement
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {


        sprite.move(sf::Vector2f(0.1, 0.f) * deltaTime * playerSpeed);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {


        sprite.move(sf::Vector2f(-0.1, 0.f) * deltaTime * playerSpeed);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {


        sprite.move(sf::Vector2f(0.f, -0.1) * deltaTime * playerSpeed);

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {


        sprite.move(sf::Vector2f(0.f, 0.1) * deltaTime * playerSpeed);

    }

    //---------------------------------------------------------------------------------------------------------------------------------

    // Bullet Movement 
    
    fireRateTimer += deltaTime;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && fireRateTimer >= fireRate)
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(20.f, 10.f)));
        int bulletIndex = bullets.size() - 1;
        sf::Vector2f playerPosition = sprite.getPosition();
        sf::Vector2f bulletPosition;
        bulletPosition.x = playerPosition.x + 64.f;
        bulletPosition.y = playerPosition.y + 64.f;
        bullets[bulletIndex].setPosition(bulletPosition);
        fireRateTimer = 0;
    }

    for (size_t i = 0; i < bullets.size(); i++)
    {

        sf::Vector2f bDirection = skeleton.enemySkeletonSprite.getPosition() - bullets[i].getPosition();
        bDirection = Math::NormalizeVector(bDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bDirection * bulletSpeed * deltaTime);

        if (Math::CheckRectCollision(bullets[i].getGlobalBounds(), skeleton.enemySkeletonSprite.getGlobalBounds()))
        {
            skeleton.SetHealth(-10);
            bullets.erase(bullets.begin() + i);
            std::cout << skeleton.health <<"\n";
        }
    }

    //Hitbox Update

    hitBox.setPosition(sprite.getPosition());

    if (Math::CheckRectCollision(sprite.getGlobalBounds(), skeleton.enemySkeletonSprite.getGlobalBounds()))
    {
        std::cout << "Lessgo";
    }
        

}
