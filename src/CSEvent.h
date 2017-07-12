#pragma once
#include<dinput.h>
#include<XInput.h>
#include"CSMacro.h"
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

	class CSMouse {
	private:
		enum 
		{
			MouseBufferSize=16
		};
		IDirectInputDevice8 *m_pDevice;
	public:
		DIDEVICEOBJECTDATA m_inputData[MouseBufferSize];
		bool m_LeftDown;
		bool m_RightDown;
		bool m_MidDown;
		long m_xMove;
		long m_yMove;
	public:
		HRESULT Init(IDirectInput8 *pDirectInput, HWND hwnd);
		void GetInput();
		void Destroy();
	};

}