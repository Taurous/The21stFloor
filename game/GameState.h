#pragma once

#include <axeLib/StateManager.h>

#include <allegro5/allegro.h>

#include "Entity.h"

class GameState : public axe::AbstractState
{
public:
	GameState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw);
	~GameState();

	void pause();
	void resume();

	void handleEvents();
	void update(unsigned long long deltaTime);
	void draw();

private:
	std::vector<Entity> entities;
	bool moving;
	int num_alive;
	axe::Timer t;
};