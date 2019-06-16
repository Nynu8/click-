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
	void drawAppleTree(sf::Vector2u, sf::RenderWindow* );
	void drawCookieAmount(sf::Vector2u, sf::RenderWindow* , unsigned long long);

	void drawAll(sf::RenderWindow* window);
	bool isSpriteHover(sf::Sprite rect, sf::Vector2i mouse);

private:
	StateManager* m_pStateManager;
	Apple* m_pApple;
	std::vector<Upgrade> m_upgrades;
	ResourceManager* m_pResourceManager;
};
