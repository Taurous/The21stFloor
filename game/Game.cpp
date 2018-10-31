#include "Game.h"

#include "GameState.h"

Game::Game() : m_events(30)
{
	int screen_width = 1024;
	int screen_height = 768;

	std::string windName = "The 21st Floor";
	m_draw.createWindow(screen_width, screen_height, m_events.getEventQueue(), ALLEGRO_RESIZABLE).setWindowTitle(windName).setWindowIcon("nicestboy.png");

	m_states.changeState(std::unique_ptr<axe::AbstractState>(new GameState(m_states, m_input, m_events, m_draw)));

	al_hide_mouse_cursor(m_draw.getWindow().getAllegroDisplay());
}

void Game::run()
{
	m_events.startTimer();
	while (m_states.running())
	{
		if (m_events.handleEvents())
		{
			m_draw.handleEvents(m_events.getEvent());

			m_input.getInput(m_events.getEvent());

			m_states.handleEvents();

			if (m_events.eventIs(ALLEGRO_EVENT_DISPLAY_CLOSE))
			{
				m_states.quit();
			}
			else if (m_events.eventIs(ALLEGRO_EVENT_TIMER))
			{
				m_states.update();
			}

			if (m_input.isKeyPressed(ALLEGRO_KEY_ESCAPE))
			{
				m_states.quit();
			}
			else if (m_input.isKeyPressed(ALLEGRO_KEY_SPACE))
			{
				m_draw.getWindow().setFullscreen(!m_draw.getWindow().getFullscreen());
				al_hide_mouse_cursor(m_draw.getWindow().getAllegroDisplay());
			}
		}

		if (m_events.eventQueueEmpty())
		{
			m_states.draw();

			axe::flipAndClear(al_map_rgb(0, 0, 0));
		}
	}
}

Game::~Game()
{

}