#include"CSFont.h"

cs::CSFont::CSFont(LPDIRECT3DDEVICE9 pDevice) :pDevice(pDevice), height(0), width(0), weight(0), mipLevels(0)
, italic(0), charSet(0), outputPrecision(0), quality(0), pitchAndFamily(0),
pFacename(L"Arial"), pFont(nullptr) {
	Init();
};
HRESULT cs::CSFont::Init()
{
	if (nullptr != pDevice) {
		V_RETURN(D3DXCreateFont(pDevice, height, width, weight, mipLevels, italic, charSet, outputPrecision,
			quality, pitchAndFamily, pFacename, &pFont));
	}
	return E_FAIL;
}
void cs::CSFont::Destroy() {
	if (pFont) SAFE_RELEASE(pFont);
}
HRESULT cs::CSFont::UpDate() {
	SAFE_RELEASE(pFont);
	return Init();
}