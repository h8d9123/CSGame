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
		CSGun *pGun_;
		CSKnief *pKnief;
		//other weapon;


	public:
		int GetHP();
		int GetMoney();
		int GetWeapon();
		int MoveTo(CSPoint);
		int MoveTo(x,y,z)
		void SetMoney(int money);
		void SetHP(int HP);	
		void setWeapon();
	};

}
