#include <SFML/Graphics.hpp>
#include "GameState.h"

//tmp
#include <iostream>

GameState::GameState(StateManager * stateManager)
{
	m_pStateManager = stateManager;
	m_pApple = new Apple();
	m_pResourceManager = new ResourceManager();
	sf::Vector2u windowSize(1000, 800);
	makeAppleTree(windowSize);
	makeCookieAmount(windowSize);
}

void GameState::Update(UpdateContext updateContext)
{
	sf::Event event;
	while (updateContext.m_pWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			updateContext.m_pWindow->close();

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (isSpriteHover(this->appleTreeSprite, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
					this->m_pApple->addApples(1);
				}
			}
		}
	}
	//std::cout << updateContext.m_DeltaTime << std::endl;
	hoverAppleTree(updateContext);
	drawAll(updateContext.m_pWindow);
}

void GameState::makeAppleTree(sf::Vector2u windowSize)
{
	sf::Sprite appleTextureSprite;
	const sf::Texture *appleTextureTree = m_pResourceManager->getTexture("appleTree");
	appleTextureSprite.setTexture(*appleTextureTree);
	appleTextureSprite.setPosition((windowSize.x - appleTextureTree->getSize().x) / 2, (windowSize.y - appleTextureTree->getSize().x) / 2);
	this->appleTreeSprite = appleTextureSprite;
}

void GameState::makeCookieAmount(sf::Vector2u)
{
	const sf::Font *font = m_pResourceManager->getFont("HandVetica");
	textPoints.setFont(*font);
	textPoints.setCharacterSize(60);
	textPoints.setFillColor(sf::Color::White);
	textPoints.setStyle(sf::Text::Bold);
}

void GameState::drawAppleTree(sf::RenderWindow* window)
{
	window->draw(this->appleTreeSprite);
}

void GameState::hoverAppleTree(UpdateContext updateContext)
{
	if (isSpriteHover(this->appleTreeSprite, sf::Mouse::getPosition(*updateContext.m_pWindow)))
		this->appleTreeSprite.setColor(sf::Color(255, 255, 128, 160));
	else
		this->appleTreeSprite.setColor(sf::Color(255, 255, 255, 255));
}

void GameState::drawCookieAmount(sf::Vector2u size, sf::RenderWindow* window, unsigned long long points)
{
	textPoints.setString(std::to_string(points));
	unsigned int charactersSize = textPoints.getLocalBounds().width;
	textPoints.setPosition((size.x - charactersSize) / 2, size.y / 10);

	window->draw(textPoints);
}

void GameState::drawAll(sf::RenderWindow* window)
{
	sf::Vector2u windowSize = window->getSize();
	window->clear();
	drawAppleTree(window);
	drawCookieAmount(windowSize, window, this->m_pApple->getAppleCount());
	window->display();
}

bool GameState::isSpriteHover(sf::Sprite rect, sf::Vector2i mouse) {
	if (rect.getGlobalBounds().contains(mouse.x, mouse.y)) {
		//std::cout << "Button Hover" << std::endl;
		return true;
	}

	return false;
}