#include "Skeleton.h"

void Skeleton::Initialize()
{
    
    //Initializing Skeleton
    int EXIndex = 0;
    int EYIndex = 0;
    float skeletonPX = 896;
    float skeletonPY = 476;

    enemySkeletonSprite.setTexture(enemySkeletonTexture);
    enemySkeletonSprite.setTextureRect(sf::IntRect(64 * EXIndex, 64 * EYIndex, 64, 64));
    enemySkeletonSprite.setPosition(sf::Vector2f(skeletonPX, skeletonPY));
    enemySkeletonSprite.setScale(sf::Vector2f(2.f, 2.f));

    //Initializing Skeleton Hitbox
    hitBox.setSize(sf::Vector2f(width * enemySkeletonSprite.getScale().x, height * enemySkeletonSprite.getScale().y));
    hitBox.setOutlineColor(sf::Color::Blue);
    hitBox.setFillColor(sf::Color::Transparent);
    hitBox.setOutlineThickness(1.f);
    hitBox.setPosition(enemySkeletonSprite.getPosition());

}

void Skeleton::Load()
{
    enemySkeletonTexture.loadFromFile("Assets/Skeleton_Enemy/PlayerSkeleton.png");
}



void Skeleton::Draw(sf::RenderWindow &window)
{
    window.draw(enemySkeletonSprite);
    window.draw(hitBox);
}
