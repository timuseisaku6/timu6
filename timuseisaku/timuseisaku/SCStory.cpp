//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SCStory.h"
#include "GameHead.h"



SCStory::SCStory()
{
}


SCStory::~SCStory()
{
}

void SCStory::InitScene()
{
	Draw::LoadImage(L"story.png", 3, TEX_SIZE_1024);


	story* objst = new story();
	Objs::InsertObj(objst, OBJ_STORY, 1);
}

//実行中メソッド
void SCStory::Scene()
{

}