#include "PauseState.h"

PauseState::PauseState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw) : axe::AbstractState(states, input, events, draw)
{
	al_init_font_addon();
	al_init_ttf_addon();
	axe::log(axe::LOGGER_MESSAGE, "In Pause State\n");
	f = al_load_font("This is the Future.ttf", 42, 0);

	m_states.setDrawAll(true);
}

PauseState::~PauseState()
{
	axe::log(axe::LOGGER_MESSAGE, "Destroying Pause State...\n");

	al_destroy_font(f);
	m_states.setDrawAll(false);
}

void PauseState::update()
{

}

void PauseState::handleEvents()
{
	if (m_input.isKeyPressed(ALLEGRO_KEY_SPACE))
	{
		m_states.popState();
	}
}

void PauseState::draw()
{
	al_draw_text(f, al_map_rgb(60, 60, 150), float(m_draw.getWindow().getWidth() / 2) + 2.f, float(m_draw.getWindow().getHeight() / 2) + 1.f, ALLEGRO_ALIGN_CENTER, "PAUSED");
	al_draw_text(f, al_map_rgb(200, 200, 200), m_draw.getWindow().getWidth() / 2, m_draw.getWindow().getHeight() / 2, ALLEGRO_ALIGN_CENTER, "PAUSED");
}

void PauseState::pause()
{

}

void PauseState::resume()
{

}