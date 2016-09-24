#pragma once
#include "CSType.h"
#include "CSMacro.h"
namespace cs
{
	class CSObject
	{
	public:
		CSObject();
		virtual ~CSObject();
	private:
		//(x_, y_, z_) descriptes the object's absolute position
		float x_;
		float y_;
		float z_;
		// (dx,dy,dz) descriptes the object's direction
		float dx;
		float dy;
		float dz;
		HMODLE hModel_;
	public:
		float GetPositionX();
		float GetPositionY();
		float GetPositionZ();
		
		void SetPositionX(float x);
		void SetPositionY(float y);
		void SetPositionZ(float z);

		CSVector3 GetDirection();
		CSPoint GetPosition();

		void SetPosition(CSPoint pos);
		void SetPosition(float x, float y, float z);
		void SetDirection(CSVector3 dir);
		void SetDirection(float x, float y, float z);
		void MoveTo(CSPoint pos);
		void MoveTo(float x, float y, float z);
		HMODLE GetModelHandle();
		void	 SetModelHandle(HMODEL hModel);
	}

}


