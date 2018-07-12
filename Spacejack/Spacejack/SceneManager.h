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
	// ��� Ÿ��
	CImage m_iTile;

	// �÷��̾�, �ٸ� ����
	CImage m_iPlayer;
	CImage m_iUser;

	// ����
	CImage m_iMonster1;
	CImage m_iMonster2;
	CImage m_iMonster3;
	CImage m_iMonster4;

	// ê�� Ȱ��ȭ ������
	CImage m_iChatIcon;

	// ȭ�� ũ��, Ÿ�� ũ��
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