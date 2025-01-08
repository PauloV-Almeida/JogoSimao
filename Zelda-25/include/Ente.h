#pragma once

#include <iostream>
#include "Graphical_Manager.h"
#include "IDs.h"


class Ente
{
protected:
	static Manager::Graphical_Manager* pGM;
public:
	Ente();
	virtual ~Ente();
	virtual void run() = 0;

};





