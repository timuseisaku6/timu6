#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：プレイヤー
class CObjEnemy :public CObj
{
public:
	CObjEnemy(float x, float y);//コンストラクタ
	~CObjEnemy() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
	float GetX() { return m_x; }
	float GetY() { return m_y; }
	void SetX(float x);
	void SetY(float y);
private:
	float m_x;	//X方向移動用
	float m_y;	//Y方向移動用
	int m_r;	//向き
	float ar;	//主人公の向き
	bool m_WalkFlag;//歩きフラグ
	int m_time;
	int m_ani_time;	//歩きアニメーション用タイム
	int m_WallAI;	//壁に当たったら
};