#include "main.h"

//globals ...
HWND g_hwnd;
CSRenderInterface *g_Render = nullptr;

LRESULT WINAPI MsgProc(HWND hd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		break;
	case WM_KEYUP:
		if (wp == VK_ESCAPE)
			PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE h, HINSTANCE p, LPSTR cmd, int show)
{
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		WINDOW_CLASS, NULL
	};
	RegisterClassEx(&wc);

	// Create the application's window
	if (FULLSCREEN)
	{
		g_hwnd = CreateWindowEx(NULL, WINDOW_CLASS, WINDOW_NAME,
			WS_POPUP | WS_SYSMENU | WS_VISIBLE, 0, 0, WINDOW_WIDTH,
			WINDOW_HEIGHT, NULL, NULL, h, NULL);
	}else
	{
		g_hwnd = CreateWindowEx(NULL, WINDOW_CLASS, WINDOW_NAME,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE, 0, 0, WINDOW_WIDTH,
			WINDOW_HEIGHT, NULL, NULL, h, NULL);
	}

	if (g_hwnd)
	{
		//show window
		ShowWindow(g_hwnd, SW_SHOWDEFAULT);
		UpdateWindow(g_hwnd);
	}
	// initialize Engine
	if (InitializeEngine())
	{
		// initialize Game
		if (GameInitialize())
		{
			// process message
			MSG msg;
			ZeroMemory(&msg, sizeof(msg));
			while (msg.message!=WM_QUIT)
			{
				if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				else
				{
					//start game;
					GameLoop();
				}
			}
		}
	}
	//close game
	GameShutdown();
	//close engine;
	ShutdownEngine();
	UnregisterClass(WINDOW_CLASS, wc.hInstance);
	_CrtDumpMemoryLeaks();
	return 0;
	
}

bool InitializeEngine()
{
	if (!CreateD3DRender(&g_Render)) return false;

	if (!g_Render->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT,
		g_hwnd, FULLSCREEN)) return false;

	g_Render->SetClearColor(0, 0, 0);
	return true;
}

void ShutdownEngine()
{
	if (g_Render)
	{
		g_Render->Shutdown();
		delete g_Render;
		g_Render = nullptr;
	}
}

bool GameInitialize()
{
	return true;
}
void GameLoop()
{
	if (!g_Render) return;

	g_Render->StartRender(1, 1, 0);
	g_Render->EndRender();
}
void GameShutdown()
{

}