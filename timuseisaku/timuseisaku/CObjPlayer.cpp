//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjPlayer.h"

//使用するネームスぺース
using namespace GameL;

#define PLAYER_SPEED	2.0f

//コンストラクタ
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

//イニシャライズ
void CObjPlayer::Init()
{
	m_r = 3;			//最初の向き
	m_ani_time = 0;

	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 27, 25, ELEMENT_PLAYER, OBJ_PLAYER, 1);
}

//アクション
void CObjPlayer::Action()
{
	m_keydown = false;

	if (Input::GetVKey(VK_UP) == true)
	{
		m_y -= PLAYER_SPEED;
		m_r = 0;			//上向き
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += PLAYER_SPEED;
		m_r = 1;			//右向き
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= PLAYER_SPEED;
		m_r = 2;			//左向き
		m_keydown = true;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += PLAYER_SPEED;
		m_r = 3;			//下向き
		m_keydown = true;
	}

	//主人公が領域外行かないように
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

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox用の入り口
	hit->SetPos(m_x+3, m_y+40);				//入り口から新しい位置(主人公の位置)情報に置き換える

	//enemyオブジェクトと接触したら主人公消滅
	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		this->SetStatus(false);		//自身に削除命令
		Hits::DeleteHitBox(this);	//HitBox削除
	}
}

//ドロー
void CObjPlayer::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;	//切り取り位置
	RECT_F dst;	//表示位置

	//主人公描画

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

	//表示
	Draw::Draw(0, &src, &dst, c, 0.0f);
}