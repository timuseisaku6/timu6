#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

class kyousitu:public CObj
{
public:
	kyousitu();
	~kyousitu();
	void Init();
	void Action();
	void Draw();
};