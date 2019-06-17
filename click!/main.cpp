#include <iostream>
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"
#include "UpdateContext.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Click!", sf::Style::Close);
	sf::Clock clock;
	
	StateManager stateManager;
	stateManager.TransitionTo<GameState>();
	UpdateContext kContext;
	kContext.m_pWindow = &window;

	bool shouldExit = false;
	while (!shouldExit)
	{	
		kContext.m_DeltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
		while (window.isOpen())
		{
			stateManager.Update(kContext);
		}
	}

	system("pause"); 
	return 0;
}