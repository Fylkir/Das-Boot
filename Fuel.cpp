#include "Fuel.h"

Texture* Fuel::_tex;

void Fuel::LoadTexture()
{
	Fuel::_tex = new Texture(L"fuel.png");
}

void Fuel::UnloadTexture()
{
	delete Fuel::_tex;
}

Fuel::Fuel(float x, float y, float t0)
{
	_x = x; 
	_x0 = x; 
	_y = y; 
	_y0 = y; 
	_t0 = t0;
}

Fuel::~Fuel()
{
}

void Fuel::Render()
{
	_tex->Draw(_x, _y);
}

void Fuel::CheckHits(PlayerBoat& pB)
{
	if (fabs(pB.getX() - _x) < 12)
		if ((fabs(pB.getY() - _y) < 39))
		{
			_isHit = true;
		}
}

void Fuel::CheckShots(std::list<Torpedo>& t, std::list<Torpedo>::iterator& it)
{
	for (it = t.begin(); it != t.end(); it++)
	{
		if (fabs((*it).getX() - _x) < 20)
			if ((fabs((*it).getY() - _y) < 15))
			{
				(*it).SetAsShot();
				_isShot = true;

			}
	}
}

