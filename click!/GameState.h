#pragma once
#include <vector>
#include "StateManager.h"
#include "Apple.h"
#include "ResourceManager.h"

class GameState : public State
{
public:
	//GameState(StateManager* stateManager): m_pStateManager(stateManager), m_pApple(new Apple()){};
	GameState(StateManager* stateManager);
	void Update(UpdateContext updateContext) override;

	void makeLogo(sf::Vector2u);
	void makeAppleTree(sf::Vector2u);
	void makeCookieAmount(sf::Vector2u);
	void makeUpgrades(sf::Vector2u);

	void drawAppleTree(sf::RenderWindow*);
	void drawCookieAmount(sf::Vector2u, sf::RenderWindow* , unsigned long long);
	void drawAll(sf::RenderWindow* window);

	void hoverAppleTree(UpdateContext updateContext);
	void hoverUpgrade(UpdateContext updateContext);
	void onclickUpgrade(UpdateContext updateContext, sf::Vector2f, sf::Vector2f, sf::Vector2f);
	bool isSpriteHover(sf::Sprite rect, sf::Vector2i mouse);
	void activeUpgrade(sf::Sprite&, sf::Vector2f);
	void unactiveUpgrade(sf::Sprite&, sf::Vector2f);

private:
	StateManager* m_pStateManager;
	Apple* m_pApple;
	ResourceManager* m_pResourceManager;
	std::vector<Upgrade> m_upgrades;

	sf::Vector2f upgradePosition1;
	sf::Vector2f upgradePosition2;
	sf::Vector2f upgradePosition3;

	//std::map<std::string, sf::Sprite*> m_sprite;
	sf::Sprite logo; 
	sf::Sprite appleTreeSprite;
	sf::Sprite background;
	//Upgrades
	sf::Sprite first;
	sf::Sprite second;
	sf::Sprite third;
	//Upgrades
	sf::Text textPoints;
};
