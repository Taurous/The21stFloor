#pragma once

#include "AxeSystemContainer.h"

#include <axeLib\EventHandler.h>
#include <axeLib\DrawEngine.h>

class Game
{
public:
	Game();
	~Game();

	int run();

private:
	AxeSystemContainer m_systems;

	axe::EventHandler m_events;
	axe::DrawEngine m_draw;
};