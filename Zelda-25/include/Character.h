#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <iostream>

namespace Entidades
{
	class Character {
	protected:
		sf::RectangleShape body;
		sf::Vector2f speed;
	public:
		Character(const sf::Vector2f pos, sf::Vector2f tam);
		Character(); // Adicionando construtor padrão
		virtual ~Character();
		const sf::RectangleShape getBody();
		virtual void move() = 0;
	};
}

#endif // CHARACTER_H
