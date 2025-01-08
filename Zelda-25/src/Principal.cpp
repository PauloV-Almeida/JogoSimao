#include "../include/Principal.h"

Principal::Principal() :
	pGM(Manager::Graphical_Manager::getInstance()),
	character() 
{
	Entidades::Player* player = new Entidades::Player(sf::Vector2f(100.f, 100.f), sf::Vector2f(50.f, 50.f));
	Entidades::Enemy* enemy = new Entidades::Enemy(sf::Vector2f(100.f, 200.f), sf::Vector2f(50.f, 50.f), player);

	Entidades::Character* p1 = static_cast<Entidades::Character*>(player);
	Entidades::Character* p2 = static_cast<Entidades::Character*>(enemy);

	character.push_back(p1);
	character.push_back(p2);

    run();
}

Principal::~Principal() {

}
   

void Principal::run() {
	while (pGM->windowOpen()) {
		while (pGM->getWindow()->pollEvent(event)) {
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				pGM->closeWindow();
			}
		}
		pGM->clean();
        for (std::size_t i = 0; i < character.size(); i++) {
			character.at(i)->move();
			pGM->draw(character.at(i)->getBody());
        }
		pGM->show();
	}
	character.clear();
}
