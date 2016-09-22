#pragma once
namespace cs
{
	union _CSPoint
	{
		float pos[3];
		struct 
		{
			float x;
			float y;
			float z;
		};
	}CSPoint;

	union _CSMatrix4
	{
		struct 
		{
			float _11, _12, _13, _14;
			float _21, _22, _23, _24;
			float _31, _32, _33, _34;
			float _41, _42, _43, _44;
		};
		float m[4][4]
	}CSMatrix4;

	union _CSMatrix3
	{
		struct
		{
			float _11, _12, _13;
			float _21, _22, _23;
			float _31, _32, _33;
	
		};
		
		float m[3][3];
	}CSMatrix3;
}
