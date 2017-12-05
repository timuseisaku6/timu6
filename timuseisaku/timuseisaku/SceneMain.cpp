//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{

}

//ゲームメイン初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込み０番に登録(512×512ピクセル)
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"haikei.png", 2, TEX_SIZE_1024);

	//プレイヤーオブジェクト作成
	CObjPlayer* obj = new CObjPlayer(387, 268);
	Objs::InsertObj(obj, OBJ_PLAYER, 1);//作ったオブジェクトをオブジェクトマネージャーに登録

	kyousitu* objk = new kyousitu();
	Objs::InsertObj(objk, OBJ_KYOUSITU, 1);
}

//ゲームメイン実行中メソッド
void CSceneMain::Scene()
{

}