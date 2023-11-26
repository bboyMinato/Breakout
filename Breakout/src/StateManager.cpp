#include "../include/StateManager.h"

StateManager::StateManager() : _add(false), _replace(false), _remove(false)
{
}

StateManager::~StateManager()
{
}

void StateManager::Add(std::unique_ptr<CGameState> toAdd, bool replace)
{
	_add = true;
	_newState = std::move(toAdd);

	_replace = replace;
}

void StateManager::PopCurrentState()
{
	_remove = true;
}

void StateManager::ProccessStateChange()
{
	if (_remove && (!_states.empty()))
	{
		_states.pop();

		if (!_states.empty());
		{
			_states.top()->Resume();
		}

		_remove = false;
	}

	if (_add)
	{
		if (_replace && (!_states.empty()))
		{
			_states.pop();
		}

		if (!_states.empty())
		{
			_states.top()->Pause();
		}
	}

	_states.push(std::move(_newState));
	_add = false;
}

std::unique_ptr<CGameState>& StateManager::GetCurrent()
{
	return _states.top();
}
