#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�v���C���[
class CObjPlayer :public CObj
{
public:
	CObjPlayer(float x, float y);//�R���X�g���N�^
	~CObjPlayer() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;	//X�����ړ��p
	float m_y;	//Y�����ړ��p
	int m_r;	//����
	int m_ani_time;//�����A�j���[�V�����p�^�C��
	bool m_keydown;//�ړ��L�[��������Ă��邩
};