#pragma once
#include <d3d9.h>
#include <d3dx9.h>
namespace cs
{
	class CSLight
	{
	private:
		D3DLIGHTTYPE type_;
		D3DCOLORVALUE diffuse_;
		D3DCOLORVALUE specular_;
		D3DCOLORVALUE ambient_;
	public:
		void SetLight(LPDIRECT3DDEVICE9 pD3DDevice, DWORD index);
		void LightEnable(LPDIRECT3DDEVICE9 pD3DDevice, DWORD index);
	};

	class CSSpotLight :public CSLight
	{
	private:
		D3DXVECTOR3 *position_;
		D3DXVECTOR3 *direction_;
		/**
		*fallOff 是内外锥体衰减系数
		*theta 是内锥体角度
		*phi 是外椎体角度
		*/
		float fallOff_;
		float theata_;
		float phi_;
		float range_;
		/**
		*attenuation 是距离衰减系数，控制光强如何向最远距离衰减，最远距离 = range
		*atten = 1/(attenuation0 + attenuation2 * d + attenuation2 *d^2)
		* d 是物体顶点和光源之间的距离
		*/
		float attenuation0;
		float attenuation1;
		float attenuation2;
	};

	/**
	*点光源特点：没有方向，向所有方向发射，随距离衰减
	*/
	class CSPointLight:public CSLight
	{
	public:
		CSSpotLight();
		~CSSpotLight();

	private:
		D3DXVECTOR3 *position_;
		//range 是可以照到的最远距离
		float range_;
		/**
		*attenuation 是距离衰减系数，控制光强如何向最远距离衰减，最远距离 = range
		*atten = 1/(attenuation0 + attenuation2 * d + attenuation2 *d^2)
		* d 是物体顶点和光源之间的距离
		*/
		float attenuation0;
		float attenuation1;
		float attenuation2;

	};

	/*
	*方向光特点：不会衰减，没有位置，计算量小
	*/
	class CSDirectionLight :public CSLight
	{
	private:
		D3DXVECTOR3 *direction_;

	};
	
}
