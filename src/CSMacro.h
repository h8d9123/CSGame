#pragma once
namespace cs
{
#define ADD_GET(type, name, member) type Get##name(){return this->member;};
#define ADD_SET(type, name, member) void Set##name(type member){this->member = member;};
#define ADD_GET_SET(type, name, member) ADD_GET(type,name,member);ADD_SET(type,name, member);

#define V_RETURN(exptr) {HRESULT hr=exptr;if (FAILED(hr)) return hr;};
#define SAFE_RELEASE(p) {if(p) {(p)->Release();(p)=nullptr;}};
#define SAFE_DELETE() {if(p){delete  (p);(p)=nullptr}};
#define SAFE_DELETE_ARRAY {if(p){delete[] (p);(p)=nullptr;}};
}