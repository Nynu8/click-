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

	void makeAppleTree(sf::Vector2u);
	void makeCookieAmount(sf::Vector2u);
	void makeImprovements(sf::Vector2u);

	void drawAppleTree(sf::RenderWindow*);
	void drawCookieAmount(sf::Vector2u, sf::RenderWindow* , unsigned long long);
	void drawAll(sf::RenderWindow* window);

	void hoverAppleTree(UpdateContext updateContext);
	void hoverImpro(UpdateContext updateContext);
	bool isSpriteHover(sf::Sprite rect, sf::Vector2i mouse);

private:
	StateManager* m_pStateManager;
	Apple* m_pApple;
	ResourceManager* m_pResourceManager;
	std::vector<Upgrade> m_upgrades;

	//std::map<std::string, sf::Sprite*> m_sprite;
	sf::Sprite appleTreeSprite;
	sf::Sprite background;
	//improvements
	sf::Sprite first;
	sf::Sprite second;
	sf::Sprite third;
	//improvements
	sf::Text textPoints;
};
