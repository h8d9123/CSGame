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
	//设置Direct 3D 的渲染系统
	virtual bool Initialize(int width, int height, HWND mainWin, bool fullscreen);
	//只需要初始化一次即可
	virtual void OneTimeInit();
	//清除渲染系统
	virtual void Shutdown();
	//设置后台缓存的颜色
	virtual void SetClearColor(float r, float g, float b);
	//启动新场景
	virtual void StartRender(bool bColor, bool bDepth, bool bStencil);
	//在渲染前后或者之间，清除缓存
	virtual void ClearBuffers(bool bColor, bool bDepth, bool bStencil);
	//结束当前场景渲染
	virtual void EndRender();
	//设置立体投影矩阵（透视投影）
	virtual void SetProjectionMatrix(float fov, float nearPos, float farPos);
	//设置正交投影矩阵（平行投影）
	virtual void SetOrthoMatrix(float nearPos, float farPos);
	//创建静态顶点缓存
	virtual int CreateStaticBuffer(VertexType, cs::PrimitiveType,
		unsigned int numVertices, unsigned int numIndices,
		int stride, void **data, unsigned int *indeces,
		unsigned int *staticId);
	//将缓存的内容渲染到屏幕
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