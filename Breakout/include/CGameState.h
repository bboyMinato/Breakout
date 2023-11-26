#pragma once

class CGameState
{
public:
	CGameState() {}
	~CGameState() {}

	virtual void Init() = 0;
	virtual void Clean() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};