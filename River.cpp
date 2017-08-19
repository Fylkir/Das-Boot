#include "River.h"



River::River()
{
	float beg = -100.;
	for (int i = 0; i < RIV_SEGMENTS; i++)
	{
		rivSeg.push_back(new RiverSegment(200., 600., 200., 600., beg + i*800/RIV_SEGMENTS, 0));
	}
}


River::~River()
{
}

void River::Update(float& time)
{
	/****AKTUALIZACJA POLOZENIA I STANU STATKOW NA RZECE****/
	scoreGain = 0;
	for (itBoat = boats.begin(); itBoat != boats.end(); itBoat++)
	{
		(*itBoat)->Update(time);
		scoreGain += (*itBoat)->IsShot(torpedos, itTorp);

	}
	/****AKTUALIZACJA POLOZENIA SEGMENTOW RZEKI I STRZALOW W NIE****/
	for (itSeg = rivSeg.begin(); itSeg != rivSeg.end(); itSeg++)
	{
		(*itSeg)->Update(time);
		(*itSeg)->IsShot(torpedos, itTorp);
	}
	/****AKTUALIZACJA POLOZENIA TORPED****/
	for (itTorp = torpedos.begin(); itTorp != torpedos.end(); itTorp++)
	{
		(*itTorp)->Update(time);
	}

	/****AKTUALIZACJA POLOZENIA PALIWA****/
	for (itFuel = fuel.begin(); itFuel != fuel.end(); itFuel++)
	{
		(*itFuel)->Update(time);
	}

	/****USUWANIE OBIEKTOW WYCHODZACYCH ZA EKRAN I ZESTRZELONYCH****/
	if (rivSeg.back()->IsOutOfScreen()) rivSeg.pop_back();

	boats.remove_if([](Boat* b) {return b->IsOutOfScreen()||b->Shot; });


	torpedos.remove_if([](Torpedo* t) {return t->Shot || t->IsOutOfScreen(); });
	fuel.remove_if([](Fuel* f) {return f->Shot || f->IsOutOfScreen() || f->Hit; });
	

	/****DODAWANIE NOWYCH OBIEKTOW PRZED EKRANEM****/
	if (rivSeg.size() < RIV_SEGMENTS) rivSeg.push_front(new RiverSegment(rivSeg.front()->getLeftBank(), rivSeg.front()->getRightBank(), rand() % 11 + rivSeg.front()->getLeftBank() - 5, rand() % 11 + rivSeg.front()->getRightBank() - 5, rivSeg.front()->getY() - 800. / RIV_SEGMENTS, time));
	if ((rand() % 1000)>990) boats.push_back(new Boat(rivSeg.front()->getX(), rivSeg.front()->getY(), rand() % (int)(rivSeg.front()->getSpan()/2. - 20), rand() % 20 / 2., time));
	if ((rand() % 1000)>990) fuel.push_back(new Fuel(rand() % rand() % (int)(rivSeg.front()->getSpan() - 20) + rivSeg.front()->getLeftBank() + 10, rivSeg.front()->getY(), time));
	

}
void River::Render()
{
	/****RENDERUJ SEGMENTY RZEKI****/
	for (itSeg = rivSeg.begin(); itSeg != rivSeg.end(); itSeg++)
	{
		(*itSeg)->Render();
	}

	/****RENDERUJ LODZIE****/
	for (itBoat = boats.begin(); itBoat != boats.end(); itBoat++)
	{
		(*itBoat)->Render();
	}

	/****RENDERUJ TORPEDY****/
	for (itTorp = torpedos.begin(); itTorp != torpedos.end(); itTorp++)
	{
		(*itTorp)->Render();
	}

	/****RENDERUJ PALIWO****/
	for (itFuel = fuel.begin(); itFuel != fuel.end(); itFuel++)
	{
		(*itFuel)->Render();
	}
}

bool River::IsHit(PlayerBoat* pB)
{
	for (itSeg = rivSeg.begin(); itSeg != rivSeg.end(); itSeg++)
	{
		if ((*itSeg)->IsHit(pB)) return true;
	}
	
	for (itBoat = boats.begin(); itBoat != boats.end(); itBoat++)
	{
		if((*itBoat)->IsHit(pB)) return true;
	}
	return false;
}

void River::InsertTorpedo(float x, float y, float& time)
{
	torpedos.push_back(new Torpedo(x, y, time));
}

int River::Refuel(PlayerBoat* pB)
{
	int r = 0;
	for (itFuel = fuel.begin(); itFuel != fuel.end(); itFuel++)
	{
		if((*itFuel)->IsHit(pB)) r++;
	}

	return 20*r;
}

int River::GainScore()
{
	return 10*scoreGain;
}

