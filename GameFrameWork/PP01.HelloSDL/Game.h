#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Monster.h"
#include "GameObject.h"
#include <vector>

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
	//�����͸� ���� �� ������ �α� ���� �����̳� STL . ���� Ŭ���� ���
	//����ũ https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60208709263&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	std::vector<GameObject*> m_gameObjects;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer; //�÷��̾� ������
	SDL_Renderer* m_bRenderer; //��׶��� ������

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_monster1;
	GameObject* m_monster2;

	bool m_bRunning;
	int m_currentFrame;
	int m_currentFrame2;
};