每一个文件为单独的测试文件，修改源文件的#include，或者copy到csgame/src目录，直接运行


修改部分
1.创建Font,和CSText对象
2.显示字体：text.DrawText(_T("hello"));


VOID Render()
{
	//创建Font,和CSText对象

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