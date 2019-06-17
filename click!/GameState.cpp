#include <SFML/Graphics.hpp>
#include "GameState.h"

//tmp
#include <iostream>

GameState::GameState(StateManager * stateManager)
{
	m_pStateManager = stateManager;
	m_pApple = new Apple();
	m_pResourceManager = new ResourceManager();
	sf::Vector2u windowSize(1200, 800);

	const sf::Texture *backgroundTexture = m_pResourceManager->getTexture("wood");
	background.setTexture(*backgroundTexture);
	background.setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));

	makeAppleTree(windowSize);
	makeCookieAmount(windowSize);
	makeImprovements(windowSize);
}

void GameState::Update(UpdateContext updateContext)
{/*
	updateContext.m_pWindow->draw(background);*/
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
	hoverImpro(updateContext);
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

void GameState::makeImprovements(sf::Vector2u windowSize)
{
	sf::Sprite improTextureSprite;
	const sf::Texture *improTexture = m_pResourceManager->getTexture("first");
	improTextureSprite.setTexture(*improTexture);
	improTextureSprite.setPosition((windowSize.x - improTexture->getSize().x-10), (windowSize.y - 5*improTexture->getSize().y-10));
	this-> first = improTextureSprite;

	improTexture = m_pResourceManager->getTexture("second");
	improTextureSprite.setTexture(*improTexture);
	improTextureSprite.setPosition((windowSize.x - improTexture->getSize().x-10), (windowSize.y - 4*improTexture->getSize().y-5));
	this->second = improTextureSprite;

	improTexture = m_pResourceManager->getTexture("third");
	improTextureSprite.setTexture(*improTexture);
	improTextureSprite.setPosition((windowSize.x - improTexture->getSize().x-10), (windowSize.y - 3*improTexture->getSize().y));
	this->third = improTextureSprite;
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

void GameState::hoverImpro(UpdateContext updateContext)
{

	sf::Vector2u windowSize(1200, 800);
	sf::Vector2f textureSize(311,109); // i do not like this
	if (isSpriteHover(this->first, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
		this->first.setTextureRect(sf::IntRect(0, 0, textureSize.x - 8, textureSize.y - 8));
		this->first.setPosition((windowSize.x - textureSize.x - 10)+8, (windowSize.y - 5 * textureSize.y-10)+8);
	}
	else if (isSpriteHover(this->second, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
		this->second.setColor(sf::Color(255, 255, 128, 160));
		this->second.setTextureRect(sf::IntRect(0, 0, textureSize.x - 8, textureSize.y - 8));
		this->second.setPosition((windowSize.x - textureSize.x - 10) + 8, (windowSize.y - 4 * textureSize.y-5) + 8);
	}
	else if (isSpriteHover(this->third, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
		this->third.setColor(sf::Color(255, 255, 128, 160));
		this->third.setTextureRect(sf::IntRect(0, 0, textureSize.x - 8, textureSize.y - 8));
		this->third.setPosition((windowSize.x - textureSize.x - 10) + 8, (windowSize.y - 3 * textureSize.y) + 8);
	}
	else
	{
		this->first.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
		this->second.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
		this->third.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
		this->first.setPosition((windowSize.x - textureSize.x - 10), (windowSize.y - 5 * textureSize.y)-10);
		this->second.setColor(sf::Color(255, 255, 255, 255));
		this->second.setPosition((windowSize.x - textureSize.x - 10), (windowSize.y - 4 * textureSize.y)-5);
		this->third.setColor(sf::Color(255, 255, 255, 255));
		this->third.setPosition((windowSize.x - textureSize.x - 10), (windowSize.y - 3 * textureSize.y));
	}

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
	window->draw(background);
	drawAppleTree(window);
	drawCookieAmount(windowSize, window, this->m_pApple->getAppleCount());
	window->draw(first);
	window->draw(second);
	window->draw(third);
	window->display();
}

bool GameState::isSpriteHover(sf::Sprite rect, sf::Vector2i mouse) {
	if (rect.getGlobalBounds().contains(mouse.x, mouse.y)) {
		//std::cout << "Button Hover" << std::endl;
		return true;
	}

	return false;
}