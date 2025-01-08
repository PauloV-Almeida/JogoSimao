#pragma once

#include "Event_Manager.h"
#include "Graphical_Manager.h"

namespace Observers
{
	class Observer
	{
	protected:
		Manager::Event_Manager* pEM;
		Manager::Graphical_Manager* pGM;
	public:
		Observer();
		virtual ~Observer();

		virtual void notify(sf::Keyboard::Key key_code) = 0;
	};
}
