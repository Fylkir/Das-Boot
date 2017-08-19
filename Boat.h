#pragma once
#include "NonPlayableObject.h"
#include "PlayerBoat.h"
#include "Torpedo.h"
#include <cmath>
#include <list>
#include <algorithm>
class Boat : public NonPlayableObject
{


	float _a, _b; // FUNKCJA RUCHU X = ASIN(BT) + X_0
	
public:
	static Texture* tex;
	bool Shot;

	Boat(float x, float y, float a, float b, float t0);
	~Boat();

	void Move(float time);
	void Update(float& time);
	bool IsHit(PlayerBoat* pB);
	int IsShot(std::list<Torpedo*>& t, std::list<Torpedo*>::iterator& it);
	void Render() override;


};

