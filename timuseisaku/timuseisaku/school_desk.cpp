//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "school_desk.h"

//�g�p����l�[���X�؁[�X
using namespace GameL;

#define PLAYER_SPEED	2.0f
#define ENEMY_SPEED		1.5f

#define ANGLE 8	//HitBox�ɂ���đΊp����ς���

school_desk::school_desk(float x,float y)
{
	m_x = x;
	m_y = y;
}

void school_desk::Init()
{
	//�����蔻��pHitBox�쐬
	Hits::SetHitBox(this, m_x+3, m_y, 25, 40, ELEMENT_FIELD, OBJ_SCHOOL_DESK, 1);

}

void school_desk::Action()
{
	CHitBox* hit = Hits::GetHitBox(this);

	//��l���Ƃ̓����蔻��
	if (hit->CheckObjNameHit(OBJ_PLAYER) != nullptr)
	{
		//��l���̈ʒu���擾
		CObjPlayer* player = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);
		float px = player->GetX() + 3;
		float py = player->GetY() + 40;

		//vector�̍쐬
		float vx = px - m_x-1.5f;
		float vy = py - m_y-7.5f;

		//���������߂�
		float len = sqrt(vx*vx + vy*vy);

		//�p�x�����߂�
		float r = atan2(vy, vx);
		r = r*180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//�p�x�ŏ㉺���E�𔻒�
		if ((r <= (45+ ANGLE) && r>=0) || r > (315 - ANGLE))
		{
			//�E
			player->SetX(PLAYER_SPEED);
		}
		if (r > (45+ ANGLE) && r<(135- ANGLE))
		{
			//��
			player->SetY(-PLAYER_SPEED);
		}
		if (r >= (135- ANGLE) && r<=(225+ ANGLE))
		{
			//��
			player->SetX(-PLAYER_SPEED);
		}
		if (r > (225+ ANGLE) && r<(315- ANGLE))
		{
			//��
			player->SetY(PLAYER_SPEED);
		}

	}
	//�G�Ƃ̓����蔻��
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		//�G�̈ʒu���擾
		CObjEnemy* enemy = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
		float px = enemy->GetX() + 7;
		float py = enemy->GetY() + 30;

		//vector�̍쐬
		float vx = px - m_x-1.5f;
		float vy = py - m_y-7.5f;

		//���������߂�
		float len = sqrt(vx*vx + vy*vy);

		//�p�x�����߂�
		float r = atan2(vy, vx);
		r = r*180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);

		//�p�x�ŏ㉺���E�𔻒�
		if ((r <= (45 + ANGLE) && r >= 0) || r > (315 - ANGLE))
		{
			//�E
			enemy->SetX(ENEMY_SPEED);
		}
		if (r > (45 + ANGLE) && r<(135 - ANGLE))
		{
			//��
			enemy->SetY(-ENEMY_SPEED);
		}
		if (r >=(135 - ANGLE) && r<=(225 + ANGLE))
		{
			//��
			enemy->SetX(-ENEMY_SPEED);
		}
		if (r >(225 + ANGLE) && r<(315 - ANGLE))
		{
			//��
			enemy->SetY(ENEMY_SPEED);
		}

	}

}

void school_desk::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;

	src.m_top = 267.0f;
	src.m_left = 0.0f;
	src.m_right = 31.0f;
	src.m_bottom = 312.0f;

	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 31.0f + m_x;
	dst.m_bottom = 45.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}