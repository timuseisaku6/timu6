//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
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

//���s�����\�b�h
void SCStory::Scene()
{

}