#include "GameState.h"

GameState::GameState(axe::StateManager &states, axe::InputHandler &input, axe::EventHandler &events, axe::DrawEngine &draw) : axe::AbstractState(states, input, events, draw)
{
	axe::log(axe::LOGGER_MESSAGE, "In Game State\n");
}

GameState::~GameState()
{
	axe::log(axe::LOGGER_MESSAGE, "Destroying Game State...");
}

void GameState::update()
{

}

void GameState::handleEvents()
{

}

void GameState::draw()
{
	al_draw_circle(m_input.getMouseX(), m_input.getMouseY(), 8, al_map_rgb(255, 0, 0), 2);
}

void GameState::pause()
{

}

void GameState::resume()
{

}