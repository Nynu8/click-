#include <iostream>
#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "GameState.h"
#include "UpdateContext.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Click!", sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);

	sf::Image icon;
	icon.loadFromFile("./assets/icon.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Clock clock;
	StateManager stateManager;
	stateManager.TransitionTo<GameState>();
	UpdateContext kContext;
	kContext.m_pWindow = &window;

	while (window.isOpen())
	{
		kContext.m_deltaTime = clock.getElapsedTime().asSeconds();
		clock.restart();
		stateManager.Update(kContext);
	}

	system("pause"); 
	return 0;
}