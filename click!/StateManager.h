#pragma once
#include "State.h"
#include "UpdateContext.h"

class StateManager
{
public:
	template<class T>
	void TransitionTo()
	{
		state = new T(this);
	}

	void Update(UpdateContext updateContext)
	{
		state->Update(updateContext);
	}
private:
	State* state;
};
