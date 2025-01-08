#include "Observer.h"

namespace Observers
{
	Observer::Observer()
	{
		this->pEM = Manager::Event_Manager::getInstance();
		this->pGM = Manager::Graphical_Manager::getInstance();
	}
	Observer::~Observer()
	{
		pEM->detach(this);
	}
}