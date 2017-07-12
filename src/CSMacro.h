#pragma once
namespace cs
{
#define ADD_GET(type, member) type Get##member(){return this->member;};
#define ADD_SET(type, member) type Set##member(){this->member = member;};
#define ADD_GET_SET(type, member) ADD_GET(type,member);ADD_SET(type,member);
#define V_RETURN(exptr) {HRESULT hr=exptr;if (FAILED(hr)) return hr;};
#define SAFE_RELEASE(p) {if(p) {(p)->Release();(p)=nullptr;}};
#define SAFE_DELETE() {if(p){delete  (p);(p)=nullptr}};
#define SAFE_DELETE_ARRAY {if(p){delete[] (p);(p)=nullptr;}};
}