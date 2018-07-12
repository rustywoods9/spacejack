#include "SceneManager.h"

SceneManager::SceneManager()
{
	// 배경 타일 로드
	m_iTile.Load(L"Tile.png");

	// 플레이어, 다른 유저 이미지 로드
	m_iPlayer.Load(L"Player.png");
	m_iUser.Load(L"User.png");

	// 몬스터 이미지 로드
	m_iMonster1.Load(L"Monster1.png");
	m_iMonster2.Load(L"Monster2.png");
	m_iMonster3.Load(L"Monster3.png");
	m_iMonster4.Load(L"Monster4.png");

	// 챗팅 활성화 아이콘
	m_iChatIcon.Load(L"ChatIcon.png");

	// 택스처 알파 세팅
	ImageAlphaSetting(&m_iTile);
	ImageAlphaSetting(&m_iPlayer);
	ImageAlphaSetting(&m_iUser);
	ImageAlphaSetting(&m_iMonster1);
	ImageAlphaSetting(&m_iMonster2);
	ImageAlphaSetting(&m_iMonster3);
	ImageAlphaSetting(&m_iMonster4);
	ImageAlphaSetting(&m_iChatIcon);

	// 화면 크기, 타일 크기 설정
	m_nWin_Width = 960;
	m_nWin_Height = 900;

	m_nTile_Width = 32;
	m_nTile_Height = 32;
}

SceneManager::~SceneManager()
{

}

void SceneManager::ImageAlphaSetting(CImage* Img)
{
	unsigned char * pCol = 0;

	long w = Img->GetWidth();
	long h = Img->GetHeight();

	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			pCol = (unsigned char *)
				Img->GetPixelAddress(x, y);

			unsigned char alpha = pCol[3];

			if (alpha != 255)
			{
				pCol[0] = (pCol[0] * alpha + 128) >> 8;
				pCol[1] = (pCol[1] * alpha + 128) >> 8;
				pCol[2] = (pCol[2] * alpha + 128) >> 8;
			}
		}
	}
}

void SceneManager::Render(HDC hViewdc)
{

	//////////////////// Map ///////////////////////////////

	

	//////////////////// Player & NPC ///////////////////////

	

	//////////////////// Status ///////////////////////////////
}

int SceneManager::GetWinWidth() { return m_nWin_Width; }

int SceneManager::GetWinHeight() { return m_nWin_Height; }

void SceneManager::ProcessKeyDown(wchar_t tChar)
{
	
}

void SceneManager::PressBackspace()
{
	
}