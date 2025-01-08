#include "Event_Manager.h"
#include "Observer.h"

namespace Manager
{
	Event_Manager* Event_Manager::instance = nullptr;

	Event_Manager* Event_Manager::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Event_Manager();
		}
		return instance;
	}

	Event_Manager::Event_Manager() :
		Subject()
	{
		pGM = Graphical_Manager::getInstance();
	}

	Event_Manager::~Event_Manager()
	{
	}

	void Event_Manager::run()
	{
		sf::Event event;
		while (pGM->getWindow()->pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				notify((event.key.code));
			}
			else if (event.type == sf::Event::Closed)
			{
				pGM->closeWindow();
			}
		}
	}
}