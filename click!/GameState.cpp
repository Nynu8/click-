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

	makeLogo(windowSize);
	makeAppleTree(windowSize);
	makeCookieAmount(windowSize);
	makeUpgrades(windowSize);

	upgradePosition1 = first.getPosition();
	upgradePosition2 = second.getPosition();
	upgradePosition3 = third.getPosition();
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
			onclickUpgrade(updateContext, upgradePosition1, upgradePosition2, upgradePosition3);
			if (event.mouseButton.button == sf::Mouse::Left)
			{

				if (isSpriteHover(this->appleTreeSprite, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
					this->m_pApple->addApples(1);
				}
			}
		}
	}
	//std::cout << updateContext.m_DeltaTime << std::endl;
	onclickUpgrade(updateContext, upgradePosition1, upgradePosition2, upgradePosition3);
	hoverAppleTree(updateContext);
	hoverUpgrade(updateContext);
	drawAll(updateContext.m_pWindow);
}

void GameState::makeLogo(sf::Vector2u windowSize)
{
	sf::Sprite logoTextureSpirte;
	const sf::Texture *logoTexture = m_pResourceManager->getTexture("logo");
	logoTextureSpirte.setTexture(*logoTexture);
	this->logo = logoTextureSpirte;

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
	const sf::Font *font = m_pResourceManager->getFont("Rainbow");
	textPoints.setFont(*font);
	textPoints.setCharacterSize(60);
	textPoints.setFillColor(sf::Color::White);
	textPoints.setStyle(sf::Text::Bold);
}

void GameState::makeUpgrades(sf::Vector2u windowSize)
{
	sf::Sprite upgradeTextureSprite;
	const sf::Texture *upgradeTexture = m_pResourceManager->getTexture("first");
	upgradeTextureSprite.setTexture(*upgradeTexture);
	upgradeTextureSprite.setPosition((windowSize.x - upgradeTexture->getSize().x-10), (windowSize.y - 5.5* upgradeTexture->getSize().y-10));
	this-> first = upgradeTextureSprite;

	upgradeTexture = m_pResourceManager->getTexture("second");
	upgradeTextureSprite.setTexture(*upgradeTexture);
	upgradeTextureSprite.setPosition((windowSize.x - upgradeTexture->getSize().x-10), (windowSize.y - 4* upgradeTexture->getSize().y-5));
	this->second = upgradeTextureSprite;

	upgradeTexture = m_pResourceManager->getTexture("third");
	upgradeTextureSprite.setTexture(*upgradeTexture);
	upgradeTextureSprite.setPosition((windowSize.x - upgradeTexture->getSize().x-10), (windowSize.y - 2.5* upgradeTexture->getSize().y));
	this->third = upgradeTextureSprite;
}

void GameState::drawAppleTree(sf::RenderWindow* window)
{
	window->draw(this->appleTreeSprite);
}

void GameState::hoverAppleTree(UpdateContext updateContext)
{
	if (isSpriteHover(this->appleTreeSprite, sf::Mouse::getPosition(*updateContext.m_pWindow)))
		this->appleTreeSprite.setColor(sf::Color(255, 255, 255, 255));
	else
		this->appleTreeSprite.setColor(sf::Color(255, 230, 255, 255));
}

void GameState::hoverUpgrade(UpdateContext updateContext)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(*updateContext.m_pWindow);

	(isSpriteHover(this->first, mouse)) ? this->first.setColor(sf::Color(255, 255, 255, 255)) : this->first.setColor(sf::Color(255, 230, 255, 255));
	(isSpriteHover(this->second, mouse)) ? this->second.setColor(sf::Color(255, 255, 255, 255)) : this->second.setColor(sf::Color(255, 230, 255, 255));
	isSpriteHover(this->third, mouse) ? this->third.setColor(sf::Color(255, 255, 255, 255)) : this->third.setColor(sf::Color(255, 230, 255, 255));
}

void GameState::onclickUpgrade(UpdateContext updateContext, sf::Vector2f upgradePosition1, sf::Vector2f upgradePosition2, sf::Vector2f upgradePosition3)
{	
	sf::Vector2i mouse = sf::Mouse::getPosition(*updateContext.m_pWindow);

	(isSpriteHover(this->first, mouse) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) ? activeUpgrade(this->first, upgradePosition1) : unactiveUpgrade(this->first, upgradePosition1);
	(isSpriteHover(this->second, mouse) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) ? activeUpgrade(this->second,upgradePosition2) : unactiveUpgrade(this->second, upgradePosition2);
	(isSpriteHover(this->third, mouse) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) ? activeUpgrade(this->third, upgradePosition3) : unactiveUpgrade(this->third, upgradePosition3);
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
	window->draw(logo);
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

void GameState::activeUpgrade(sf::Sprite &upgrade, sf::Vector2f texturePosition)
{
	sf::Vector2u windowSize(1200, 800);
	sf::Vector2u textureSize = (upgrade.getTexture())->getSize();
	upgrade.setTextureRect(sf::IntRect(0, 0, textureSize.x - 8, textureSize.y - 8));
	upgrade.setPosition(texturePosition.x + 8, texturePosition.y + 8);
}

void GameState::unactiveUpgrade(sf::Sprite &upgrade, sf::Vector2f texturePosition)
{
	sf::Vector2u windowSize(1200, 800);
	sf::Vector2u textureSize = (upgrade.getTexture())->getSize();
	upgrade.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
	upgrade.setPosition(texturePosition.x - 8, texturePosition.y - 8);
}
