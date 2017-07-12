#include"CSEvent.h"

HRESULT cs::CSKeyBoard::Init(IDirectInput8 *pDirectInput, HWND hwnd) {
	V_RETURN(pDirectInput->CreateDevice(GUID_SysKeyboard, &m_pDevice, nullptr));
	V_RETURN(m_pDevice->SetCooperativeLevel(hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE));
	V_RETURN(m_pDevice->SetDataFormat(&c_dfDIKeyboard));
	V_RETURN(m_pDevice->Acquire());
	return S_OK;
}

void cs::CSKeyBoard::GetInput() {
	if (m_pDevice->GetDeviceState(sizeof(m_keyBuffer), (LPVOID)m_keyBuffer) == DIERR_INPUTLOST) {
		m_pDevice->Acquire();
		m_pDevice->GetDeviceState(sizeof(m_keyBuffer), (LPVOID)m_keyBuffer);
	}
}
bool cs::CSKeyBoard::IsKeyPressed(int iKey) {
	if (m_keyBuffer[iKey] & 0x80) {
		return true;
	}
	else {
		return false;
	}
}
void cs::CSKeyBoard::Destroy() {
	if (m_pDevice != nullptr) {
		m_pDevice->Unacquire();
	}
	SAFE_RELEASE(m_pDevice);
}

HRESULT cs::CSMouse::Init(IDirectInput8 *pDirectInput, HWND hwnd) {
	V_RETURN(pDirectInput->CreateDevice(GUID_SysMouse, &m_pDevice, nullptr));
	V_RETURN(m_pDevice->SetCooperativeLevel(hwnd, DISCL_BACKGROUND | DISCL_NONEXCLUSIVE));
	V_RETURN(m_pDevice->SetDataFormat(&c_dfDIMouse));
	V_RETURN(m_pDevice->Acquire());
	return S_OK;
}
void cs::CSMouse::GetInput() {
	HRESULT hr;
	DWORD readNum = 1;
	ZeroMemory(m_inputData, sizeof(m_inputData));

	m_xMove = 0;
	m_yMove = 0;
	//验证是否丢失设备
	for (int i = 0; i < MouseBufferSize; i++) {
		if (m_pDevice->GetDeviceData(sizeof(DIDEVICEOBJECTDATA),&m_inputData[i],&readNum,0) == DIERR_INPUTLOST) 
		{
			m_pDevice->Acquire();
			m_pDevice->GetDeviceData(sizeof(DIDEVICEOBJECTDATA),
				&m_inputData[i],&readNum,0);
		}
		//计算相对移动数据
		if (m_inputData[i].dwOfs == DIMOFS_BUTTON0
			&& (m_inputData[i].dwData & 0x80)) {
			m_LeftDown = true;
		}
		else if (m_inputData[i].dwOfs == DIMOFS_BUTTON0
			&& !(m_inputData[i].dwData & 0x80)) {
			m_LeftDown = false;
		}

		if (m_inputData[i].dwOfs == DIMOFS_BUTTON1
			&& (m_inputData[i].dwData & 0x80)) {
			m_RightDown = true;
		}
		else if (m_inputData[i].dwOfs == DIMOFS_BUTTON1
			&& !(m_inputData[i].dwData & 0x80)) {
			m_RightDown = false;
		}

		if (m_inputData[i].dwOfs == DIMOFS_BUTTON2
			&& (m_inputData[i].dwData & 0x80)) {
			m_MidDown = true;
		}
		else if (m_inputData[i].dwOfs == DIMOFS_BUTTON2
			&& !(m_inputData[i].dwData & 0x80)) {
			m_MidDown = false;
		}
	}
	
}
void cs::CSMouse::Destroy() {
	if (m_pDevice != nullptr) {
		m_pDevice->Unacquire();
	}
	SAFE_RELEASE(m_pDevice);
}