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

		//�ؽ��� ���
		if (!TheTextureManager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("Assets/simhyang.png", "mob1", m_pRenderer))
		{
			return false;
		}
		if (!TheTextureManager::Instance()->load("Assets/red.png", "mob2", m_pRenderer))
		{
			return false;
		}

		m_go = new GameObject();
		m_player = new Player();
		m_enemy = new Enemy();
		m_monster1 = new Monster();
		m_monster2 = new Monster();

		m_go->load(100, 100, 128, 82, "animate");
		m_player->load(300, 300, 128, 82, "animate");
		m_enemy->load(0, 0, 128, 82, "animate");
		m_monster1->load(0, 50, 64, 64, "mob1");
		m_monster2->load(0, 100, 64, 64, "mob2");



		//���� m_gameObjects �� ���� ���ʿ� �� ���ӿ�����Ʈ���� �־���
		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);
		m_gameObjects.push_back(m_monster1);
		m_gameObjects.push_back(m_monster2);
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

	//����STL�� �־��� ������Ʈ���� �׷��ش�. push_back ���� ������Ʈ���� Ž���ϸ� draw �Լ� ����
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}

	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	m_currentFrame2 = int(((SDL_GetTicks() / 50) % 6));

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
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