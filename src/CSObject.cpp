#include "CSObject.h"

namespace cs
{
	/**
	*gets object's position
	*/
	float CSObject::GetPositionX()
	{
		return x_;
	}

	float CSObject::GetPositionY()
	{
		return y_;
	}

	float CSObject::GetPositionZ()
	{
		return z_;
	}

	CSPOINT CSObject::GetPosition()
	{
		return CSPOINT(x_, y_, z_);
	}


	/**
	*sets object's position
	*/
	void CSObject::SetPositionX(float x)
	{
		x_ = x;
	}

	void CSObject::SetPositionY(float y)
	{
		y_ = y;
	}

	void CSObject::SetPositionZ(float zx)
	{
		z_ = z;
	}

	void CSObject::SetPosition(CSPOINT pos)
	{
		x_ = pos.x;
		y_ = pos.y;
		z_ = pos.z;
	}

	void CSObject::SetPosition(float x, float y, float z)
	{
		x_ = x;
		y_ = y;
		z_ = z;
	}

	/**
	*sets or gets object's direction in 3d world.
	*this direction is baseed on position 
	*rather than origin of coordinate in 3d world
	*this vector ,(dx, dy, dz), assigns where object's 
	*x-axis in local coordinate is
	*/

	//gets its direction;
	CSVECTOR3 CSObject::GetDirection()
	{
		return CSVector(dx, dy, dz);
	}

	//set its direction
	void CSObject::SetDirection(CSVECTOR3 dir)
	{
		dx_ = dir.x;
		dy_ = dir.y;
		dz_ = dir.z;
	}

	void CSObject::SetDirection(float x, float y, float z)
	{
		dx_ = x;
		dy_ = y;
		dz_ = z;
	}
	
	
	//moves object to another position
	void CSObject:: MoveTo(CSPOINT pos)
	{
		x_ = pos.x;
		y_ = pos.y;
		z_ = pos.z;
	}

	void CSObject::MoveTo(float x, float y, float z)
	{
		x_ = x;
		y_ = y;
		z_ = z;
	}


	// gets its model's handel;
	HMODLE CSObject::GetModelHandle()
	{
		return hModel_;
	}

	// sets its model's handel;
	void CSObject::SetModelHandle(HMODEL hModel)
	{
		hModel_ = hModel;
	}
	
}