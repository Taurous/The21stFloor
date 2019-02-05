#pragma once

#include <axeLib/StateManager.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class PauseState : public axe::AbstractState
{
public:
	PauseState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw);
	~PauseState();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void draw();

private:
	ALLEGRO_FONT *f;
};