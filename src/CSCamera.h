#pragma once
#include "CSObject.h"
#include <d3dx9math.h>
namespace cs
{
	class CSCamera
	{
	public :
		enum CAMERATYPE
		{
			LANDCAMERA,
			AIRCAMERA
		};
	public:
		CSCamera(CAMERATYPE type);
		// set and get members
		void SetPos(D3DXVECTOR3 vPos) { m_vPos = vPos; }
		void SetLookVec(D3DXVECTOR3 vLook) { m_vLook = vLook; }
		void SetUpVec(D3DXVECTOR3 vUp) { m_vUp = vUp; }
		void SetRightVec(D3DXVECTOR3 vRight) { m_vRight = vRight; }

		D3DXVECTOR3 GetPos() { return m_vPos; }
		D3DXVECTOR3 GetLookVec() { return m_vLook; }
		D3DXVECTOR3 GetUpVec() {return m_vUp; }
		D3DXVECTOR3 GetRightVec() { return m_vRight; }
		//set cameratype
		void SetCameraType(CAMERATYPE type) { m_CameraType = type; }
		CAMERATYPE GetCameraType() { return m_CameraType; }

		//control camera funcs
		void Pitch(float fAngle);
		void Yaw(float fAngle);
		void Roll(float fAngle);
		void Strafe(float fDistance);
		void Fly(float fDistance);
		void Walk(float fDistance);

		void GetViewMatirx(D3DXMATRIXA16*);


	
	private:
		D3DXVECTOR3 m_vPos;
		D3DXVECTOR3 m_vLook;
		D3DXVECTOR3 m_vUp;
		D3DXVECTOR3 m_vRight;
		CAMERATYPE m_CameraType;
	
	

	};
}
