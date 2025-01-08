#include "../include/Enemy.h"
#include "../include/Player.h"
namespace Entidades
{
	Enemy::Enemy(const sf::Vector2f pos,const sf::Vector2f tam, Entidades::Player* player) :
		Character(pos, tam),
		clock(),
		player(player)
	{
		body.setFillColor(sf::Color::Red);
		start();
		srand(time(NULL));
		moveRandom = rand() % 4;
	}
	Enemy::~Enemy()
	{
	}
	void Enemy::start()
	{
		speed = sf::Vector2f(SPEED_ENEMY_X, SPEED_ENEMY_Y);
	}
	void Enemy::ChasePlayer(sf::Vector2f posPlayer, sf::Vector2f posEnemy)
	{
		if (posPlayer.x - posEnemy.x > 0.f)
		{
			body.move(speed.x, 0.f);
		}
		else 
		{
			body.move(-speed.x, 0.f);
		}
		if (posPlayer.y - posEnemy.y > 0.f)
		{
			body.move(0.f, speed.y);
		}
		else 
		{
			body.move(0.f, -speed.y);
		}
	}
	void Enemy::RadomMove()
	{

	}
	void Enemy::move()
	{
		sf::Vector2f posPlayer = player->getBody().getPosition();
		sf::Vector2f posEnemy = body.getPosition();
		if (fabs(posPlayer.x - posEnemy.x) <= PURSUIT_RADIUS_X && fabs(posPlayer.y - posEnemy.y) <= PURSUIT_RADIUS_Y)
		{
			ChasePlayer(posPlayer, posEnemy);
		}
	}
}