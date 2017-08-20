#include "River.h"



River::River()
{
	Reset();
}


River::~River()
{
}

void River::Update(const float& time)
{
	/****AKTUALIZACJA POLOZENIA I STANU STATKOW NA RZECE****/
	_scoreGain = 0;
	for (_boats_it = _boats_l.begin(); _boats_it != _boats_l.end(); _boats_it++)
	{
		(*_boats_it).Update(time);
		(*_boats_it).CheckShots(_torpedos_l, _torpedos_it);
	}
	/****AKTUALIZACJA POLOZENIA SEGMENTOW RZEKI ****/
	for (_rivSeg_it = _rivSeg_l.begin(); _rivSeg_it != _rivSeg_l.end(); _rivSeg_it++)
	{
		(*_rivSeg_it).Update(time);
		(*_rivSeg_it).CheckShots(_torpedos_l, _torpedos_it);
	}
	/****AKTUALIZACJA POLOZENIA TORPED****/
	for (_torpedos_it = _torpedos_l.begin(); _torpedos_it != _torpedos_l.end(); _torpedos_it++)
	{
		(*_torpedos_it).Update(time);
	}

	/****AKTUALIZACJA POLOZENIA PALIWA****/
	for (_fuel_it = _fuel_l.begin(); _fuel_it != _fuel_l.end(); _fuel_it++)
	{
		(*_fuel_it).Update(time);
	}

	/****USUWANIE OBIEKTOW WYCHODZACYCH ZA EKRAN I ZESTRZELONYCH****/
	if (_rivSeg_l.back().IsOutOfScreen()) _rivSeg_l.pop_back();

	_boats_l.remove_if([](Boat& b) {return b.IsOutOfScreen() || b.IsShot(); });
	_torpedos_l.remove_if([](Torpedo& t) {return t.IsShot() || t.IsOutOfScreen(); });
	_fuel_l.remove_if([](Fuel& f) {return f.IsShot()|| f.IsOutOfScreen() || f.IsHit(); });
	

	///////////////////////////////////
	// OGARNAC LOSOWANIE
	//////////////////////////////////

	/****DODAWANIE NOWYCH OBIEKTOW PRZED EKRANEM****/
	if (_rivSeg_l.size() < RIV_SEGMENTS) _rivSeg_l.push_front(RiverSegment(_rivSeg_l.front().getLeftBank(), _rivSeg_l.front().getRightBank(), rand() % 11 + _rivSeg_l.front().getLeftBank() - 5, rand() % 11 + _rivSeg_l.front().getRightBank() - 5, _rivSeg_l.front().getY() - 800. / RIV_SEGMENTS, time));
	if ((rand() % 1000)>990) _boats_l.push_back(Boat(_rivSeg_l.front().getX(), _rivSeg_l.front().getY(), rand() % (int)(_rivSeg_l.front().getSpan()/2. - 20), rand() % 20 / 2., time));
	if ((rand() % 1000)>990) _fuel_l.push_back(Fuel(rand() % rand() % (int)(_rivSeg_l.front().getSpan() - 20) + _rivSeg_l.front().getLeftBank() + 10, _rivSeg_l.front().getY(), time));
	

}
void River::Render()
{
	/****RENDERUJ SEGMENTY RZEKI****/
	for (_rivSeg_it = _rivSeg_l.begin(); _rivSeg_it != _rivSeg_l.end(); _rivSeg_it++)
	{
		(*_rivSeg_it).Render();
	}

	/****RENDERUJ LODZIE****/
	for (_boats_it = _boats_l.begin(); _boats_it != _boats_l.end(); _boats_it++)
	{
		(*_boats_it).Render();
	}

	/****RENDERUJ TORPEDY****/
	for (_torpedos_it = _torpedos_l.begin(); _torpedos_it != _torpedos_l.end(); _torpedos_it++)
	{
		(*_torpedos_it).Render();
	}

	/****RENDERUJ PALIWO****/
	for (_fuel_it = _fuel_l.begin(); _fuel_it != _fuel_l.end(); _fuel_it++)
	{
		(*_fuel_it).Render();
	}
}

void River::CheckHits(PlayerBoat& pB)
{


	for (_rivSeg_it = _rivSeg_l.begin(); _rivSeg_it != _rivSeg_l.end(); _rivSeg_it++)
	{
		(*_rivSeg_it).CheckHits(pB);
		if ((*_rivSeg_it).IsHit())
		{
			_isHit = true;
			return;
		}
	}
	
	for (_boats_it = _boats_l.begin(); _boats_it != _boats_l.end(); _boats_it++)
	{
		(*_boats_it).CheckHits(pB);
		if ((*_boats_it).IsHit())
		{
			_isHit = true;
			return;
		}
	}

	for (_fuel_it = _fuel_l.begin(); _fuel_it != _fuel_l.end(); _fuel_it++)
	{
		(*_fuel_it).CheckHits(pB);
	}

	CheckShots(_torpedos_l, _torpedos_it);

}

void River::CheckShots(std::list<Torpedo>& t , std::list<Torpedo>::iterator & it)
{
	for (_rivSeg_it = _rivSeg_l.begin(); _rivSeg_it != _rivSeg_l.end(); _rivSeg_it++)
	{
		(*_rivSeg_it).CheckShots(_torpedos_l, _torpedos_it);
	}

	for (_boats_it = _boats_l.begin(); _boats_it != _boats_l.end(); _boats_it++)
	{
		(*_boats_it).CheckShots(_torpedos_l, _torpedos_it);
	}

	for (_fuel_it = _fuel_l.begin(); _fuel_it != _fuel_l.end(); _fuel_it++)
	{
		(*_fuel_it).CheckShots(_torpedos_l, _torpedos_it);
	}
}

void River::InsertTorpedo(float x, float y, float& time)
{
	_torpedos_l.push_back(Torpedo(x, y, time));
}

void River::Reset()
{
	_rivSeg_l.clear();
	_torpedos_l.clear();
	_boats_l.clear();
	_isHit = false;
	_isShot = false;
	
	float beg = -100.;
	for (int i = 0; i < RIV_SEGMENTS; i++)
	{
		_rivSeg_l.push_back(RiverSegment(200., 600., 200., 600., beg + i * 800 / RIV_SEGMENTS, 0));
	}


}

int River::Refuel(PlayerBoat& pB)
{
	int r = 0;
	for (_fuel_it = _fuel_l.begin(); _fuel_it != _fuel_l.end(); _fuel_it++)
	{
		if((*_fuel_it).IsHit()) r++;
	}

	return FUEL_MULTIPLIER * r;
}

int River::GainScore()
{
	int s = 0;
	for (_boats_it = _boats_l.begin(); _boats_it != _boats_l.end(); _boats_it++)
	{
		if ((*_boats_it).IsShot()) s++;
	}
	return SCORE_MULTIPLIER * s;
}

