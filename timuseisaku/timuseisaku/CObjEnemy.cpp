//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "CObjEnemy.h"
#include "UtilityModule.h"
#include <random>

//使用するネームスぺース
using namespace GameL;

std::random_device rnd;     // 非決定的な乱数生成器を生成
std::mt19937 mt(rnd());     //  メルセンヌ・ツイスタの32ビット版、引数は初期シード値
std::uniform_int_distribution<> rand20(64, 83);        // [1, 6] 範囲の一様乱数

#define ENEMY_SPEED 1.5f;

//コンストラクタ
CObjEnemy::CObjEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//左右が壁に当たったら下に行く
void CObjEnemy::SetX(float x)
{
	m_x += x;
	m_y += ENEMY_SPEED;
	m_WallAI = 1;
}

//上下が壁に当たったら右に行く
void CObjEnemy::SetY(float y)
{
	m_y += y;
	m_x += ENEMY_SPEED;
	m_WallAI = 2;
}

//イニシャライズ
void CObjEnemy::Init()
{
	m_r = 3;			//最初の向き
	m_time = 0;
	m_ani_time = 0;
	m_WallAI = 0;
	//当たり判定用HitBox作成
	Hits::SetHitBox(this, m_x, m_y, 27, 25, ELEMENT_ENEMY, OBJ_ENEMY, 1);
}

//アクション
void CObjEnemy::Action()
{
	m_time++;
	//主人公機と誘導弾丸で角度を取る
	CObjPlayer* obj = (CObjPlayer*)Objs::GetObj(OBJ_PLAYER);

	//主人公機が存在する場合、誘導角度の計算する
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
			m_r = 1;			//右向き
			m_WalkFlag = true;
		}
		else if (45.0f <= ar &&  ar < 135.0f)
		{
			m_y -= ENEMY_SPEED;
			m_r = 0;			//上向き
			m_WalkFlag = true;
		}
		else if (135.0f <= ar && ar < 225.0f)
		{
			m_x -= ENEMY_SPEED;
			m_r = 2;			//左向き
			m_WalkFlag = true;
		}
		else if (225.0f <= ar && ar < 315.0f)
		{
			m_y += ENEMY_SPEED;
			m_r = 3;			//下向き
			m_WalkFlag = true;
		}
	}	

	//敵が領域外行かないように
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

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);	//作成したHitBox用の入り口
	hit->SetPos(m_x + 7, m_y + 30);			//入り口から新しい位置(主人公の位置)情報に置き換える

	if (m_WallAI == 1) {
		m_r = 3;
	}
	else if (m_WallAI == 2) {
		m_r = 1;
	}
	m_WallAI = 0;
}


//ドロー
void CObjEnemy::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;
	RECT_F dst;


	//男ゾンビ

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

	//女ゾンビ
	//	src.m_left   +=130.0f;
	//	src.m_right  +=130.0f;



	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 44.0f + m_x;
	dst.m_bottom = 54.0f + m_y;


	Draw::Draw(0, &src, &dst, c, 0.0f);
}