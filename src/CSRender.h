#pragma once
#include "CSRenderInterface.h"
#include<d3d9.h>
#include<d3dx9.h>
#include"CSType.h"

typedef long VertexType;
struct stD3DStaticBuffer
{
	stD3DStaticBuffer():vbPtr(0), ibPtr(0), numVertices(0),
						numIndices(0), stride(0), fvf(0),
						primitiveType(cs::NULL_TYPE){}

	LPDIRECT3DVERTEXBUFFER9 vbPtr;
	LPDIRECT3DINDEXBUFFER9 ibPtr;
	int numVertices;
	int numIndices;
	int stride;
	unsigned long fvf;
	cs::PrimitiveType primitiveType;
};
bool CreateD3DRender(CSRenderInterface **pObj);
class CSD3DRender:public CSRenderInterface
{
public:
	CSD3DRender();
	~CSD3DRender();
	//����Direct 3D ����Ⱦϵͳ
	virtual bool Initialize(int width, int height, HWND mainWin, bool fullscreen);
	//ֻ��Ҫ��ʼ��һ�μ���
	virtual void OneTimeInit();
	//�����Ⱦϵͳ
	virtual void Shutdown();
	//���ú�̨�������ɫ
	virtual void SetClearColor(float r, float g, float b);
	//�����³���
	virtual void StartRender(bool bColor, bool bDepth, bool bStencil);
	//����Ⱦǰ�����֮�䣬�������
	virtual void ClearBuffers(bool bColor, bool bDepth, bool bStencil);
	//������ǰ������Ⱦ
	virtual void EndRender();
	//��������ͶӰ����͸��ͶӰ��
	virtual void SetProjectionMatrix(float fov, float nearPos, float farPos);
	//��������ͶӰ����ƽ��ͶӰ��
	virtual void SetOrthoMatrix(float nearPos, float farPos);
	//������̬���㻺��
	virtual int CreateStaticBuffer(VertexType, cs::PrimitiveType,
		unsigned int numVertices, unsigned int numIndices,
		int stride, void **data, unsigned int *indeces,
		unsigned int *staticId);
	//�������������Ⱦ����Ļ
	virtual int Render(int staticId);

private:
	D3DCOLOR m_color;
	LPDIRECT3D9 m_d3d;
	LPDIRECT3DDEVICE9 m_device;
	bool m_isRenderingScence;

	stD3DStaticBuffer *m_staticBufferList;
	int m_numStaticBuffers;
	int m_activeStaticBuffers;

};