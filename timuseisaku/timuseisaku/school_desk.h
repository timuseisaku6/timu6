#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class school_desk:public CObj
{
public:
	school_desk(float x,float y);
	~school_desk() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

private:
	float m_x;
	float m_y;
};

