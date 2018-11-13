#pragma once
#include <map>
#include <SDL_image.h>

class TextureManager
{
public:
	~TextureManager() {}

	//static 클래스 내에서의 전역변수 개념
	//같은 클래스 내 모든 객체가 공용으로 사용할 수 있음
	//전역변수 처럼 하나의 객체에서 값을 변경하면 같이 사용하는 다른 객체에도 영향을 미침에 주의하여야 함
	//아래 Instance 함수에서 생성자를 한번만 호출되게 해줌으로서 싱글턴패턴을 따름
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager() {}
	std::map<std::string, SDL_Texture* > m_textureMap;
	static TextureManager *s_pInstance;
};

//typedef로 TextureManager 선언을 TheTextureManager 선언으로 이름을 재정의한다.
typedef TextureManager TheTextureManager;