#pragma once

#include <axeLib/StateManager.h>

#include <allegro5/allegro.h>

#include "vec2.h"

class JackState : public axe::AbstractState
{
public:
	JackState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw);
	~JackState();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void draw();

private:
	ALLEGRO_BITMAP *ejack_handle;
	ALLEGRO_BITMAP *ejack_body;

	vec2 jack_position;
	vec2 jack_direction;

	double prev_accel;
	double velocity;
	double steering_angle;

	axe::Timer t;
	axe::m_secs prev_time;
};