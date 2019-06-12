#pragma once
#include "State.h"
#include "UpdateContext.h"

class StateManager
{
public:
	template<class T>
	void TransitionTo()
	{
		m_pState = new T(this);
	}

	void Update(UpdateContext updateContext)
	{
		m_pState->Update(updateContext);
	}
private:
	State* m_pState;
};
