#include <SFML/Graphics.hpp>
#include "GameState.h"

//tmp
#include <iostream>

GameState::GameState(StateManager * stateManager)
{
	m_pStateManager = stateManager;
	m_pApple = new Apple();
	m_pResourceManager = new ResourceManager();
}

void GameState::Update(UpdateContext updateContext)
{
	updateContext.m_pWindow->create(sf::VideoMode(1000, 800), "Click!");
	sf::RenderWindow* Window = updateContext.m_pWindow;
	sf::Vector2u sizeWindow = Window->getSize();
	sf::Event event;
	while (updateContext.m_pWindow->isOpen()) 
	{
		while (updateContext.m_pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				updateContext.m_pWindow->close();
		}
		//std::cout << updateContext.m_DeltaTime << std::endl;
		drawAll(Window);
	}
}

void GameState::drawAppleTree(sf::Vector2u size, sf::RenderWindow* window)
{
	sf::Sprite appleTsprite;
	sf::Texture appleTtree = m_pResourceManager->getTexture("appleTree");
	appleTsprite.setTexture(appleTtree);
	appleTsprite.setPosition((size.x - appleTtree.getSize().x) / 2, (size.y - appleTtree.getSize().x) / 2);
	window->draw(appleTsprite);

}

void GameState::drawCookieAmount(sf::Vector2u size, sf::RenderWindow* window, unsigned long long points)
{
	sf::Text textPoints;
	sf::Font font = m_pResourceManager->getFont("HandVetica");
	textPoints.setFont(font); 
	textPoints.setCharacterSize(60);
	textPoints.setFillColor(sf::Color::White);
	textPoints.setStyle(sf::Text::Bold);

	textPoints.setString(std::to_string(points));
	
	unsigned int charactersSize = textPoints.getLocalBounds().width;
	textPoints.setPosition((size.x - charactersSize) / 2, size.y / 10);

	window->draw(textPoints);
}

void GameState::drawAll(sf::RenderWindow * window)
{
	sf::Vector2u windowSize = window->getSize();
	window->clear();
	drawAppleTree(windowSize, window);
	drawCookieAmount(windowSize, window, 121221);
	window->display();
}

bool GameState::isSpriteHover(sf::Sprite rect, sf::Vector2i mouse) {
	if (rect.getGlobalBounds().contains(mouse.x, mouse.y)) {
		//std::cout << "Button Hover" << std::endl;
		return true;
	}
	return false;
}