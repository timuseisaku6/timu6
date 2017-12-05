#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�v���C���[
class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x, float y);//�R���X�g���N�^
	~CObjEnemy() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
	float GetX() { return m_x; }
	float GetY() { return m_y; }
	void SetX(float x);
	void SetY(float y);
private:
	float m_x;	//X�����ړ��p
	float m_y;	//Y�����ړ��p
	int m_r;	//����
	float ar;	//��l���̌���
	bool m_WalkFlag;//�����t���O
	int m_time;
	int m_ani_time;	//�����A�j���[�V�����p�^�C��
	int m_WallAI;	//�ǂɓ���������
};