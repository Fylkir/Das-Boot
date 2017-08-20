#pragma once
#include "NonPlayableObject.h"
#include "PlayerBoat.h"
#include "Torpedo.h"
#include <list>
#include <algorithm>
class RiverSegment : public NonPlayableObject
{
	float _x_bl, _x_br, _x_tl, _x_tr, _span;
public:
	RiverSegment(float xbl, float xbr, float xtl, float xtr, float ymid, float time);
	~RiverSegment();


	void Update(const float& time);
	void Render();
	void CheckHits(PlayerBoat& pB);
	void CheckShots(std::list<Torpedo>& t, std::list<Torpedo>::iterator& it);
	float getLeftBank();
	float getRightBank();
	float getSpan();
};

