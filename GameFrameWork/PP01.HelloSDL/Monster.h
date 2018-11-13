#pragma once
#include "GameObject.h"

class Monster : public GameObject
{
public:
	Monster() {}
	~Monster() {}

	void update();
	void control(int m_x, int m_y, int currentFrame); 
private:
	bool goR = true;
};