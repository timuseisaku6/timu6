#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

class school_desk:public CObj
{
public:
	school_desk(float x,float y);
	~school_desk() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

private:
	float m_x;
	float m_y;
};

