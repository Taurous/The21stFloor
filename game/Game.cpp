#include "Game.h"

Game::Game() : m_events(30)
{
	int screen_width = 1024;
	int screen_height = 768;

	m_systems.input = std::move(std::make_unique<axe::InputHandler>());

	std::string windName = "axeLib v0.5.0 Test";
	m_draw.createWindow(screen_width, screen_height, windName);
	m_draw.getWindow().registerForEvents(m_events.getEventQueue());

	m_draw.fonts.setPathToResources("res/fonts/");
	m_draw.bitmaps.setPathToResources("res/textures/");
}

int Game::run()
{
	bool running = true;
	int result = 1;

	m_events.startTimer();
	while (running)
	{
		if (m_events.handleEvents())
		{
			m_systems.input->getInput(m_events.getEvent());

			if (m_events.eventIs(ALLEGRO_EVENT_DISPLAY_CLOSE))
			{
				result = 0;
				running = false;
			}
			else if (m_events.eventIs(ALLEGRO_EVENT_TIMER))
			{
				// tick
			}
		}

		if (m_events.eventQueueEmpty())
		{
			m_draw.flipAndClear(al_map_rgb(0, 0, 0));
		}
	}
	return result;
}

Game::~Game()
{

}