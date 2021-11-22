#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class FPS
{

	private:

		sf::Text fpsText;
		sf::Font fpsFont;

	public:

		void Initialize();
		void Load();
		void Update(sf::Clock clock, float deltaTime);
		void Draw(sf::RenderWindow& window);

};

