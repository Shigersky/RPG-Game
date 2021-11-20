#include "Math.h"

//normalizing function
sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
    float m = sqrt(vector.x * vector.x + vector.y + vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;
    return normalizedVector;
}