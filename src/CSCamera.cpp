#pragma once
#include"CSCamera.h"

using namespace cs;
CSCamera::CSCamera(CAMERATYPE type)
{
	m_vPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_vRight = D3DXVECTOR3(1.0f, 0.0f, 0.0f);
	m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
	m_vLook = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	m_CameraType = type;
}

void CSCamera::Pitch(float fAngle)//ÉÏÏòÁ¿Æ«º½½Ç
{
	D3DXMATRIXA16 matPitch;
	D3DXMatrixRotationAxis(&matPitch, &m_vRight, fAngle);
	D3DXVec3TransformCoord(&m_vLook, &m_vLook, &matPitch);
	D3DXVec3TransformCoord(&m_vUp, &m_vUp, &matPitch);
}

void CSCamera::Yaw(float fAngle)
{
	D3DXMATRIXA16 matYaw;
	if (m_CameraType == LANDCAMERA)
		D3DXMatrixRotationY(&matYaw, fAngle);
	else
		D3DXMatrixRotationAxis(&matYaw, &m_vUp, fAngle);
	D3DXVec3TransformCoord(&m_vLook, &m_vLook, &matYaw);
	D3DXVec3TransformCoord(&m_vRight, &m_vRight, &matYaw);
}

void CSCamera::Roll(float fAngle)
{
	D3DXMATRIXA16 matRoll;
	if (m_CameraType == AIRCAMERA)
	{
		D3DXMatrixRotationAxis(&matRoll, &m_vRight, fAngle);
		D3DXVec3TransformCoord(&m_vRight, &m_vRight, &matRoll);
		D3DXVec3TransformCoord(&m_vUp, &m_vUp, &matRoll);
	}
}

void CSCamera::Strafe(float fDistance)
{
	if (m_CameraType == LANDCAMERA)
		m_vPos += (D3DXVECTOR3(m_vRight.x, 0.0f, m_vRight.z)*fDistance);
	else
		m_vPos += (m_vPos*fDistance);
}

void CSCamera::Fly(float fDistance)
{
	if (m_CameraType == LANDCAMERA)
		m_vPos.y += fDistance;
	else
		m_vPos += (m_vPos*fDistance);
}

void CSCamera::Walk(float fDistance)
{
	if (m_CameraType == LANDCAMERA)
		m_vPos += (D3DXVECTOR3(m_vLook.x, 0.0f, m_vLook.z)*fDistance);
	else
		m_vPos += (m_vLook*fDistance);
}
void CSCamera::GetViewMatirx(D3DXMATRIXA16 *pMatView)
{
	D3DXVec3Normalize(&m_vLook, &m_vLook);
	D3DXVec3Cross(&m_vUp, &m_vLook, &m_vRight);
	D3DXVec3Normalize(&m_vUp, &m_vUp);

	D3DXVec3Cross(&m_vRight, &m_vUp, &m_vLook);
	D3DXVec3Normalize(&m_vRight, &m_vRight);

	pMatView->_11 = m_vRight.x;
	pMatView->_12 = m_vUp.x;
	pMatView->_13 = m_vLook.x;
	pMatView->_14 = 0.0f;

	pMatView->_21 = m_vRight.y;
	pMatView->_22 = m_vUp.y;
	pMatView->_23 = m_vLook.y;
	pMatView->_24 = 0.0f;

	pMatView->_31 = m_vRight.z;
	pMatView->_32 = m_vUp.z;
	pMatView->_33 = m_vLook.z;
	pMatView->_34 = 0.0f;

	pMatView->_41 = -D3DXVec3Dot(&m_vPos, &m_vRight);
	pMatView->_42 = -D3DXVec3Dot(&m_vPos, &m_vUp);
	pMatView->_43 = -D3DXVec3Dot(&m_vPos, &m_vLook);
	pMatView->_44 = 1.0f;
}