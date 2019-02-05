#pragma once

#include <axeLib/StateManager.h>

#include <allegro5/allegro.h>

class GameState : public axe::AbstractState
{
public:
	GameState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw);
	~GameState();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void draw();

private:

};