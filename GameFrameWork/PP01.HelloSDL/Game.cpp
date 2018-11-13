#include "Game.h"

bool Game::init(const char*title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	//main.cpp���� m_bRunning ���� ���� �ݺ����� ������ ���� ����
	//Game.h ���� m_bRunning �� false ������ �ʱ�ȭ �Ǿ��ֱ� ������ 
	//init�� �� �� ������ ���ư��ٴ� ���� �����ֱ� ���� true�� �Ҵ�����
	m_bRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow("HOSEO BAR",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, SDL_WINDOW_SHOWN);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
		if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		////�䳢 �ִϸ��̼� �߰�
		//if (!TheTextureManager::Instance()->load("Assets/animate-Rabbit.png", "Rabbit", m_pRenderer))
		//{
		//	return false;
		//}
		////Ǯ���� �̹��� �߰�
		//if (!TheTextureManager::Instance()->load("Assets/grass.png", "grass", m_pRenderer))
		//{
		//	return false;
		//}

		m_go.load(100, 100, 128, 82, "animate");
		m_player.load(300, 300, 128, 82, "animate");
	}
	else
	{
		return 1;
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	//TheTextureManager::Instance()->draw("grass", 0, 0, 32, 32, m_pRenderer);
	//TheTextureManager::Instance()->drawFrame("Rabbit", 0, 0, 32, 32, 1, m_currentFrame, m_pRenderer);

	m_go.draw(m_pRenderer);
	m_player.draw(m_pRenderer);

	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_currentFrame2 = int(((SDL_GetTicks() / 50) % 6));

	m_go.update();
	m_player.update();
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);

	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}