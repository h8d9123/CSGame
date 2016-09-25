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
		*diffuse:�������ϵ��,
		*ambient:������ϵ��, 
		*specular:���淴���ϵ��
		*emissive:�Է��ⷴ��ϵ������������ռ���
		*power : ���淴��ָ��
		*���㹫ʽ��
		*I_ambient:ֻ����ɫ��û��λ�úͷ���������������������㶨
		*I_diffuse = diffuse_ * I_light * cos(theta);
		*I_specular = specular * I_light * (cos(fai))^power;
		*I_emissive = emissive;��������ռ���
		*I_total = I_ambient + I_diffusse + I_diffuse + I_emissive
		*ps:D3DColorValue �ĳ�Ա��r,g,b,�ֱ�������Ӧ��ʾ�ķ���ϵ��
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