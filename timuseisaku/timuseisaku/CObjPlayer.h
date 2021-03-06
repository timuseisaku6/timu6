#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：プレイヤー
class CObjPlayer :public CObj
{
public:
	CObjPlayer(float x, float y);//コンストラクタ
	~CObjPlayer() {};
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
	int m_ani_time;//歩きアニメーション用タイム
	bool m_keydown;//移動キーが押されているか
};