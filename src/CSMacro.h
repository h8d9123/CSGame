#pragma once
namespace cs
{
#define ADD_GET(type, member) type Get##member(){return this->member;};
#define ADD_SET(type, member) type Set##member(){this->member = member;};
#define ADD_GET_SET(type, member) ADD_GET(type,member);ADD_SET(type,member);
}