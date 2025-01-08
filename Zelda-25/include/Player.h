#pragma once
#include "Character.h"

namespace Entidades {

	class Player : public Character
	{
	private:
		sf::RectangleShape body;
		sf::Vector2f speed;
		void run();
	public:
		Player(const sf::Vector2f pos, sf::Vector2f tam);
		Player(sf::RectangleShape body);
		Player();
		~Player();
		const sf::RectangleShape& getBody();
		void move();
	};
}