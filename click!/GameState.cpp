#include <SFML/Graphics.hpp>

#include "GameState.h"

void GameState::Update(UpdateContext updateContext)
{
	sf::Event event;
	while (updateContext.m_pWindow->pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
			updateContext.m_pWindow->close();
	} 
}
