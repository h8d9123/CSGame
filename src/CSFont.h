#pragma once
#include<d3dx9.h>
#include<d3dx9core.h>
#include<d3dx9mesh.h>
#include<tchar.h>
#
#include"CSMacro.h"
namespace cs {



	class CSFont {
	protected:
		LPDIRECT3DDEVICE9 pDevice;
		INT height;
		UINT width;
		UINT weight;
		UINT mipLevels;
		BOOL italic;
		DWORD charSet;
		DWORD outputPrecision;
		DWORD quality;
		DWORD pitchAndFamily;
		LPCTSTR pFacename;
		LPD3DXFONT pFont;
	public:
		/*
		CSFont() :pDevice(nullptr), height(0), width(0), weight(0), mipLevels(0)
			, italic(0), charSet(0), outputPrecision(0), quality(0), pitchAndFamily(0),
			pFacename(L"Arial"), pFont(nullptr) {};
		*/

		CSFont(LPDIRECT3DDEVICE9 pDevice);

		HRESULT Init();
		HRESULT UpDate();
		void Destroy();
		//add functions to get or set members;
		ADD_GET_SET(LPDIRECT3DDEVICE9, Device, pDevice);
		ADD_GET_SET(INT, Height, height);
		ADD_GET_SET(UINT, Width, width);
		ADD_GET_SET(UINT, Weight, weight);
		ADD_GET_SET(UINT, MipLevels, mipLevels);
		ADD_GET_SET(bool, Italic, italic);
		ADD_GET_SET(DWORD, CharSet, charSet);
		ADD_GET_SET(DWORD, OutputPrecision, outputPrecision);
		ADD_GET_SET(DWORD, Quality, quality);
		ADD_GET_SET(DWORD, PitchAndFamily, pitchAndFamily);
		ADD_GET_SET(LPCTSTR, PFacename, pFacename);
		ADD_GET(LPD3DXFONT, Instance, pFont);
	};
	class CSText {
	protected:
		CSFont *pfont;
		LPD3DXSPRITE pSprite;
		LPCTSTR pText;
		int count;
		RECT rect;
		DWORD format;
		D3DCOLOR color;
	public:
		ADD_GET_SET(LPD3DXSPRITE,PSprite, pSprite)
		ADD_GET_SET(int, Count, count);
		ADD_GET_SET(DWORD, Format, format);
		ADD_GET_SET(D3DCOLOR, Color,color);

	public:
		CSText(CSFont* pfont) :pfont(pfont), pText(L"Hello"), count(-1), rect({ 0, 0, 600, 20 }), format(DT_TOP | DT_LEFT), color(0xffffffff) {}
		void DrawText(LPCTSTR pText){
			ID3DXFont* font;
			font = pfont->GetInstance();
			font->DrawText(pSprite, pText, count, &rect, format, color);

		}
		void DrawText(LPD3DXSPRITE pSprite, LPCTSTR pText, RECT rect, D3DCOLOR color=0xffffffff) {
			ID3DXFont* font;
			font = pfont->GetInstance();
			font->DrawText(pSprite, pText, count, &rect, format, color);
		}

	};

}