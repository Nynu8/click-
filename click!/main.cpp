#include <iostream>
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "InitializeState.h"
#include "UpdateContext.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1440, 900), "click!");
	sf::Clock clock;

	StateManager stateManager;
	stateManager.TransitionTo<InitializeState>();

	bool shouldExit = false;
	while (!shouldExit)
	{
		UpdateContext kContext;
		kContext.m_pWindow = &window;
		while (window.isOpen())
		{
			stateManager.Update(kContext);
			window.clear();
			window.display();
		}
	}

	system("pause"); 
	return 0;
}