#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{

	private:

		sf::Texture enemySkeletonTexture;

		sf::RectangleShape hitBox;

		sf::Text hpText;
		sf::Font hpFont;

		float width = 64.f;
		float height = 64.f;

	public:

		int health = 0;

		sf::Sprite enemySkeletonSprite;

	public:

		Skeleton();

		void SetHealth(int hp);

	void Initialize();

	void Load();

	void Update();

	void Draw(sf::RenderWindow &window);
};

