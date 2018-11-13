#include "Monster.h"

void Monster::update()
{
	if (this->m_textureID == "mob1")
		control(1, 0, int(((SDL_GetTicks() / 100) % 1)));
	else if (this->m_textureID == "mob2")
		control(2, 0, int(((SDL_GetTicks() / 20) % 1)));
}

void Monster::control(int m_x, int m_y, int currentFrame)
{
	//���� �պ��ڵ�
	if (this->m_x >= 0 && this->m_x < 100 && goR == true)
	{
		this->m_x += m_x;

		if (this->m_x == 100)
		{
			goR = false;
		}
	}
	else if (goR == false)
	{
		this->m_x -= m_x;

		if (this->m_x == 0)
		{
			goR = true;
		}
	}

	//������ �� ����
	m_currentFrame = currentFrame;
}