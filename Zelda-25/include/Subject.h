#pragma once

#include <list>
#include "Graphical_Manager.h"

namespace Observers
{
	class Observer;
}

namespace Manager
{
	class Subject
	{
	protected:
		std::list<Observers::Observer*> list_observers;
		std::list<Observers::Observer*>::iterator it;
	public:
		Subject();
		virtual ~Subject();
		void detach(Observers::Observer* pObserver);
		void attach(Observers::Observer* pObserver);
		void notify(sf::Keyboard::Key key_code);
	};
}