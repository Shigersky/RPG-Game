#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Skeleton.h"

class Player
{

	private:

		sf::Texture texture;
		std::vector <sf::RectangleShape> bullets;
		float bulletSpeed = 1;

	public:
		sf::Sprite sprite;

	public:

		void Initialize(); // called once
		void Load(); // called once
		void Draw(sf::RenderWindow &window); // once per frame
		void Update(Skeleton& skeleton); // once per frame

	

};

