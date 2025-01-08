#include "Subject.h"
#include "Observer.h"

namespace Manager
{
	Subject::Subject()
	{
		list_observers.clear();
	}

	Subject::~Subject()
	{
		for (it = list_observers.begin(); it != list_observers.end(); it++)
		{
			delete (*it);
		}
		list_observers.clear();
	}

	void Subject::detach(Observers::Observer* pObserver)
	{
		list_observers.remove(pObserver);
	}

	void Subject::attach(Observers::Observer* pObserver)
	{
		list_observers.push_back(pObserver);
	}

	void Subject::notify(sf::Keyboard::Key key_code)
	{
		for (it = list_observers.begin(); it != list_observers.end(); it++)
		{
			(*it)->notify(key_code);
		}
	}
}