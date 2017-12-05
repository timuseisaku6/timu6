#pragma once

#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

class SCStory :public CScene
{
public:
	SCStory();
	~SCStory();
	void InitScene();//初期化メソッド
	void Scene();//実行メソッド
private:
};

