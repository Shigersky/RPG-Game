#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{

	private:

		sf::Texture enemySkeletonTexture;

	public:

		sf::Sprite enemySkeletonSprite;

	public:

	void Load();

	void Draw(sf::RenderWindow &window);
};

