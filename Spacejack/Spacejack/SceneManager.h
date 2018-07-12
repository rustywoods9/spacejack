#pragma once

#include <atlimage.h>
#include <iostream>
#include <fstream>

struct Client
{
	unsigned char objectType;
	int posX;
	int posY;
	int level;
	int exp;
	int hp;
};

class SceneManager
{
	// 배경 타일
	CImage m_iTile;

	// 플레이어, 다른 유저
	CImage m_iPlayer;
	CImage m_iUser;

	// 몬스터
	CImage m_iMonster1;
	CImage m_iMonster2;
	CImage m_iMonster3;
	CImage m_iMonster4;

	// 챗팅 활성화 아이콘
	CImage m_iChatIcon;

	// 화면 크기, 타일 크기
	int m_nWin_Width, m_nWin_Height;
	int m_nTile_Width, m_nTile_Height;

public:
	SceneManager();
	~SceneManager();

	void ImageAlphaSetting(CImage*);

	void Render(HDC);

	int GetWinWidth();
	int GetWinHeight();

	void ProcessKeyDown(wchar_t tChar);
	void PressBackspace();
};