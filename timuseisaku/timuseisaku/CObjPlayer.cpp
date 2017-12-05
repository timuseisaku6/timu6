//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjPlayer.h"

//�g�p����l�[���X�؁[�X
using namespace GameL;

#define PLAYER_SPEED	2.0f

//�R���X�g���N�^
CObjPlayer::CObjPlayer(float x, float y)
{
	m_x = x;
	m_y = y;
}
void CObjPlayer::SetX(float x)
{
	m_x += x;
}

void CObjPlayer::SetY(float y)
{
	m_y += y;
}

//�C�j�V�����C�Y
void CObjPlayer::Init()
{
	m_r = 3;			//�ŏ��̌���
	m_ani_time = 0;

	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x, m_y, 27, 25, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//�A�N�V����
void CObjPlayer::Action()
{
	m_keydown = false;

	if (Input::GetVKey(VK_UP) == true)
	{
		m_y -= PLAYER_SPEED;
		m_r = 0;			//�����
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += PLAYER_SPEED;
		m_r = 1;			//�E����
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= PLAYER_SPEED;
		m_r = 2;			//������
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += PLAYER_SPEED;
		m_r = 3;			//������
		m_keydown = true;
	}

	//��l�����̈�O�s���Ȃ��悤��
	if (m_x + 33.0f > 800.0f)
	{
		m_x = 800.0f - 33.0f;
	}
	if (m_y + 65.0f > 600.0f)
	{
		m_y = 600.0f - 65.0f;
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
	hit->SetPos(m_x+3, m_y+40);				//���������V�����ʒu(��l���̈ʒu)���ɒu��������

	//enemy�I�u�W�F�N�g�ƐڐG�������l������
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);		//���g�ɍ폜����
		Hits::DeleteHitBox(this);	//HitBox�폜
	}
}

//�h���[
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//�؂���ʒu
	RECT_F dst;	//�\���ʒu

	//��l���`��

	if (m_r == 0) {
		src.m_top = 199.0f;
		src.m_left = 34.0f;
		src.m_right = 67.0f;
		src.m_bottom = 264.0f;
	}
	else if (m_r == 1) {
		src.m_top = 133.0f;
		src.m_left = 34.0f;
		src.m_right = 67.0f;
		src.m_bottom = 198.0f;
	}
	else if (m_r == 2) {
		src.m_top = 67.0f;
		src.m_left = 34.0f;
		src.m_right = 67.0f;
		src.m_bottom = 132.0f;
	}
	else if (m_r == 3) {
		src.m_top = 1.0f;
		src.m_left = 34.0f;
		src.m_right = 67.0f;
		src.m_bottom = 66.0f;
	}

	if (m_keydown == true) {
		m_ani_time++;
		if (m_ani_time > 24) {
			m_ani_time = 0;
		}
	}
	else {
		m_ani_time = 0;
	}

	if (m_keydown == true) {
		if (m_ani_time <= 6) {
			src.m_left = 67.0f;
			src.m_right = 100.0f;
		}
		else if (m_ani_time <= 12) {
			src.m_left = 34.0f;
			src.m_right = 67.0f;
		}
		else if (m_ani_time <= 18) {
			src.m_left = 1.0f;
			src.m_right = 34.0f;
		}
		else {
			src.m_left = 34.0f;
			src.m_right = 67.0f;
		}
	}


	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 33.0f + m_x;
	dst.m_bottom = 65.0f + m_y;

	//�\��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}