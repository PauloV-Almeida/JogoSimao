#pragma once

#include "Graphical_Manager.h"

#include "Subject.h"

namespace Observers
{
	class Observer;
}

namespace Manager
{
	class Event_Manager : public Subject
	{
	private:
		Graphical_Manager* pGM;
		//padrao singleton
		Event_Manager();
		static Event_Manager* instance;
	public:
		~Event_Manager();
		static Event_Manager* getInstance();
		void run();
	};
}
