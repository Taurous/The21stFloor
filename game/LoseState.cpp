#include "LoseState.h"

LoseState::LoseState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw) : axe::AbstractState(states, input, events, draw)
{
	al_init_font_addon();
	al_init_ttf_addon();
	axe::log(axe::LOGGER_MESSAGE, "In Lose State\n");
	f = al_load_font("This is the Future.ttf", 62, 0);
	fs = al_load_font("This is the Future.ttf", 26, 0);

	m_states.setDrawAll(true);
}

LoseState::~LoseState()
{
	axe::log(axe::LOGGER_MESSAGE, "Destroying Lose State...\n");

	al_destroy_font(f);
	al_destroy_font(fs);
	m_states.setDrawAll(false);
}

void LoseState::update()
{

}

void LoseState::handleEvents()
{
	if (m_input.isKeyPressed(ALLEGRO_KEY_SPACE))
	{
		m_states.popState();
	}
}

void LoseState::draw()
{
	al_draw_text(f, al_map_rgb(60, 60, 150), float(m_draw.getWindow().getWidth() / 2) + 2.f, float(m_draw.getWindow().getHeight() / 2) - 29.F, ALLEGRO_ALIGN_CENTER, "YOU LOSE");
	al_draw_text(f, al_map_rgb(200, 200, 200), m_draw.getWindow().getWidth() / 2, m_draw.getWindow().getHeight() / 2 - 30.F, ALLEGRO_ALIGN_CENTER, "YOU LOSE");
	al_draw_text(fs, al_map_rgb(60, 60, 150), float(m_draw.getWindow().getWidth() / 2) + 2.f, float(m_draw.getWindow().getHeight() / 2) + 51.f, ALLEGRO_ALIGN_CENTER, "PRESS SPACE TO RETRY");
	al_draw_text(fs, al_map_rgb(200, 200, 200), m_draw.getWindow().getWidth() / 2, m_draw.getWindow().getHeight() / 2+50, ALLEGRO_ALIGN_CENTER, "PRESS SPACE TO RETRY");
}

void LoseState::pause()
{

}

void LoseState::resume()
{

}