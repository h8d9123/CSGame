#pragma once
#include"CSVector.h"
namespace cs
{
	class CSParticle;
	
}

class CSParticle
{
	typedef CSVector3f CSVector3;
	typedef float real;
public:
	CSParticle();
	~CSParticle();
	void SetMass(real m) { assert(m); inverseMass = 1.0 / m; }
	real getMass() { return 1.0/inverseMass }
	void SetInverseMass(real m) { inverseMass = m; }
	real getInverseMass() { return inverseMass; }

public:
	
	CSVector3 position;
	CSVector3 velocity;
	CSVector3 acceleration;
	real inverseMass;
};
