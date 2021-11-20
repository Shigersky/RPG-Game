#include "Skeleton.h"

void Skeleton::Load()
{
    int EXIndex = 0;
    int EYIndex = 0;
    float skeletonPX = 896;
    float skeletonPY = 476;
    enemySkeletonTexture.loadFromFile("Assets/Skeleton_Enemy/PlayerSkeleton.png");
    enemySkeletonSprite.setTexture(enemySkeletonTexture);
    enemySkeletonSprite.setTextureRect(sf::IntRect(64 * EXIndex, 64 * EYIndex, 64, 64));
    enemySkeletonSprite.setPosition(sf::Vector2f(skeletonPX, skeletonPY));
}

void Skeleton::Draw(sf::RenderWindow &window)
{
    window.draw(enemySkeletonSprite);
}
