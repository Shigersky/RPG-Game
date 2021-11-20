#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{

	private:

		sf::Texture enemySkeletonTexture;

		sf::RectangleShape hitBox;

		float width = 64.f;
		float height = 64.f;

	public:

		sf::Sprite enemySkeletonSprite;

	public:

	void Initialize();

	void Load();

	void Draw(sf::RenderWindow &window);
};

