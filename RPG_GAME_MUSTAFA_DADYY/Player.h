#pragma once
#include <SFML/Graphics.hpp>

class Player
{

	private:

		sf::Texture texture;

	public:
		sf::Sprite sprite;

	public:

		void Initialize(); // called once
		void Load(); // called once
		void Draw(); // once per frame
		void Update(); // once per frame

	

};

