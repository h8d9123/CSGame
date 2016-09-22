#pragma once
#include "CSType.h"
#include "CSMacro.h"
namespace cs
{
	class CSObject()
	{
	public:
		CSObject();
		virtual ~CSObject();
	private:
		float x_;
		float y_;
		float z_;
		HMODLE hModel_;
	public:
		float GetPositionX();
		float GetPositionY();
		float GetPositionZ();
		void SetPositionX(float x);
		void SetPositionY(float y);
		void SetPositionZ(float y);
		CSPoint GetPosition();
		void SetPostion(CSPoint pos)
		HMODLE GetModelHandle();
		void	 SetModelHandle(HModel hModle);
	}

}


