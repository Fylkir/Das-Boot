#include "Boat.h"


Texture* Boat::tex;
Boat::Boat(float x, float y, float a, float b, float t0) 
{	
	_x = x;
	_x0 = x;
	_y = y;
	_y0 = y;
	_a = a;
	_b = b;
	_t0 = t0;
	Shot = false; 
	

};

Boat::~Boat()
{

}

void Boat::Move(float time)
{
	_x = _x0 + _a*sin(_b*(time-_t0));
}

void Boat::Update(float& time)
{
	Move(time);
	MoveDown(time);
}

void Boat::Render()
{
	tex->Draw(_x, _y);
}

bool Boat::IsHit(PlayerBoat* pB)
{
	if (fabs(pB->getX() - _x) < 46)
		if ((fabs(pB->getY() - _y) < 40)) return true;
	return false;
}

int Boat::IsShot(std::list<Torpedo*>& t, std::list<Torpedo*>::iterator& it)
{
	int s=0;
	for (it = t.begin(); it != t.end(); it++)
	{
		if (fabs((*it)->getX() - _x) < 43.5)
			if ((fabs((*it)->getY() - _y) < 33.5))
			{
				(*it)->Shot = true;
				Shot = true;
				s = 1;
			}
	}
	return s;
}