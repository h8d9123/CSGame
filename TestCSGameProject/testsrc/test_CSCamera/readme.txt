ÿһ���ļ�Ϊ�����Ĳ����ļ����޸�Դ�ļ���#include������copy��csgame/srcĿ¼��ֱ������

1.���� camera
cs::CSCamera g_camera(cs::CSCamera::LANDCAMERA);
2.�������
VOID SetupMatrices()
{
	//------------------------------------------------------
	D3DXVECTOR3 vEyePt1(0.0f, 0.0f, -15.0f);
	D3DXVECTOR3 vLookat1Pt(0.0f, 0.0f, 1.0f);
	D3DXVECTOR3 vUpVec1(0.0f, 1.0f, 0.0f);
	D3DXVECTOR3 vrVec1(1.0f, 0.0f, 0.0f);
	
	g_camera.SetPos(vEyePt1);
	g_camera.SetLookVec(vLookat1Pt);
	g_camera.SetUpVec(vUpVec1);
	g_camera.SetRightVec(vrVec1);
	//�������
	g_camera.Strafe(2.0);
	D3DXMATRIXA16 matView;
	
	g_camera.GetViewMatirx(&matView);
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &matView);
	//-------------------------------------------------------
	D3DXMATRIXA16 matProj;
	D3DXMatrixPerspectiveFovLH(&matProj, D3DX_PI / 4, 1.0f, 1.0f, 100.0f);
	g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}