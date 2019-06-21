#pragma once
#include <vector>
#include "StateManager.h"
#include "Apple.h"
#include "ResourceManager.h"

constexpr int height = 800;
constexpr int width = 1200;

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
	void makeInstruction(sf::Vector2u);
	void makeTextUpgrades(sf::Vector2u, sf::Text&);
	void makeUpgradesName(sf::Text&);
	void makeUpgradesCost(sf::Text&);

	void setUpgradesName();

	void drawCookieAmount(sf::RenderWindow* , unsigned long long);
	void drawUpgradesAmount(sf::RenderWindow*);
	void drawUpgradesCost(sf::RenderWindow*);
	void drawAll(sf::RenderWindow*);

	void hoverAppleTree(UpdateContext);
	void hoverUpgrade(UpdateContext, sf::Sprite &);
	void onclickUpgrade(UpdateContext, sf::Sprite &, sf::Vector2f);
	bool isSpriteHover(sf::Sprite, sf::Vector2i);
	void activeUpgrade(sf::Sprite&, sf::Vector2f);
	void unactiveUpgrade(sf::Sprite&, sf::Vector2f);
	void disableUpgrade(UpdateContext, sf::Sprite &, sf::Text&, sf::Vector2f);


private:
	StateManager* m_pStateManager;
	Apple* m_pApple;
	ResourceManager* m_pResourceManager;
	std::vector<Upgrade> m_upgrades;

	sf::Vector2f upgradePosition1;
	sf::Vector2f upgradePosition2;
	sf::Vector2f upgradePosition3;

	//std::map<std::string, sf::Sprite*> m_sprite; nienawidze map
	
	sf::Sprite logo; 
	sf::Sprite appleTreeSprite;
	sf::Sprite background;

	sf::Sprite upgrade1;
	sf::Sprite upgrade2;
	sf::Sprite upgrade3;
	
	sf::Text upgrade1Text;
	sf::Text upgrade2Text;
	sf::Text upgrade3Text;

	sf::Text upgrade1Name;
	sf::Text upgrade2Name;
	sf::Text upgrade3Name;

	sf::Text upgrade1Cost;
	sf::Text upgrade2Cost;
	sf::Text upgrade3Cost;

	sf::Text textPoints;
	sf::Text instruction;


	sf::Image icon;
};
