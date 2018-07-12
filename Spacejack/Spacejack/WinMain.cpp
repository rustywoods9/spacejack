
#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")
#pragma comment(lib,"ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#include <iostream>
#include <locale.h>

#include "SceneManager.h"

#define WINDOW_CLASS_NAME L"Client"

#define WM_SOCKET 0xFF00

// 윈도우 핸들
HWND g_hWnd;
HINSTANCE g_hInst;

// 씬 매니저
SceneManager* g_cSceneManager;

int Game_Init()
{
	g_cSceneManager = new SceneManager();

	return 0;
}

void Game_Shutdown()
{
	
}

void ProcessKeyDown(WPARAM wParam)
{
	switch (wParam)
	{
	case VK_RETURN:
		break;
	case VK_BACK:
		g_cSceneManager->PressBackspace();
		break;
	case VK_CAPITAL:

		break;
	case VK_SHIFT:

		break;
	}
}

void ProcessKeyUp(WPARAM wParam)
{
	switch (wParam)
	{
	case VK_SHIFT:
		
		break;
	}
}

// 윈도우 메시지 콜벡 함수
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		MoveWindow(hWnd, 100, 100, g_cSceneManager->GetWinWidth(), g_cSceneManager->GetWinHeight(), TRUE);
		break;
	case WM_GETMINMAXINFO:
		reinterpret_cast<MINMAXINFO*>(lParam)->ptMaxTrackSize.x = g_cSceneManager->GetWinWidth();
		reinterpret_cast<MINMAXINFO*>(lParam)->ptMaxTrackSize.y = g_cSceneManager->GetWinHeight();
		reinterpret_cast<MINMAXINFO*>(lParam)->ptMinTrackSize.x = g_cSceneManager->GetWinWidth();
		reinterpret_cast<MINMAXINFO*>(lParam)->ptMinTrackSize.y = g_cSceneManager->GetWinHeight();
		break;
	case WM_KEYDOWN:
		ProcessKeyDown(wParam);
		break;
	case WM_KEYUP:
		ProcessKeyUp(wParam);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// Double buffering
		HBITMAP hViewBit = CreateCompatibleBitmap(hdc,
			g_cSceneManager->GetWinWidth(),
			g_cSceneManager->GetWinHeight());

		HDC hViewdc = CreateCompatibleDC(hdc);
		SelectObject(hViewdc, hViewBit);

		// Draw Here
		g_cSceneManager->Render(hViewdc);

		// Double buffering
		BitBlt(hdc, 0, 0,
			g_cSceneManager->GetWinWidth(),
			g_cSceneManager->GetWinHeight(),
			hViewdc, 0, 0, SRCCOPY);

		DeleteDC(hViewdc);
		DeleteObject(hViewBit);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:


		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game_Init();

	// 윈도우 클래스 등록
	WNDCLASS cwnd;
	cwnd.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	cwnd.lpfnWndProc = WndProc;
	cwnd.cbClsExtra = 0;
	cwnd.cbWndExtra = 0;
	cwnd.hInstance = hInstance;
	cwnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	cwnd.hCursor = LoadCursor(NULL, IDC_ARROW);
	cwnd.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	cwnd.lpszMenuName = NULL;
	cwnd.lpszClassName = WINDOW_CLASS_NAME;
	if (!RegisterClass(&cwnd)) return 1;

	// 윈도우 생성
	g_hWnd = CreateWindow(WINDOW_CLASS_NAME, L"Spacejack",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0,
		g_cSceneManager->GetWinWidth() + 16, g_cSceneManager->GetWinHeight() + 39,
		NULL, NULL, hInstance, NULL);

	if (g_hWnd == NULL) return 1;

	g_hInst = hInstance;

	// 메시지 루프
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// test if this is a quit
			if (msg.message == WM_QUIT) break;

			// translate any accelerator keys
			TranslateMessage(&msg);

			// send the message to the window proc
			DispatchMessage(&msg);
		} // end if

		  // main game processing goes here
		InvalidateRect(g_hWnd, NULL, false);
	}

	Game_Shutdown();

	return static_cast<int>(msg.wParam);
}