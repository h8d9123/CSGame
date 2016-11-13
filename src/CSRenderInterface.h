#pragma once
#include"CSType.h"
namespace cs { class CSRenderInterface; }
class CSRenderInterface
{
public:
	CSRenderInterface() :m_screenWidth(0),
		m_screenHeight(0), m_near(0), m_far(0){}
	virtual ~CSRenderInterface() {}
	//����Direct 3D ����Ⱦϵͳ
	virtual bool Initialize(int width, int height, HWND mainWin, bool fullscreen) = 0;
	//ֻ��Ҫ��ʼ��һ�μ���
	virtual void OneTimeInit() = 0;
	//�����Ⱦϵͳ
	virtual void Shutdown() = 0;
	//���ú�̨�������ɫ
	virtual void SetClearColor(float r, float g, float b) = 0;
	//�����³���
	virtual void StartRender(bool bColor, bool bDepth, bool bStencil) = 0;
	//����Ⱦǰ�����֮�䣬�������
	virtual void ClearBuffers(bool bColor, bool bDepth, bool bStencil) = 0;
	//������ǰ������Ⱦ
	virtual void EndRender() = 0;
	//��������ͶӰ����͸��ͶӰ��
	virtual void SetProjectionMatrix(float fov, float near, float far) = 0;
	//��������ͶӰ����ƽ��ͶӰ��
	virtual void SetOrthoMatrix(float near, float far) = 0;
	//������̬���㻺��
	virtual int CreateStaticBuffer(cs::VertexType, cs::PrimitiveType,
		unsigned int numVertices, unsigned int numIndices,
		int stride, void **data, unsigned int *indeces,
		unsigned int *staticId) = 0;
	//�������������Ⱦ����Ļ
	virtual int Render( int staticId) = 0;
protected:

	//��Ļ�Ŀ�Ⱥ͸߶ȣ��Ƿ�ȫ��
	int m_screenWidth;
	int m_screenHeight;
	bool m_fullscreen;
	
	//�������Զ����ͽ�����
	float m_near;
	float m_far;
	HWND m_mainHandle;


};
