#pragma once
#include <stack>
#include <memory>

#include "CGameState.h"

class StateManager
{
public:
	StateManager();
	~StateManager();

	void Add(std::unique_ptr<CGameState> toAdd, bool replace = false);
	void PopCurrentState();
	void ProccessStateChange();
	std::unique_ptr<CGameState>& GetCurrent();

private:
	std::stack<std::unique_ptr<CGameState>> _states;
	std::unique_ptr<CGameState> _newState;
	
	bool _add;
	bool _replace;
	bool _remove;
};