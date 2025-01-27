#include "../include/Player.h"

namespace Entidades
{
	Player::Player(const sf::Vector2f pos,const sf::Vector2f tam) :
		Character(pos, tam)
	{
		body.setPosition(pos);
		body.setFillColor(sf::Color::Green);
		run();
	}
	Player::Player()
	{
	}
	Player::~Player()
	{

	}
	void Player::run()
	{
		speed = sf::Vector2f(1.f, 1.f);
	}

	const sf::RectangleShape Player::getBody()
	{
		return body;
	}
	void Player::move()
	{
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			body.move(0.f, -speed.y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			body.move(0.f, speed.y);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			body.move(-speed.x, 0.f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			body.move(speed.x, 0.f);
		}
	}
}
