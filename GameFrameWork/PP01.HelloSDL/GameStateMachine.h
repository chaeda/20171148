#pragma once
#include "GameState.h"
#include <iostream>

class GameStateMachine
{
public:
	std::vector<GameState*> m_gameStates;

	void changeState(GameState* pState);
	void popState();
	void pushState(GameState *pState);

	void update();
	void render();

private:
	GameState * m_currentState;
	GameState* m_prevState;
};