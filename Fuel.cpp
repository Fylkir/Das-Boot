#include "Fuel.h"

Texture* Fuel::tex;

Fuel::~Fuel()
{
}

void Fuel::Render()
{
	tex->Draw(_x, _y);
}

bool Fuel::IsHit(PlayerBoat* pB)
{
	if (fabs(pB->getX() - _x) < 12)
		if ((fabs(pB->getY() - _y) < 39))
		{
			Hit = true;
			return true;
		}
	return false;
}

void Fuel::IsShot(std::list<Torpedo*>& t, std::list<Torpedo*>::iterator& it)
{
	for (it = t.begin(); it != t.end(); it++)
	{
		if (fabs((*it)->getX() - _x) < 20)
			if ((fabs((*it)->getY() - _y) < 15))
			{
				(*it)->Shot = true;
				Shot = true;

			}
	}
}

