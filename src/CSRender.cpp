#include "CSRender.h"
bool CreateD3DRender(CSRenderInterface **pObj)
{
	if (!*pObj)
		*pObj = new CSD3DRender;
	else
		return false;
	return true;
}

CSD3DRender::CSD3DRender()
{
	m_d3d = nullptr;
	m_device = nullptr;
	m_isRenderingScence = false;
	m_numStaticBuffers = 0;
	m_activeStaticBuffers = CS_INVALID;
}
CSD3DRender::~CSD3DRender()
{
	Shutdown();
}

bool CSD3DRender::Initialize(int width, int height, HWND mainWin, bool fullscreen)
{
	Shutdown();
	m_mainHandle = mainWin;
	m_screenHeight = height;
	m_screenWidth = width;
	if (!m_mainHandle) return false;

	m_fullscreen = fullscreen;
	D3DDISPLAYMODE mode;
	D3DCAPS9 caps;
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	m_d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (!m_d3d) return false;
	
	if (FAILED(m_d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,
		&mode))) return false;
	if (FAILED(m_d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps)))
		return false;
	//选择硬件处理还是软件方式处理
	DWORD processing = 0;
	if (caps.VertexProcessingCaps != 0)
	{
		processing = D3DCREATE_HARDWARE_VERTEXPROCESSING |
			D3DCREATE_PUREDEVICE;
	}
	else
	{
		processing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}
	// initilize D3DPRESENT_PARAMETERS object ,d3dpp
	if (m_fullscreen)
	{
		d3dpp.FullScreen_RefreshRateInHz = mode.RefreshRate;
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	}
	else
	{
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	}

	d3dpp.Windowed = !m_fullscreen;
	d3dpp.BackBufferWidth = m_screenWidth;
	d3dpp.BackBufferHeight = m_screenHeight;
	d3dpp.hDeviceWindow = m_mainHandle;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = mode.Format;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	//create device
	if (FAILED(m_d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL, m_mainHandle, processing, &d3dpp, &m_device)))
	{
		return false;
	}

	if (m_device == NULL) return false;
	
	OneTimeInit();
	return true;
}

void CSD3DRender::OneTimeInit()
{
	if (!m_device)return;
	//不使用灯光
	m_device->SetRenderState(D3DRS_LIGHTING, FALSE);
	m_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	//设置透视投影矩阵
	SetProjectionMatrix(D3DX_PI / 4.0, 0.1f, 100.f);
}

void CSD3DRender::Shutdown()
{
	// 清空顶点缓存和索引缓存
	for (int s = 0; s < m_numStaticBuffers; s++)
	{
		if (m_staticBufferList[s].vbPtr)
		{
			m_staticBufferList[s].vbPtr->Release();
			m_staticBufferList[s].vbPtr = nullptr;
		}
		if (m_staticBufferList[s].ibPtr)
		{
			m_staticBufferList[s].ibPtr->Release();
			m_staticBufferList[s].ibPtr = nullptr;
		}
	}
	m_numStaticBuffers = 0;
	
	// 删除静态缓存列表
	if (m_staticBufferList)
	{
		delete[] m_staticBufferList;
		m_staticBufferList = nullptr;
	}
	//释放direct 3D ,和Device 对象
	if (m_device) m_device->Release();
	if (m_d3d) m_d3d->Release();

	m_device = nullptr;
	m_d3d = nullptr;
}

void CSD3DRender::SetClearColor(float r, float g, float b)
{
	m_color = D3DCOLOR_COLORVALUE(r, g, b, 1.0f);
}

void CSD3DRender::StartRender(bool bColor, bool bDepth, bool bStencil)
{
	//清空缓存
	if (!m_device)return;
	unsigned int buffers = 0;
	if (bColor) buffers |= D3DCLEAR_TARGET;
	if (bDepth) buffers |= D3DCLEAR_ZBUFFER;
	if (bStencil) buffers |= D3DCLEAR_STENCIL;
	//开始渲染场景
	if (FAILED(m_device->BeginScene())) return;
	//正在渲染
	m_isRenderingScence = true;

}

void CSD3DRender::ClearBuffers(bool bColor, bool bDepth, bool bStencil)
{
	//清空缓存
	if (!m_device)return;
	unsigned int buffers = 0;
	if (bColor) buffers |= D3DCLEAR_TARGET;
	if (bDepth) buffers |= D3DCLEAR_ZBUFFER;
	if (bStencil) buffers |= D3DCLEAR_STENCIL;

	//先关闭渲染，再清空，清空后在继续渲染
	if (m_isRenderingScence) m_device->EndScene();
	if (FAILED(m_device->Clear(0, NULL, buffers, m_color, 1, 0)))
		return;
	if (m_isRenderingScence)
	{
		if (FAILED(m_device->BeginScene())) return;
	}
}

void CSD3DRender::EndRender()
{
	if (!m_device)return;
	m_device->EndScene();
	m_device->Present(NULL, NULL, NULL, NULL);
	m_isRenderingScence = false;

}

void CSD3DRender::SetProjectionMatrix(float fv, float nearPos, float farPos)
{
	if (!m_device) return;
	D3DXMATRIX projectionMatrix;
	//得到透视投影矩阵
	D3DXMatrixPerspectiveFovLH(&projectionMatrix,
		fv, (float)m_screenWidth / (float)m_screenHeight, nearPos, farPos);
	//设置透视投影矩阵
	m_device->SetTransform(D3DTS_PROJECTION, &projectionMatrix);
}
void CSD3DRender::SetOrthoMatrix(float nearPos, float farPos)
{
	if (!m_device) return;
	D3DXMATRIX ortho;
	//得到正交投影矩阵
	D3DXMatrixOrthoLH(&ortho, (float)m_screenWidth,
		(float)m_screenHeight, nearPos, farPos);
	//设置正交投影矩阵
	m_device->SetTransform(D3DTS_PROJECTION, &ortho);

}

int CSD3DRender::CreateStaticBuffer(cs::VertexType vType, cs::PrimitiveType primType,
	unsigned int numVertices, unsigned int numIndices,
	int stride, void **data, unsigned int *indeces,
	unsigned int *staticId)
{
	void *ptr;
	int index = m_numStaticBuffers;
	//分配 m_numstaticbuffers 个静态缓存对象
	if (!m_staticBufferList)
	{
		m_staticBufferList = new stD3DStaticBuffer[1];
		if (!m_staticBufferList) return CS_FAIL;
	}
	else
	{
		stD3DStaticBuffer *tmp;
		tmp = new stD3DStaticBuffer[m_numStaticBuffers + 1];
		memcpy(tmp, m_staticBufferList, sizeof(stD3DStaticBuffer)*m_numStaticBuffers);
		m_staticBufferList = tmp;

	}

	m_staticBufferList[index].numVertices = numVertices;
	m_staticBufferList[index].numIndices = numIndices;
	m_staticBufferList[index].stride = stride;
	m_staticBufferList[index].primitiveType =primType ;
	m_staticBufferList[index].fvf = vType;

	if (numIndices > 0)
	{
		if (FAILED(m_device->CreateIndexBuffer(sizeof(unsigned int) * numIndices,
			D3DUSAGE_WRITEONLY, D3DFMT_INDEX16,
			D3DPOOL_DEFAULT, &m_staticBufferList[index].ibPtr,NULL))) 
			return CS_FAIL;

		if (FAILED(m_staticBufferList[index].ibPtr->Lock(0, 0,
			(void**)&ptr, 0))) return CS_FAIL;

		memcpy(ptr, indeces, sizeof(unsigned int)*numIndices);

		m_staticBufferList[index].ibPtr->Unlock();
	
	}
	else
	{
		m_staticBufferList[index].ibPtr = nullptr;
	}

	if (FAILED(m_device->CreateVertexBuffer(numVertices * stride,
		D3DUSAGE_WRITEONLY, m_staticBufferList[index].fvf, D3DPOOL_DEFAULT,
		&m_staticBufferList[index].vbPtr, NULL)))
		return CS_FAIL;
	
	if (FAILED(m_staticBufferList[index].vbPtr->Lock(0, 0,
		(void **)&ptr, 0)))
		return CS_FAIL;

	memcpy(ptr, data, numVertices*stride);
	m_staticBufferList[index].vbPtr->Unlock();

	*staticId = m_numStaticBuffers;
	m_numStaticBuffers++;
	return CS_OK;
}

int CSD3DRender::Render(int staticId)
{
	using namespace cs;
	if (staticId >= m_numStaticBuffers)return CS_FAIL;

	if (m_activeStaticBuffers != staticId)
	{
		if (m_staticBufferList[staticId].ibPtr != NULL)
			m_device->SetIndices(m_staticBufferList[staticId].ibPtr);
		
		m_device->SetStreamSource(0,
			m_staticBufferList[staticId].vbPtr, 0,
			m_staticBufferList[staticId].stride);

		m_device->SetFVF(m_staticBufferList[staticId].fvf);
		m_activeStaticBuffers = staticId;
	}

	if (m_staticBufferList[staticId].ibPtr != NULL)
	{
		
		switch (m_staticBufferList[staticId].primitiveType)
		{
		case POINT_LIST:
			if (FAILED(m_device->DrawPrimitive(D3DPT_POINTLIST,
				0, m_staticBufferList[staticId].numVertices)))
				return CS_FAIL;
			break;
		case TRIANGLE_LIST:
			if (FAILED(m_device->DrawIndexedPrimitive(
				D3DPT_TRIANGLELIST, 0, 0,
				m_staticBufferList[staticId].numVertices / 3,
				0, m_staticBufferList[staticId].numIndices)))
				return CS_FAIL;
			break;
		case TRIANGLE_STRIP:
			if (FAILED(m_device->DrawIndexedPrimitive(
				D3DPT_TRIANGLESTRIP, 0, 0,
				m_staticBufferList[staticId].numVertices / 2,
				0, m_staticBufferList[staticId].numIndices)))
				return CS_FAIL;
			break;
		case TRIANGLE_FAN:
			if (FAILED(m_device->DrawIndexedPrimitive(
				D3DPT_TRIANGLEFAN, 0, 0,
				m_staticBufferList[staticId].numVertices / 2,
				0, m_staticBufferList[staticId].numIndices)))
				return CS_FAIL;
			break;
		case LINE_LIST:
			if (FAILED(m_device->DrawIndexedPrimitive(
				D3DPT_LINELIST, 0, 0,
				m_staticBufferList[staticId].numVertices / 2,
				0, m_staticBufferList[staticId].numIndices)))
				return CS_FAIL;
			break;
		case LINE_STRIP:
			if (FAILED(m_device->DrawIndexedPrimitive(
				D3DPT_LINESTRIP, 0, 0,
				m_staticBufferList[staticId].numVertices,
				0, m_staticBufferList[staticId].numIndices)))
				return CS_FAIL;
			break;

		default:
			return CS_FAIL;
			break;
		}
	}
	else
	{
		switch (m_staticBufferList[staticId].primitiveType)
		{
		case POINT_LIST:
			if(FAILED(m_device->DrawPrimitive(
				D3DPT_POINTLIST, 0,
				m_staticBufferList[staticId].numVertices)))
				return CS_FAIL;
		case TRIANGLE_LIST:
			if (FAILED(m_device->DrawPrimitive(
				D3DPT_TRIANGLELIST, 0,
				(int)m_staticBufferList[staticId].numVertices / 3)))
				return CS_FAIL;
			break;
		case TRIANGLE_STRIP:
			if (FAILED(m_device->DrawPrimitive(
				D3DPT_TRIANGLESTRIP, 0,
				(int)m_staticBufferList[staticId].numVertices / 2)))
				return CS_FAIL;
			break;
		case TRIANGLE_FAN:
			if (FAILED(m_device->DrawPrimitive(
				D3DPT_TRIANGLEFAN, 0,
				(int)m_staticBufferList[staticId].numVertices / 2)))
				return CS_FAIL;
			break;
		case LINE_LIST:
			if (FAILED(m_device->DrawPrimitive(
				D3DPT_LINELIST, 0,
				(int)m_staticBufferList[staticId].numVertices / 2)))
				return CS_FAIL;
			break;
		case LINE_STRIP:
			if (FAILED(m_device->DrawPrimitive(
				D3DPT_LINESTRIP, 0,
				(int)m_staticBufferList[staticId].numVertices)))
				return CS_FAIL;
			break;	

		default:
			break;
		}
	}
	return CS_OK;
}
