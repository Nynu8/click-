#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "UpgradeType.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include "json.h"

using json = nlohmann::json;

//tmp
#include <iostream>

GameState::GameState(StateManager* _stateManager)
{
	m_pStateManager = _stateManager;
	m_pApple = new Apple();
	m_pResourceManager = new ResourceManager();
	
	sf::Vector2u windowSize(width, height);

	const sf::Texture *backgroundTexture = m_pResourceManager->GetTexture("wood");
	background.setTexture(*backgroundTexture);
	background.setTextureRect(sf::IntRect(0, 0, windowSize.x, windowSize.y));

	makeLogo(windowSize);
	makeAppleTree(windowSize);
	makeCookieAmount(windowSize);
	makeUpgrades(windowSize);
	makeInstruction(windowSize);
	makeTextUpgrades(windowSize, upgrade1Text);
	makeTextUpgrades(windowSize, upgrade2Text);
	makeTextUpgrades(windowSize, upgrade3Text);
	makeUpgradesName(upgrade1Name);
	makeUpgradesName(upgrade2Name);
	makeUpgradesName(upgrade3Name);
	setUpgradesName();
	makeUpgradesName(upgrade1Cost);
	makeUpgradesName(upgrade2Cost);
	makeUpgradesName(upgrade3Cost);

	upgradePosition1 = upgrade1.getPosition();
	upgradePosition2 = upgrade2.getPosition();
	upgradePosition3 = upgrade3.getPosition();

	//set upgrades
	this->m_upgrades.push_back({ std::string("MOC"), 1, 15, UpgradeType::Click });
	this->m_upgrades.push_back({ std::string("SZYBKOSC"), 2, 100, UpgradeType::ApplesPerSecond });
	this->m_upgrades.push_back({ std::string("OGIEN"), 5, 1000, UpgradeType::ApplesPerSecond });
	//load save
	load();
}

void GameState::Update(UpdateContext updateContext)
{
	sf::Event event;
	while (updateContext.m_pWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			//tu bedziemy zapisywac stan gry
			save();
			updateContext.m_pWindow->close();
		}

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (isSpriteHover(this->appleTreeSprite, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
					this->m_pApple->AddApples(1 + this->m_pApple->GetApplesPerClick());
				}

				if (isSpriteHover(this->upgrade1, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
					if (this->m_upgrades.at(0).GetUpgradeCost() <= this->m_pApple->GetAppleCount()) {
						this->m_pApple->AddApples(this->m_upgrades.at(0).GetUpgradeCost()*-1);
						this->m_upgrades.at(0).AddUpgradeLevel();
						this->m_pApple->AddUpgrade(this->m_upgrades.at(0));
					}
				}

				if (isSpriteHover(this->upgrade2, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
					if (this->m_upgrades.at(1).GetUpgradeCost() <= this->m_pApple->GetAppleCount()) {
						this->m_pApple->AddApples(this->m_upgrades.at(1).GetUpgradeCost()*-1);
						this->m_upgrades.at(1).AddUpgradeLevel();
						this->m_pApple->AddUpgrade(this->m_upgrades.at(1));
					}
				}

				if (isSpriteHover(this->upgrade3, sf::Mouse::getPosition(*updateContext.m_pWindow))) {
					if (this->m_upgrades.at(2).GetUpgradeCost() <= this->m_pApple->GetAppleCount()) {
						this->m_pApple->AddApples(this->m_upgrades.at(2).GetUpgradeCost()*-1);
						this->m_upgrades.at(2).AddUpgradeLevel();
						this->m_pApple->AddUpgrade(this->m_upgrades.at(2));
					}
				}
			}
		}
	}

	timeElapsed += updateContext.m_deltaTime;
	applesToAdd += updateContext.m_deltaTime * m_pApple->GetApplesPerSecond();
	if (applesToAdd > 1) {
		int tmpApples = (int)applesToAdd;
		applesToAdd -= tmpApples;
		m_pApple->AddApples(tmpApples);
	}

	hoverAppleTree(updateContext);
	disableUpgrades(updateContext);
	drawAll(updateContext.m_pWindow);
}

void GameState::makeLogo(sf::Vector2u windowSize)
{
	sf::Sprite logoTextureSpirte;
	const sf::Texture *logoTexture = m_pResourceManager->GetTexture("logo");
	logoTextureSpirte.setTexture(*logoTexture);
	this->logo = logoTextureSpirte;
	logo.setColor(sf::Color(255, 255, 255, 160));
}

void GameState::makeAppleTree(sf::Vector2u windowSize)
{
	sf::Sprite appleTextureSprite;
	const sf::Texture *appleTextureTree = m_pResourceManager->GetTexture("appleTree");
	appleTextureSprite.setTexture(*appleTextureTree);
	appleTextureSprite.setPosition((windowSize.x - appleTextureTree->getSize().x) / 2, (windowSize.y - appleTextureTree->getSize().y) / 2);
	this->appleTreeSprite = appleTextureSprite;
}

void GameState::makeCookieAmount(sf::Vector2u)
{
	const sf::Font *font = m_pResourceManager->GetFont("HandVetica");
	textPoints.setFont(*font);
	textPoints.setCharacterSize(60);
	textPoints.setFillColor(sf::Color::White);
	textPoints.setOutlineColor(sf::Color(226, 91, 48, 160));
	textPoints.setOutlineThickness(5);
	textPoints.setStyle(sf::Text::Bold);
}

void GameState::makeUpgrades(sf::Vector2u windowSize)
{
	sf::Sprite upgradeTextureSprite;
	const sf::Texture *upgradeTexture = m_pResourceManager->GetTexture("upgrade1");
	upgradeTextureSprite.setTexture(*upgradeTexture);
	upgradeTextureSprite.setPosition((windowSize.x - upgradeTexture->getSize().x-10), (windowSize.y - 5.5* upgradeTexture->getSize().y-10));
	this-> upgrade1 = upgradeTextureSprite;

	upgradeTexture = m_pResourceManager->GetTexture("upgrade2");
	upgradeTextureSprite.setTexture(*upgradeTexture);
	upgradeTextureSprite.setPosition((windowSize.x - upgradeTexture->getSize().x-10), (windowSize.y - 4* upgradeTexture->getSize().y-5));
	this->upgrade2 = upgradeTextureSprite;

	upgradeTexture = m_pResourceManager->GetTexture("upgrade3");
	upgradeTextureSprite.setTexture(*upgradeTexture);
	upgradeTextureSprite.setPosition((windowSize.x - upgradeTexture->getSize().x-10), (windowSize.y - 2.5* upgradeTexture->getSize().y));
	this->upgrade3 = upgradeTextureSprite;
}

void GameState::makeInstruction(sf::Vector2u windowSize)
{
	const sf::Font *font = m_pResourceManager->GetFont("ubuntu");
	instruction.setFont(*font);
	instruction.setCharacterSize(30);
	instruction.setStyle(sf::Text::Bold);

	instruction.setString("Klikaj na drzewo aby zerwac z niego jablka. \nZa zerwane jablka kupuj ulepszenia");
	instruction.setPosition(10, windowSize.y-120);
	instruction.setFillColor(sf::Color(255, 255, 255, 160));
}

void GameState::makeTextUpgrades(sf::Vector2u windowSize, sf::Text& upgrade)
{
	const sf::Font *font = m_pResourceManager->GetFont("HandVetica");
	upgrade.setFont(*font);
	upgrade.setCharacterSize(50);
	upgrade.setStyle(sf::Text::Bold);
	upgrade.setFillColor(sf::Color(255, 255, 255, 255));
	upgrade.setOutlineColor(sf::Color(226, 91, 48, 160));
	upgrade.setOutlineThickness(5);
}

void GameState::makeUpgradesName(sf::Text& upgradeName)//and cost
{
	const sf::Font *font = m_pResourceManager->GetFont("ubuntu");
	upgradeName.setFont(*font);
	upgradeName.setCharacterSize(30);
	upgradeName.setStyle(sf::Text::Bold);
	upgradeName.setFillColor(sf::Color(255, 255, 255, 255));
	upgradeName.setOutlineColor(sf::Color::Black);
	upgradeName.setOutlineThickness(1);
}



void GameState::setUpgradesName()
{
	upgrade1Name.setString("MOC");
	upgrade2Name.setString("SZYBKOSC");
	upgrade3Name.setString("OGIEN");

	upgrade1Name.setPosition(upgrade1.getPosition().x, upgrade1.getPosition().y - 45);
	upgrade2Name.setPosition(upgrade2.getPosition().x, upgrade2.getPosition().y - 45);
	upgrade3Name.setPosition(upgrade3.getPosition().x, upgrade3.getPosition().y - 45);
}

void GameState::drawCookieAmount(sf::RenderWindow* window, uint64_t points)
{
	textPoints.setString(std::to_string(points));
	unsigned int charactersSize = textPoints.getLocalBounds().width;
	textPoints.setPosition((window->getSize().x - charactersSize) / 2, window->getSize().y / 10);

	window->draw(textPoints);
}

void GameState::drawUpgradesAmount(sf::RenderWindow *window)
{
	upgrade1Text.setString(std::to_string(this->m_upgrades.at(0).GetUpgradeLevel()));
	upgrade2Text.setString(std::to_string(this->m_upgrades.at(1).GetUpgradeLevel()));
	upgrade3Text.setString(std::to_string(this->m_upgrades.at(2).GetUpgradeLevel()));

	unsigned int charactersSize1 = upgrade1Text.getLocalBounds().width;
	unsigned int charactersSize2 = upgrade2Text.getLocalBounds().width;
	unsigned int charactersSize3 = upgrade3Text.getLocalBounds().width;

	unsigned int charactersSize = textPoints.getLocalBounds().width;
	//+250 - characterSize* amount 
	upgrade1Text.setPosition(upgrade1.getPosition().x + 250 - charactersSize1, upgrade1.getPosition().y + 10);
	upgrade2Text.setPosition(upgrade2.getPosition().x + 250 - charactersSize2, upgrade2.getPosition().y + 10);
	upgrade3Text.setPosition(upgrade3.getPosition().x + 250 - charactersSize3, upgrade3.getPosition().y + 10);
	window->draw(upgrade1Text);
	window->draw(upgrade2Text);
	window->draw(upgrade3Text);
}

void GameState::drawUpgradesCost(sf::RenderWindow *window)
{
	upgrade1Cost.setString(std::string("Koszt " + std::to_string(this->m_upgrades.at(0).GetUpgradeCost())));
	upgrade2Cost.setString(std::string("Koszt " + std::to_string(this->m_upgrades.at(1).GetUpgradeCost())));
	upgrade3Cost.setString(std::string("Koszt " + std::to_string(this->m_upgrades.at(2).GetUpgradeCost())));

	unsigned int charactersSize1 = upgrade1Cost.getLocalBounds().width;
	unsigned int charactersSize2 = upgrade2Cost.getLocalBounds().width;
	unsigned int charactersSize3 = upgrade3Cost.getLocalBounds().width;
	//+250 - characterSize* amount 
	upgrade1Cost.setPosition(upgrade1.getPosition().x + 250 - charactersSize1, upgrade1.getPosition().y + 60);
	upgrade2Cost.setPosition(upgrade2.getPosition().x + 250 - charactersSize2, upgrade2.getPosition().y + 60);
	upgrade3Cost.setPosition(upgrade3.getPosition().x + 250 - charactersSize3, upgrade3.getPosition().y + 60);
	window->draw(upgrade1Cost);
	window->draw(upgrade2Cost);
	window->draw(upgrade3Cost);
}

void GameState::drawAll(sf::RenderWindow* window)
{
	window->clear();
	window->draw(background);
	window->draw(logo);
	window->draw(appleTreeSprite);
	drawCookieAmount(window, this->m_pApple->GetAppleCount());
	window->draw(upgrade1);
	window->draw(upgrade2);
	window->draw(upgrade3);
	if(this->m_pApple->GetAppleCount() < 5) 
		window->draw(instruction);
	drawUpgradesAmount(window);
	window->draw(upgrade1Name);
	window->draw(upgrade2Name);
	window->draw(upgrade3Name);
	drawUpgradesCost(window);
	window->display();
}

bool GameState::isSpriteHover(sf::Sprite rect, sf::Vector2i mouse) {
	if (rect.getGlobalBounds().contains(mouse.x, mouse.y)) {
		return true;
	}

	return false;
}

void GameState::hoverAppleTree(UpdateContext updateContext)
{
	if (isSpriteHover(this->appleTreeSprite, sf::Mouse::getPosition(*updateContext.m_pWindow)))
		this->appleTreeSprite.setColor(sf::Color(255, 255, 255, 255));
	else
		this->appleTreeSprite.setColor(sf::Color(255, 230, 255, 255));
}

void GameState::hoverUpgrade(UpdateContext updateContext, sf::Sprite &upgrade)
{
	sf::Vector2i mouse = sf::Mouse::getPosition(*updateContext.m_pWindow);

	(isSpriteHover(upgrade, mouse)) ? upgrade.setColor(sf::Color(255, 255, 255, 255)) : upgrade.setColor(sf::Color(250, 230, 255, 255));
}

void GameState::onclickUpgrade(UpdateContext updateContext, sf::Sprite &upgrade, sf::Vector2f upgradePosition)
{	
	sf::Vector2i mouse = sf::Mouse::getPosition(*updateContext.m_pWindow);

	(isSpriteHover(upgrade, mouse) && (sf::Mouse::isButtonPressed(sf::Mouse::Left))) ? activeUpgrade(upgrade, upgradePosition) : unactiveUpgrade(upgrade, upgradePosition);
}

void GameState::activeUpgrade(sf::Sprite &upgrade, sf::Vector2f texturePosition)
{
	sf::Vector2u textureSize = (upgrade.getTexture())->getSize();
	upgrade.setTextureRect(sf::IntRect(0, 0, textureSize.x - 6, textureSize.y - 6));
	upgrade.setPosition(texturePosition.x + 6, texturePosition.y + 6);
}

void GameState::unactiveUpgrade(sf::Sprite &upgrade, sf::Vector2f texturePosition)
{
	sf::Vector2u textureSize = (upgrade.getTexture())->getSize();
	upgrade.setTextureRect(sf::IntRect(0, 0, textureSize.x, textureSize.y));
	upgrade.setPosition(texturePosition.x - 6, texturePosition.y - 6);
}

void GameState::disableUpgrade(UpdateContext updateContext, sf::Sprite &upgrade, sf::Text& textUpgrade, sf::Vector2f upgradePosition, bool disable)
{

	if (disable) {
		upgrade.setColor(sf::Color(40, 40, 40));
		textUpgrade.setOutlineThickness(0);
	}
	else {
		onclickUpgrade(updateContext, upgrade, upgradePosition);
		hoverUpgrade(updateContext, upgrade);
	}
}

void GameState::disableUpgrades(UpdateContext updateContext)
{
	disableUpgrade(updateContext, upgrade1, upgrade1Text, upgradePosition1, (this->m_pApple->GetAppleCount() < this->m_upgrades.at(0).GetUpgradeCost()));
	disableUpgrade(updateContext, upgrade2, upgrade2Text, upgradePosition2, (this->m_pApple->GetAppleCount() < this->m_upgrades.at(1).GetUpgradeCost()));
	disableUpgrade(updateContext, upgrade3, upgrade3Text, upgradePosition3, (this->m_pApple->GetAppleCount() < this->m_upgrades.at(2).GetUpgradeCost()));
}

void GameState::save()
{
	json data;
	for (std::vector<Upgrade>::iterator it = this->m_upgrades.begin(); it != this->m_upgrades.end(); ++it) {
		json upgrade={ it->GetName(), it->GetUpgradeLevel() };
		data += upgrade;
	}

	data += this->m_pApple->GetAppleCount();
	data += this->timeElapsed;
	std::ofstream file("data.json");
	file << data;
}

void GameState::load()
{
	std::ifstream file("data.json");
	if (file.good()&&!file.eof()) {
		json data;
		file >> data;
		std::cout << data[1][1];
		this->m_upgrades.at(0).SetUpgradeLevel(data[0][1]);
		this->m_pApple->AddUpgrade(this->m_upgrades.at(0));

		this->m_upgrades.at(1).SetUpgradeLevel(data[1][1]);
		this->m_pApple->AddUpgrade(this->m_upgrades.at(1));
		
		this->m_upgrades.at(2).SetUpgradeLevel(data[2][1]);
		this->m_pApple->AddUpgrade(this->m_upgrades.at(2));
		
		this->m_pApple->SetAppleCount(data[3]);
		this->timeElapsed = data[4];
	}
}

std::string GameState::makeTimeString(double time)
{
	int hours = time / 3600;
	int minutes = (time - hours*3600) / 60;
	int seconds = (int)time % 60;

	std::stringstream ss;
	ss << std::setfill('0') << std::setw(2) << hours << ":";
	ss << std::setfill('0') << std::setw(2) << minutes << ":";
	ss << std::setfill('0') << std::setw(2) << seconds;
	return ss.str();
}
