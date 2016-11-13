#pragma once
#include <d3d9.h>
#include <d3dx9.h>


namespace cs
{
	/*
	*defines resource handle
	*/
	typedef unsigned int HMODEL; 
	typedef unsigned int HWEAPON;
	typedef unsigned int HGUN;
	typedef unsigned int HSOUND;
	typedef unsigned int HICON;
	typedef unsigned int HBITMAP;
	typedef unsigned int HMESH;
	typedef unsigned int HLIGHT;
	typedef unsigned int HMATERIAL;


	/*
	*defines some types in D3DX Structures
	*/

	typedef unsigned int uint;

	typedef D3DXVECTOR3 CSPOINT;
	typedef D3DXVECTOR3 CSVECTOR3;

	/*
	*Directx 游戏开发指南：p63, define.h
	*/
	#define CS_INVALID -1
	#define CS_OK 1
	#define CS_FAIL 0
	typedef long VertexType;
	enum PrimitiveType
	{
		NULL_TYPE,
		POINT_LIST,
		TRIANGLE_LIST,
		TRIANGLE_STRIP,
		TRIANGLE_FAN,
		LINE_LIST,
		LINE_STRIP
	};
#define CSCOLOR_ARGB(a, r, g, b) ((unsigned long)((((a)&0xff)<<24)|\
								  (((r)&0xff)<<16)|(((g)&0xff)<<8)|\
								  ((b)&0xff)))
	

}
