#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class story :public CObj
{
public:
	story();
	~story();
	void Init();//�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();//�h���[
private:
	bool m_key_flag;//�L�[�t���O
	float m_rgb;	//RGB����p
};

