//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "CObjPlayer.h"

//�g�p����l�[���X�؁[�X
using namespace GameL;

//�R���X�g���N�^
CObjPlayer::CObjPlayer(float x, float y)
{
	m_x = x;
	m_y = y;
}

//�C�j�V�����C�Y
void CObjPlayer::Init()
{
	m_r = 3;			//�ŏ��̌���
	m_ani_time = 0;
}

//�A�N�V����
void CObjPlayer::Action()
{
	m_keydown = false;

	if (Input::GetVKey(VK_UP) == true)
	{
		m_y -= 2.0f;
		m_r = 0;			//�����
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += 2.0f;
		m_r = 1;			//�E����
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= 2.0f;
		m_r = 2;			//������
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += 2.0f;
		m_r = 3;			//������
		m_keydown = true;
	}

}

//�h���[
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

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

	/*�j�]���r

	if (m_r == 0) {
	src.m_top = 0.0f+179.0f;
	src.m_left = 0.0f+144.0f;
	src.m_right = 44.0f+144.0f;
	src.m_bottom = 54.0f+179.0f;
	}
	else if (m_r == 1) {
	src.m_top = 0.0f+121.0f;
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
	src.m_top = 0.0f+5.0f;
	src.m_left = 0.0f + 144.0f;
	src.m_right = 44.0f + 144.0f;
	src.m_bottom = 54.0f + 5.0f;
	}

	if (m_keydown == true) {
	m_ani_time++;
	if (m_ani_time > 40) {
	m_ani_time = 0;
	}
	}
	else {
	m_ani_time = 0;
	}

	if (m_keydown == true) {
	if (m_ani_time <= 10) {
	src.m_left = 0.0f+190.0f;
	src.m_right = 44.0f + 190.0f;
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
	src.m_left   +=129.0f;
	src.m_right  +=129.0f;



	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 44.0f + m_x;
	dst.m_bottom = 54.0f + m_y;
	*/

	Draw::Draw(0, &src, &dst, c, 0.0f);
}