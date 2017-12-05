//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjEnemy.h"
#include "UtilityModule.h"
#include <random>

//�g�p����l�[���X�؁[�X
using namespace GameL;

std::random_device rnd;     // �񌈒�I�ȗ���������𐶐�
std::mt19937 mt(rnd());     //  �����Z���k�E�c�C�X�^��32�r�b�g�ŁA�����͏����V�[�h�l
std::uniform_int_distribution<> rand20(64, 83);        // [1, 6] �͈͂̈�l����

#define ENEMY_SPEED 1.5f;

//�R���X�g���N�^
CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//���E���ǂɓ��������牺�ɍs��
void CObjEnemy::SetX(float x)
{
	m_x += x;
	m_y += ENEMY_SPEED;
	m_WallAI = 1;
}

//�㉺���ǂɓ���������E�ɍs��
void CObjEnemy::SetY(float y)
{
	m_y += y;
	m_x += ENEMY_SPEED;
	m_WallAI = 2;
}

//�C�j�V�����C�Y
void CObjEnemy::Init()
{
	m_r = 3;			//�ŏ��̌���
	m_time = 0;
	m_ani_time = 0;
	m_WallAI = 0;
	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 27, 25, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//�A�N�V����
void CObjEnemy::Action()
{
	m_time++;
	//��l���@�ƗU���e�ۂŊp�x�����
	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	//��l���@�����݂���ꍇ�A�U���p�x�̌v�Z����
	if (obj != nullptr)
	{	
		if (m_time >= rand20(mt)) {
			float x = obj->GetX() - m_x;
			float y = obj->GetY() + 15.0f - m_y;
			ar = GetAtan2Angle(x, -y);
			m_time = 0;
		}

		m_WalkFlag = false;

		if (0.0f <= ar && ar < 45.0f ||
			315.0f <= ar && ar < 360.0f)
		{
			m_x += ENEMY_SPEED;
			m_r = 1;			//�E����
			m_WalkFlag = true;
		}
		else if (45.0f <= ar &&  ar < 135.0f)
		{
			m_y -= ENEMY_SPEED;
			m_r = 0;			//�����
			m_WalkFlag = true;
		}
		else if (135.0f <= ar && ar < 225.0f)
		{
			m_x -= ENEMY_SPEED;
			m_r = 2;			//������
			m_WalkFlag = true;
		}
		else if (225.0f <= ar && ar < 315.0f)
		{
			m_y += ENEMY_SPEED;
			m_r = 3;			//������
			m_WalkFlag = true;
		}
	}	

	//�G���̈�O�s���Ȃ��悤��
	if (m_x + 44.0f > 800.0f)
	{
		m_x = 800.0f - 44.0f;
	}
	if (m_y + 54.0f > 600.0f)
	{
		m_y = 600.0f - 54.0f;
	}
	if (m_y  < 110.0f)
	{
		m_y = 110.0f;
	}
	if (m_x  < 0.0f)
	{
		m_x = 0.0f;
	}

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);	//�쐬����HitBox�p�̓����
	hit->SetPos(m_x + 7, m_y + 30);			//���������V�����ʒu(��l���̈ʒu)���ɒu��������

	if (m_WallAI == 1) {
		m_r = 3;
	}
	else if (m_WallAI == 2) {
		m_r = 1;
	}
	m_WallAI = 0;
}


//�h���[
void CObjEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;


	//�j�]���r

	if (m_r == 0) {
		src.m_top = 0.0f + 179.0f;
		src.m_left = 0.0f + 144.0f;
		src.m_right = 44.0f + 144.0f;
		src.m_bottom = 54.0f + 179.0f;
	}
	else if (m_r == 1) {
		src.m_top = 0.0f + 121.0f;
		src.m_left = 0.0f + 144.0f;
		src.m_right = 44.0f + 144.0f;
		src.m_bottom = 54.0f + 121.0f;
	}
	else if (m_r == 2) {
		src.m_top = 0.0f + 63.0f;
		src.m_left = 0.0f + 144.0f;
		src.m_right = 44.0f + 144.0f;
		src.m_bottom = 54.0f + 63.0f;
	}
	else if (m_r == 3) {
		src.m_top = 0.0f + 5.0f;
		src.m_left = 0.0f + 144.0f;
		src.m_right = 44.0f + 144.0f;
		src.m_bottom = 54.0f + 5.0f;
	}

	if (m_WalkFlag == true) {
		m_ani_time++;
		if (m_ani_time > 40) {
			m_ani_time = 0;
		}
	}
	else {
		m_ani_time = 0;
	}

	if (m_WalkFlag == true) {
		if (m_ani_time <= 10) {
			src.m_left = 0.0f + 189.0f;
			src.m_right = 44.0f + 189.0f;
		}
		else if (m_ani_time <= 20) {
			src.m_left = 0.0f + 144.0f;
			src.m_right = 44.0f + 144.0f;
		}
		else if (m_ani_time <= 30) {
			src.m_left = 0.0f + 102.0f;
			src.m_right = 44.0f + 102.0f;
		}
		else {
			src.m_left = 0.0f + 144.0f;
			src.m_right = 44.0f + 144.0f;
		}
	}

	//���]���r
	//	src.m_left   +=130.0f;
	//	src.m_right  +=130.0f;



	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 44.0f + m_x;
	dst.m_bottom = 54.0f + m_y;


	Draw::Draw(0, &src, &dst, c, 0.0f);
}