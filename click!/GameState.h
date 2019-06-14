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
	void drawCookieAmount(unsigned long long);

private:
	StateManager* m_pStateManager;
	Apple* m_pApple;
	std::vector<Upgrade> m_upgrades;
	ResourceManager* m_pResourceManager;
};
