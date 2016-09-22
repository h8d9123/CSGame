#pragma once
namespace cs
{
	union CSPoint
	{
		float pos[3];
		struct 
		{
			float x;
			float y;
			float z;
		};
	}CSPoint;
}
