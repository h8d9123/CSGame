ÿһ���ļ�Ϊ�����Ĳ����ļ����޸�Դ�ļ���#include������copy��csgame/srcĿ¼��ֱ������


�޸Ĳ���
1.����Font,��CSText����
2.��ʾ���壺text.DrawText(_T("hello"));


VOID Render()
{
	//����Font,��CSText����

	cs::CSFont font(g_pd3dDevice);
	cs::CSText text(&font);


	if (NULL == g_pd3dDevice)
		return;

	// Clear the backbuffer to a blue color
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		// Rendering of scene objects can happen here
		text.DrawText(_T("hello"));

		// End the scene
		g_pd3dDevice->EndScene();
	}

	// Present the backbuffer contents to the display
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}