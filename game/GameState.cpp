#include "GameState.h"

#include <ctime>
#include <iostream>

const int max_speed_ = 100;
const int min_speed_ = 10;

Entity createEntity(int bound_x, int bound_y, int min_speed, int max_speed)
{
	double x = rand() % (bound_x * 3) - bound_x;
	double y = -50;//rand() % bound_y;

//	double x = 500;
//	double y = 200;

	Entity e;
	e.pos = vec2(x, y);

	vec2 dir = vec2::randomDirection();
//	vec2 dir = vec2(0, -1);
//	vec2::nudgeDirection(ALLEGRO_PI / 4.f, dir); 

	e.speed = dir * double((rand() % (max_speed - min_speed)) + min_speed);
	e.speed.x = 0;
	e.accel = dir * 10.f;
	e.alive = true;
	e.alpha = 0.f;
	e.angle = float(rand() % 360) / (2.f * ALLEGRO_PI);

	return e;
}

GameState::GameState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw)
	: axe::AbstractState(states, input, events, draw), moving(true), num_alive(0)
{
	srand(time(NULL));

	int w = m_draw.getWindow().getWidth();
	int h = m_draw.getWindow().getHeight();

	entities.reserve(10000);

	for (int i = 0; i < 10000; ++i)
	{
		Entity e = createEntity(w, h, max_speed_, min_speed_);
		e.alive = false;

		entities.push_back(e);
	}

	std::cout << "sizeof(Entity) = " << sizeof(Entity) << std::endl << "total in kbytes = " << float(sizeof(Entity) * 1000) / 1024.f << std::endl;

	t.start();
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

		vec2 wave = vec2(sin(float(t.elapsed().count()) / 400.f) * 3.f, 0);

		for (auto &e : entities)
		{
			if (!e.alive)
			{
				if (respawns >= 5 || num_alive > 5000) continue;
				e = createEntity(w, h, max_speed_, min_speed_);
				num_alive++;
				respawns++;
			}
			else
			{
				if (e.alpha < 1.f) e.alpha += 0.1f;

				e.pos = e.pos + (e.speed * deltaTime / 1000.f);
				e.speed += vec2(0, 200) * (deltaTime / 1000.f); // gravity
				//e.speed += vec2(-200, 0) * (deltaTime / 1000.f); // wind
				e.speed += wave;

				if ((e.pos.y > h) && e.alive)
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
	for (auto const &e : entities)
	{
		if (e.alive) al_draw_rectangle(e.pos.x - 8, e.pos.y - 8, e.pos.x + 8, e.pos.y + 8, al_map_rgba_f(1, 1, 1, e.alpha), 2);
	}
}

void GameState::pause()
{

}

void GameState::resume()
{

}