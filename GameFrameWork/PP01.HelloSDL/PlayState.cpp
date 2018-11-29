#include "PlayState.h"
#include "Player.h"
#include "Game.h"


const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = NULL;


void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TextureManager::Instance()->load(
		"assets/helicopter.png", "helicopter",
	TheGame::Instance()->getRenderer()))
	{
	 return false;
	}


	GameObject* player = new Player(new LoaderParams(100, 100, 128, 55, "helicopter"));
	m_gameObjects.push_back(player);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TextureManager::Instance()->clearFromtheTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}