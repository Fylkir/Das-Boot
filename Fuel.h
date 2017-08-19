#pragma once
#include "NonPlayableObject.h"
class Fuel :
	public NonPlayableObject
{
public:
	static Texture* tex;
	bool Shot;
	bool Hit;

	Fuel(float x, float y, float t0) { _x = x; _x0 = x; _y = y; _y0 = y; _t0 = t0; Shot = false; Hit = false;
	};
	~Fuel();

	bool IsHit(PlayerBoat* pB);
	void IsShot(std::list<Torpedo*>& t, std::list<Torpedo*>::iterator& it);
	void Render() override;

};

