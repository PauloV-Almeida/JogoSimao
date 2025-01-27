#pragma once
#include "Character.h"

namespace Entidades {

	class Player : public Character
	{
	private:
	public:
		Player(const sf::Vector2f pos,const sf::Vector2f tam);
		Player(sf::RectangleShape body);
		Player();
		~Player();
		const sf::RectangleShape getBody();
		void run();
		void move();
	};
}