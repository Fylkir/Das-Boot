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

private:
	int _scoreGain;
	std::list<RiverSegment> _rivSeg_l;
	std::list<Boat> _boats_l;
	std::list<Torpedo> _torpedos_l;
	std::list<Fuel> _fuel_l;
	std::list<Boat>::iterator _boats_it;
	std::list<RiverSegment>::iterator _rivSeg_it;
	std::list<Torpedo>::iterator _torpedos_it;
	std::list<Fuel>::iterator _fuel_it;


public:
	River();
	~River();
	void Update(const float& time);
	void Render() override;
	void CheckHits(PlayerBoat& pB) override;
	void CheckShots(std::list<Torpedo>& t, std::list<Torpedo>::iterator& it);
	void Reset();
	int Refuel(PlayerBoat& pB);
	int GainScore();
	void InsertTorpedo(float x, float y, float& time);
};

