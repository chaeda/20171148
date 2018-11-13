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
	//데이터를 여러 개 저장해 두기 위한 컨테이너 STL . 벡터 클래스 사용
	//참고링크 https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60208709263&proxyReferer=https%3A%2F%2Fwww.google.com%2F
	std::vector<GameObject*> m_gameObjects;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer; //플레이어 렌더러
	SDL_Renderer* m_bRenderer; //백그라운드 렌더러

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_monster1;
	GameObject* m_monster2;

	bool m_bRunning;
	int m_currentFrame;
	int m_currentFrame2;
};