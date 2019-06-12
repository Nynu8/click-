#pragma once
#include <SFML/Graphics.hpp>

#include "InitializeState.h"
#include "GameState.h"

void InitializeState::Update(UpdateContext updateContext)
{
	updateContext.m_pWindow->setFramerateLimit(60);
	updateContext.m_pWindow->setVerticalSyncEnabled(true);

	this->m_pStateManager->TransitionTo<GameState>();
}