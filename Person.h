#pragma once
#include "CSObject.h"

namespace cs
{
	class Person:public CSObject
	{
	public:
		Person CSObject();
		~Person CSObject();

	private:
		int HP_;
		int money_;
	public:
		int GetHP();
		int GetMoney();
	protected:
		void SetMoney(int money);
		void SetHP(int HP);	
	};
}
