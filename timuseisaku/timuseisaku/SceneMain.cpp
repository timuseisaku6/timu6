//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{

}

//�Q�[�����C�����������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ��݂O�Ԃɓo�^(512�~512�s�N�Z��)
	Draw::LoadImage(L"image.png", 0, TEX_SIZE_512);

	Draw::LoadImage(L"haikei.png", 2, TEX_SIZE_1024);

	//�v���C���[�I�u�W�F�N�g�쐬
	CObjPlayer* obj = new CObjPlayer(387, 268);
	Objs::InsertObj(obj, OBJ_PLAYER, 1);//������I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	kyousitu* objk = new kyousitu();
	Objs::InsertObj(objk, OBJ_KYOUSITU, 1);
}

//�Q�[�����C�����s�����\�b�h
void CSceneMain::Scene()
{

}