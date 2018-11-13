#pragma once
#include "Player.h"
#include "GameObject.h"

using namespace std;

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer; //�÷��̾� ������
	SDL_Renderer* m_bRenderer; //��׶��� ������

	GameObject m_go;
	Player m_player;

	bool m_bRunning;
	int m_currentFrame;
	int m_currentFrame2;
};