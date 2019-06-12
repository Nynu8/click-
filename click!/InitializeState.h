#pragma once
#include "StateManager.h"

class InitializeState : public State
{
public:
	InitializeState(StateManager* stateManager) : m_pStateManager(stateManager) {};
	void Update(UpdateContext updateContext) override;

private:
	StateManager* m_pStateManager;
};
