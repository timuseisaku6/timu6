#include "story.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

#include"GameHead.h"

using namespace GameL;

story::story()
{
	;
}


story::~story()
{
}

void story::Init()
{
	m_key_flag = false;
	m_rgb = 0.0f;
}

void story::Action()
{
	if (m_rgb <= 1.0f) m_rgb += 0.01f;
	
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
		m_key_flag = false;
	}
	else
	{
		m_key_flag = true;
	}
}


void story::Draw()
{
	float c[4] = { m_rgb,m_rgb,m_rgb,1.0f };

	RECT_F src;
	RECT_F dst;

	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);

}