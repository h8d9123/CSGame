#pragma once
#include<cmath>
#include<assert.h>
namespace cs {
	class CSVector3;
}
class CSVector3f
{
	typedef float T;
	typedef CSVector3f SelfType
public:
	//Holds value along x, y, z axis;
	T x;
	T y;
	T z;
private:
	//padding to ensure 4-word alignment
	T pad;
public:
	CSVector3() :x(0), y(0), z(0) {}
	CSVector3(const T x, const T y, const T z) :x(x), y(y), z(z) {}
	// invert the vecort's direction
	void invert()
	{
		x = -x;
		y = -y;
		z = -z;
	}
	T magnitude() const
	{
		//retunr double
		return sqrtf(x*x + y*y + z*z);
	}
	T normalize() const
	{
		//retunr double
		T l = magnitude();
		if (l > 0)
		{
			x /= l;
			y /= l;
			z /= l;
		}
	}
	void operator*=(const T k)
	{
		x *= k;
		y *= k;
		z *= k;
	}
	void operator*=(const SelfType v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
	}
	void operator+=(const T k)
	{
		x += k;
		y += k;
		z += k;
	}
	void operator+=(const SelfType v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}
	void operator-=(const T k)
	{
		x -= k;
		y -= k;
		z -= k;
	}
	void operator-=(const T v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
	void operator/=(const T k)
	{
		assert(k);
		x /= k;
		y /= k;
		z /= k;
	}
	//+,-,*,/
	SelfType operator*(const T k) const
	{
		return SelfType(x*k, y*k, z*k);
	}
	SelfType operator*(const SelfType v) const
	{
		return SelfType(x*v.x, y*v.y, z*v.z);
	}
	SelfType operator-(const T k) const
	{
		return SelfType(x-k, y-k, z-k);
	}
	SelfType operator-(const SelfType v) const
	{
		return SelfType(x-v.x, y-v.y, z-v.z);
	}
	SelfType operator+(const T k) const
	{
		return SelfType(x+k, y+k, z+k);
	}
	SelfType operator+(const SelfType v) const
	{
		return SelfType(x+v.x, y+v.y, z+v.z);
	}
	SelfType operator/(const T k) const
	{
		assert(k);
		return SelfType(x/k, y/k, z/k);
	}
	
	
};