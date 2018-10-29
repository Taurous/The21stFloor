#include "Game.h"

Game::Game() : m_events(30)
{
	int screen_width = 1024;
	int screen_height = 768;

	std::string windName = "The 21st Floor";
	m_draw.createWindow(screen_width, screen_height, m_events.getEventQueue(), ALLEGRO_FULLSCREEN_WINDOW).setWindowTitle(windName);
}

void Game::run()
{
	axe::Timer t;
	m_events.startTimer();
	while (m_states.running())
	{
		if (m_events.handleEvents())
		{
			m_draw.handleEvents(m_events.getEvent());

			m_input.getInput(m_events.getEvent());

			if (m_events.eventIs(ALLEGRO_EVENT_DISPLAY_CLOSE))
			{
				m_states.quit();
			}
			else if (m_events.eventIs(ALLEGRO_EVENT_TIMER))
			{
				// tick
			}

			if (m_input.isKeyPressed(ALLEGRO_KEY_ESCAPE))
			{
				m_states.quit();
			}
		}

		if (m_events.eventQueueEmpty())
		{
			axe::flipAndClear(al_map_rgb(0, 0, 0));
		}
	}
}

Game::~Game()
{

}