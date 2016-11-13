#pragma once
/*
*Directx 游戏开发指南：p63,main.h
*/
#include <d3d9.h>
#include<d3dx9.h>
#include"CSEngine.h"

#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#define WINDOW_CLASS L"CSGame"
#define WINDOW_NAME L"CSGame"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define FULLSCREEN 0


bool InitializeEngine();
void ShutdownEngine();

//main game function
bool GameInitialize();
void GameLoop();
void GameShutdown();
