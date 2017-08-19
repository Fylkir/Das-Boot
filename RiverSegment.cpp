#include "RiverSegment.h"



RiverSegment::RiverSegment(float xbl, float xbr, float xtl, float xtr, float ymid, float time)
{
	_x_bl = xbl;
	_x_br = xbr;
	_x_tl = xtl;
	_x_tr = xtr;
	_y = ymid;
	_x = (xbl + xbr + xtl + xtr) / 4;
	_y0 = ymid;
	_x0 = 0;
	_t0 = time;
	_span = (xbr + xtr - xbl - xtl) / 2.;

}


RiverSegment::~RiverSegment()
{
}
void RiverSegment::Update(float& time)
{
	MoveDown(time);
}

void RiverSegment::Render()
{
	gfx->DrawTrapezium(_x_bl, _x_br, _x_tl, _x_tr, _y);
}


/*******SPRAWDZANIE WPADNIECIA LODKI NA BRZEG SEGMENTU RZEKI*******/
bool RiverSegment::IsHit(PlayerBoat* pB)
{
	if (fabs(pB->getY() - _y) <= 800. / 2. / RIV_SEGMENTS)
		if(pB->getX() < (_x_bl + _x_tl)/2. +10 || pB->getX() > (_x_br + _x_tr) / 2. -10) return true;
	return false;
}

void RiverSegment::IsShot(std::list<Torpedo*>& t, std::list<Torpedo*>::iterator& it)
{
	{
		for (it = t.begin(); it != t.end(); it++)
		{
			if (fabs((*it)->getY() - _y) <= 800. / 2. / RIV_SEGMENTS)
				if ((*it)->getX() < (_x_bl + _x_tl) / 2. + 5 || (*it)->getX() > (_x_br + _x_tr) / 2. - 5)
				{
					(*it)->Shot = true;
				}
		}
	}
}


/****POBIERZ WSPOLRZEDNA LEWEGO GORNEGO PUNKTU SEGMENTU****/
float RiverSegment::getLeftBank()
{
	return _x_tl;
}


/****POBIERZ WSPOLRZEDNA PRAWEGO GORNEGO PUNKTU SEGMENTU****/
float RiverSegment::getRightBank()
{
	return _x_tr;
}

float RiverSegment::getSpan()
{
	return _span;
}