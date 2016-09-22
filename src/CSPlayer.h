#pragma once
#include "CSObject.h"
#include "CSMacro.h"
#include "CSWeapon.h"
namespace cs
{
	class CSPlayer:public CSObject
	{
	public:
		CSPlayer();
		~CSPlayer();

	private:
		int HP_;
		int money_;
		float speed_;

	public:
		int GetHP();
		int GetMoney();
		int GetWeapon();
		int Move
	protected:
		void SetMoney(int money);
		void SetHP(int HP);	
	};

}
