#include "GameState.h"

#include <ctime>
#include <iostream>

const int max_speed_ = 100;
const int min_speed_ = 10;

Entity createEntity(int bound_x, int bound_y, int min_speed, int max_speed)
{
	//double x = rand() % bound_x;
	//double y = rand() % bound_y;

	double x = 500;
	double y = 200;

	Entity e;
	e.pos = vec2(x, y);

	vec2 dir = vec2(0, -1); //vec2::randomDirection();
	vec2::nudgeDirection(ALLEGRO_PI / 4.f, dir); 

	e.speed = dir * double((rand() % (max_speed - min_speed)) + min_speed);
	e.accel = dir * 10.f;
	e.alive = true;
	e.alpha = 0.f;
	e.angle = float(rand() % 360) / (2.f * ALLEGRO_PI);

	return e;
}

GameState::GameState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw)
	: axe::AbstractState(states, input, events, draw), moving(false), num_alive(0)
{
	bmp = al_load_bitmap("snowflake.png");

	srand(time(NULL));

	int w = m_draw.getWindow().getWidth();
	int h = m_draw.getWindow().getHeight();

	for (int i = 0; i < 1000; ++i)
	{
		Entity e = createEntity(w, h, max_speed_, min_speed_);
		e.alive = false;

		entities.push_back(e);
	}
}

GameState::~GameState()
{
	entities.clear();
}

void GameState::update(unsigned long long deltaTime)
{
	int respawns = 0;
	if (moving)
	{
		int w = m_draw.getWindow().getWidth();
		int h = m_draw.getWindow().getHeight();

		for (auto &e : entities)
		{
			if (!e.alive)
			{
				if (respawns >= 5 || num_alive > 600) continue;
				e = createEntity(w, h, max_speed_, min_speed_);
				num_alive++;
				respawns++;
			}
			else
			{
				if (e.alpha < 1.f) e.alpha += 0.1f;

				e.pos = e.pos + (e.speed * deltaTime / 1000.f);
				e.speed += vec2(0, 100) * (deltaTime / 1000.f);

				if ((e.pos.x < 0 || e.pos.x > w || e.pos.y > h) && e.alive)
				{
					e.alive = false;
					num_alive--;
				}
			}
		}
	}
}

void GameState::handleEvents()
{
	if (m_input.isKeyPressed(ALLEGRO_KEY_SPACE))
	{
		moving = !moving;
	}
	if (m_input.isKeyPressed(ALLEGRO_KEY_I))
	{
		std::cout << num_alive << std::endl;
	}
}

void GameState::draw()
{
	al_hold_bitmap_drawing(true);
	for (auto &e : entities)
	{
		if (e.alive) al_draw_tinted_rotated_bitmap(bmp, al_map_rgba_f(1, 1, 1, e.alpha), 15, 15, e.pos.x, e.pos.y, e.angle, 0); //al_draw_rectangle(e.pos.x - 8, e.pos.y - 8, e.pos.x + 8, e.pos.y + 8, al_map_rgb(e.r, 0, 0), 2);
	}
	al_hold_bitmap_drawing(false);
}

void GameState::pause()
{

}

void GameState::resume()
{

}