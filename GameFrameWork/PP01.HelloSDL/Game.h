#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include <iostream>

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
	SDL_Renderer* m_pRenderer; //플레이어 렌더러
	SDL_Renderer* m_bRenderer; //백그라운드 렌더러
							   //SDL_Texture* m_pTexture; // the new SDL_Texture variable
							   //SDL_Rect m_sourceRectangle; //원본 사각형
							   //SDL_Rect m_destinationRectangle; //대상 사각형
							   //TextureManager m_textureManager;	//텍스쳐 파일을 중앙관리하는 매니저
	bool m_bRunning;
	int m_currentFrame;
	int m_currentFrame2;
};