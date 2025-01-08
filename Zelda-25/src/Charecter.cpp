#include "../include/Character.h"

namespace Entidades
{
	Character::Character(const sf::Vector2f pos, sf::Vector2f tam) :
		body(sf::RectangleShape(tam))
	{
		body.setPosition(pos);
	}
	Character::Character()
	{
	}
	Character::~Character()
	{
	}
	const sf::RectangleShape Character::getBody()
	{
		return body;
	}
}