#pragma once
#include"CSType.h"
namespace cs { class CSRenderInterface; }
class CSRenderInterface
{
public:
	CSRenderInterface() :m_screenWidth(0),
		m_screenHeight(0), m_near(0), m_far(0){}
	virtual ~CSRenderInterface() {}
	//设置Direct 3D 的渲染系统
	virtual bool Initialize(int width, int height, HWND mainWin, bool fullscreen) = 0;
	//只需要初始化一次即可
	virtual void OneTimeInit() = 0;
	//清除渲染系统
	virtual void Shutdown() = 0;
	//设置后台缓存的颜色
	virtual void SetClearColor(float r, float g, float b) = 0;
	//启动新场景
	virtual void StartRender(bool bColor, bool bDepth, bool bStencil) = 0;
	//在渲染前后或者之间，清除缓存
	virtual void ClearBuffers(bool bColor, bool bDepth, bool bStencil) = 0;
	//结束当前场景渲染
	virtual void EndRender() = 0;
	//设置立体投影矩阵（透视投影）
	virtual void SetProjectionMatrix(float fov, float near, float far) = 0;
	//设置正交投影矩阵（平行投影）
	virtual void SetOrthoMatrix(float near, float far) = 0;
	//创建静态顶点缓存
	virtual int CreateStaticBuffer(cs::VertexType, cs::PrimitiveType,
		unsigned int numVertices, unsigned int numIndices,
		int stride, void **data, unsigned int *indeces,
		unsigned int *staticId) = 0;
	//将缓存的内容渲染到屏幕
	virtual int Render( int staticId) = 0;
protected:

	//屏幕的宽度和高度，是否全屏
	int m_screenWidth;
	int m_screenHeight;
	bool m_fullscreen;
	
	//摄像机的远裁面和近裁面
	float m_near;
	float m_far;
	HWND m_mainHandle;


};
