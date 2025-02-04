#pragma once
#include <time.h> // usando para gerar enemy aleatorio

//atualizar o fabs
#include <math.h>
#define SPEED_ENEMY_X 0.025f
#define SPEED_ENEMY_Y 0.025f

#define PURSUIT_RADIUS_X 200.f
#define PURSUIT_RADIUS_Y 200.f

#include "Character.h"


namespace Entidades
{
    class Player;
}


namespace Entidades
{

    class Enemy : public Character {
    private:
		Entidades::Player* player;
		sf::Clock clock;
        short moveRandom;
        void start();
    public:
        Enemy(const sf::Vector2f pos, sf::Vector2f tam, Entidades::Player* player);
        ~Enemy();
		void ChasePlayer(sf::Vector2f posPlayer, sf::Vector2f posEnemy);
		void RadomMove();
		void move();

    };
}