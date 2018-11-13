#pragma once
#include "LoaderParams.h"

class GameObject
{
public:
	//���� ���� �Լ�
	//�߻� Ŭ������ ��
	//��ü ������ �Ұ���
	//����� ���Ҹ� �� �� �ְԲ� ���� ������ ��
	//��ӹ޾Ƽ� ���� ��ü���� �ǹ̰� �ִٴ� ���� �ٷ� �˷���
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};