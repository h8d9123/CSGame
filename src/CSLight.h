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
		*fallOff ������׶��˥��ϵ��
		*theta ����׶��Ƕ�
		*phi ����׵��Ƕ�
		*/
		float fallOff_;
		float theata_;
		float phi_;
		float range_;
		/**
		*attenuation �Ǿ���˥��ϵ�������ƹ�ǿ�������Զ����˥������Զ���� = range
		*atten = 1/(attenuation0 + attenuation2 * d + attenuation2 *d^2)
		* d �����嶥��͹�Դ֮��ľ���
		*/
		float attenuation0;
		float attenuation1;
		float attenuation2;
	};

	/**
	*���Դ�ص㣺û�з��������з����䣬�����˥��
	*/
	class CSPointLight:public CSLight
	{
	public:
		CSSpotLight();
		~CSSpotLight();

	private:
		D3DXVECTOR3 *position_;
		//range �ǿ����յ�����Զ����
		float range_;
		/**
		*attenuation �Ǿ���˥��ϵ�������ƹ�ǿ�������Զ����˥������Զ���� = range
		*atten = 1/(attenuation0 + attenuation2 * d + attenuation2 *d^2)
		* d �����嶥��͹�Դ֮��ľ���
		*/
		float attenuation0;
		float attenuation1;
		float attenuation2;

	};

	/*
	*������ص㣺����˥����û��λ�ã�������С
	*/
	class CSDirectionLight :public CSLight
	{
	private:
		D3DXVECTOR3 *direction_;

	};
	
}
