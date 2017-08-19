#pragma once
#include "NonPlayableObject.h"
#include "Boat.h"
#include "RiverSegment.h"
#include "Fuel.h"
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include "Constants.h"
class River :
	public NonPlayableObject
{
	int scoreGain;

	std::list<RiverSegment*> rivSeg;
	std::list<Boat*> boats;
	std::list<Torpedo*> torpedos;
	std::list<Fuel*> fuel;
	std::list<Boat*>::iterator itBoat;
	std::list<RiverSegment*>::iterator itSeg;
	std::list<Torpedo*>::iterator itTorp;
	std::list<Fuel*>::iterator itFuel;


public:
	River();
	~River();
	void Update(float& time);
	void Render() override;
	bool IsHit(PlayerBoat* pB) override;
	//void IsShot();
	int Refuel(PlayerBoat* pB);
	int GainScore();
	void InsertTorpedo(float x, float y, float& time);
};

