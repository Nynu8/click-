#include <iostream>
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"
#include "UpdateContext.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 800), "Click!");
	window.setVerticalSyncEnabled(true);
	sf::Clock clock;
	
	StateManager stateManager;
	stateManager.TransitionTo<GameState>();
	UpdateContext kContext;
	kContext.m_pWindow = &window;

	while (window.isOpen())
	{
		kContext.m_DeltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
		stateManager.Update(kContext);
	}

	system("pause"); 
	return 0;
}