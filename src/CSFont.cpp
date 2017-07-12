#include"CSFont.h"

HRESULT cs::CSFont::Init(LPDIRECT3DDEVICE9 device)
{
	if (pFont) SAFE_RELEASE(pFont);
	V_RETURN(D3DXCreateFont(device,height,width,weight,
		mipLevels,italic,charSet,outputPrecision,quality,
		pitchAndFamily, pFacename, &pFont));
	pDevice = device;
	return S_OK;
}
void cs::CSFont::Destroy() {
	if (pFont) SAFE_RELEASE(pFont);
}