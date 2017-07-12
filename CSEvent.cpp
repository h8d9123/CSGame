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