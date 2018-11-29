#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"
#include <iostream>


Game* Game::s_pInstance = 0;



bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;


		if (!TextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		m_pGameStateMachine = new GameStateMachine();
		m_pGameStateMachine->changeState(MenuState::Instance());
		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));



		SDL_SetRenderDrawColor(m_pRenderer, 255, 155, 156, 255);		//배경색
	}
	else
	{
		return false;
	}

	return true;
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(PlayState::Instance());
	}

}

void Game::render()
{

	SDL_RenderClear(m_pRenderer);

	m_pGameStateMachine->render();
	// 화면
	SDL_RenderPresent(m_pRenderer);

	//for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		//m_gameObjects[i]->draw();


}

void Game::update()
{
	//handleEvents();
	//TheInputHandler::Instance()->update();
	m_pGameStateMachine->update();
	for (vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
		m_gameObjects[i]->update();

}

void Game::clean()
{
	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


