#pragma once
#include "GameL\SceneObjManager.h"

using namespace GameL;

class story :public CObj
{
public:
	story();
	~story();
	void Init();//イニシャライズ
	void Action();//アクション
	void Draw();//ドロー
private:
	bool m_key_flag;//キーフラグ
	float m_rgb;	//RGB操作用
};

