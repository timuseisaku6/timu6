#include <math.h>
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;
//---UnitVec�֐�
//����1�@float* vx �F�x�N�g���̂w�����̃|�C���^
//����2�@float* vy �F�x�N�g���̂x�����̃|�C���^
//�߂�lbool       �Ftrue=�v�Z�����@false=�v�Z���s
//���e
//�����̃x�N�g���𐳋K�������̒l��vx,vy�ɕύX���܂�


bool UnitVec(float* vx, float * vy)
{
	//�x�N�g���̒��������߂�i�O�����̒藝�j
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);//r�����[�g�����߂�

				//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		//0�Ȃ�v�Z���s
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}

	//�v�Z����
	return true;
}

//---CheckWindow�֐�
//����1�@float pos_x       :�̈�O���ǂ������ׂ�x�ʒu
//����2�@float pos_y       :�̈�O���ǂ������ׂ�y�ʒu
//����3�@float window_x    :�̈��top�ʒu
//����4�@float window_y    :�̈��left�ʒu
//����5�@float window_w    :�̈��right�ʒu
//����6�@float window_h    :�̈��bottom�ʒu
//�߂�l bool			�Ftrue=�̈���@false=�̈�O
//���e
//�̈�����ǂ������ׂ�ʒupos_(x,y)��window_(xywh)�̓����O���𒲂ׂ�
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{
	//�̈�`�F�b�N
	if (pos_x < window_x)
	{
		return false;
	}
	if (pos_x > window_w)
	{
		return false;
	}
	if (pos_y < window_y)
	{
		return false;
	}
	if (pos_y > window_h)
	{
		return false;
	}

	return true;
}

//---GetAtan2Angle�֐�
//����1�@float w     :��
//����2�@float h     :����
//�߂�l float       :�p�x�i0���`360���j
//���e
//�����ƕ����璼�p�O�p�`������Ɖ��肵���̊p�x�����߂�
float GetAtan2Angle(float w, float h)
{
	//atan2�Ŋp�x�����߂�
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180���`0�����@180���`360���ɕϊ�
	if (r < 0)
	{
		r = 360 - abs(r);
	}

	return r;
}

//---Getkatta-Effec�֐�
//����1  int* ani;		�A�j���[�V����
//����2  int* ani_time;	�A�j���[�V�����Ԋu�^�C��
//����3  bool del;		�폜�`�F�b�N�itrue=�G�t�F�N�g�@false=�ʏ�
//����4  int  timing	�Ԋu���
//�߂�l�@RECT_F eff;	�`�悷��RECT
//del�Œe�ۂ�RECT�⒅�eeffect��RECT(�A�j���[�V������RECT)��Ԃ�

RECT_F GetBulletEffec(int* ani, int*ani_time, bool del, int timing)
{
	//�Ԃ�RECT���
	RECT_F rect;

	//�t���O�Œʏ킩�A�j���[�V������������
	if (del == true)
	{
		//�A�j���[�V����
		//���\�[�X�A�j���[�V�����ʒu
		RECT_F ani_src[5] =
		{
			{ 32, 0,32,64 },
			{ 32,32,64,64 },
			{ 32,64,96,64 },
			{ 32,96,128,64 },
			{ 0,0,0,0 },
		};
		//�A�j���[�V�����̃R�}�Ԋu
		if (*ani_time > timing)
		{
			*ani += 1;
			*ani_time = 0;
		}
		else
		{
			*ani_time += 1;
		}

		rect = ani_src[*ani];
	}
	else
	{
		//�e�ۂ̓A�j���[�V��������
		//���\�[�X�e�ۈʒu
		RECT_F bullet = { 0.0f,96.0f,126.0f,32.0f };
		rect = bullet;
	}

	return rect;
}