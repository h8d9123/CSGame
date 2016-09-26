#pragma once
#include <d3d9.h>
#include <d3dx9.h>
namespace cs
{
	class CSTexture
	{
	public:
		CreateTextureFromFile();

	private:
		LPDIRECT3DDEVICE9 *pDevice;
	};
}
