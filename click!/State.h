#pragma once
#include "StateManager.h"
#include "UpdateContext.h"

class State
{
public:
	virtual void Update(UpdateContext updateContext) = 0;
};
