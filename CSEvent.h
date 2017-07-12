#pragma once
#include<dinput.h>
#include<XInput.h>
#include"src/CSMacro.h"
namespace cs {
	class CSKeyBoard{
	public:
		IDirectInputDevice8 *m_pDevice;
		char m_keyBuffer[256];
	public:
		HRESULT Init(IDirectInput8 *pDirectInput, HWND hwnd);
		void GetInput();
		/**
		*Desc:
		*	check whether iKey is pressed;
		*Args:
		*	iKey: eg,DIK_LEFT, DIK_SHIFT,'A', 'B', reference Dinput.h
		*/
		bool IsKeyPressed(int iKey);
		void Destroy();
	};


}