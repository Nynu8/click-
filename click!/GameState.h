#pragma once
#include <vector>
#include "StateManager.h"
#include "Apple.h"

class GameState : public State
{
public:
	GameState(StateManager* stateManager): m_pStateManager(stateManager), m_pApple(new Apple()){};
	void Update(UpdateContext updateContext) override;

private:
	StateManager* m_pStateManager;
	Apple* m_pApple;
	std::vector<Upgrade> m_upgrades;
};
