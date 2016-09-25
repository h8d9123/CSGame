#pragma once
#include <d3d.h>
#include <d3dx9.h>
namespace cs
{
	
	class CSMaterial
	{
	public:
		CSMaterial();
		~CSMaterial();
	public:
		void SetMaterial(LPDIRECT3DDEVICE9 pD3DDevice);
	private:
		/**
		*diffuse:漫反射光系数,
		*ambient:环境光系数, 
		*specular:镜面反射光系数
		*emissive:自发光反射系数，不参与光照计算
		*power : 镜面反射指数
		*计算公式：
		*I_ambient:只有颜色，没有位置和方向的特征，环境光数量恒定
		*I_diffuse = diffuse_ * I_light * cos(theta);
		*I_specular = specular * I_light * (cos(fai))^power;
		*I_emissive = emissive;不参与光照计算
		*I_total = I_ambient + I_diffusse + I_diffuse + I_emissive
		*ps:D3DColorValue 的成员，r,g,b,分别代表对相应演示的反射系数
		*/
		D3DCOLORVALUE diffuse_;
		D3DCOLORVALUE ambient_;
		D3DCOLORVALUE specular;
		D3DCOLORVALUE Emissive;
		float power;

	};

	CSMaterial::CSMaterial()
	{
	}

	CSMaterial::~CSMaterial()
	{
	}
}