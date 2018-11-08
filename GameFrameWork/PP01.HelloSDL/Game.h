#include "SDL.h"
using namespace std;

class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int pos,
		int width, int height, bool fullscreen);

	void render();
	void update() {};
	void handleEvents();
	void clean();
	bool running() {
		return m_bRunning;
	}
private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};
