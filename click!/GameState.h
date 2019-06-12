#pragma once
#include "StateManager.h"

class GameState : public State
{
public:
	GameState(StateManager* stateManager): m_pStateManager(stateManager){};
	void Update(UpdateContext updateContext) override;

private:
	StateManager* m_pStateManager;
};
