#pragma once
#include "CSObject.h"
namespace cs
{
	class CSWeapon :public CSObject
	{
	public:
		CSWeapon();
		~CSWeapon();

	private:
		uint price;
		float weight;


	};

	class CSGun :public CSWeapon
	{
	public:
		CSGun();
		~CSGun();
	private:
		uint bulletCount_;
		uint clipCount_;
		float range_;
		float fireRate_;
		float damage_;
		float accuracy_;
	public:
		uint GetBulletCount();
		uint GetClipCount();
		float GetRange();
		float GetFireRate()
		float GetDamage();
		float GetAccuracy();

	};

	class CSKnief :public CSWeapon
	{
	public:
		CSKnief();
		~CSKnief();
	private:
		float range_;
		float damage_;
		float accuracy_;
		float attackSpeed;
	public:
		float GetRange();
		float GetDamage();
		float GetAccuracy();
		float GetAttackSpeed();

	};
	class CSArmer : public CSWeapon
	{
	public:
		CSArmer();
		~CSArmer();

	private:

	};
}
