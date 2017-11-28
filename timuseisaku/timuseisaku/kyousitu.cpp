#include "kyousitu.h"
#include "GameL\SceneObjManager.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

using namespace GameL;



kyousitu::kyousitu()
{
}


kyousitu::~kyousitu()
{
}

void kyousitu::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

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

	Draw::Draw(2, &src, &dst, c, 0.0f);
}