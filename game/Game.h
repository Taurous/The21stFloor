#pragma once

#include <axeLib/InputHandler.h>
#include <axeLib/EventHandler.h>
#include <axeLib/DrawEngine.h>
#include <axeLib/StateManager.h>

class Game
{
public:
	Game();
	~Game();

	void run();

private:
	axe::InputHandler m_input;
	axe::EventHandler m_events;
	axe::DrawEngine m_draw;
	axe::StateManager m_states;
};