#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphical_Manager.h"
#include "Player.h"
#include "Enemy.h"

class Principal
{
private:
	Manager::Graphical_Manager* pGM;
	sf::Event event;
	std::vector<Entidades::Character*> character;
public:
	Principal();
	~Principal();	
	void run();
};


