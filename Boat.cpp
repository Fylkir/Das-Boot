#include "Boat.h"


Texture* Boat::_tex;


Boat::Boat(float x, float y, float a, float b, float t0) 
{	
	_x = x;
	_x0 = x;
	_y = y;
	_y0 = y;
	_a = a;
	_b = b;
	_t0 = t0;
	

};

Boat::~Boat()
{

}

void Boat::LoadTexture()
{
	Boat::_tex = new Texture(L"Boat.png");
}

void Boat::UnloadTexture()
{
	delete Boat::_tex;
}

void Boat::Move(const float& time)
{
	_x = _x0 + _a*sin(_b*(time-_t0));
}

void Boat::Update(const float& time)
{
	Move(time);
	MoveDown(time);
}

void Boat::Render()
{
	_tex->Draw(_x, _y);
}

void Boat::CheckHits(PlayerBoat& pB)
{
	if (fabs(pB.getX() - _x) < 46)
		if ((fabs(pB.getY() - _y) < 40)) _isHit = true;
}

void Boat::CheckShots(std::list<Torpedo>& t, std::list<Torpedo>::iterator& it)
{
	for (it = t.begin(); it != t.end(); it++)
	{
		if (fabs((*it).getX() - _x) < 43.5)
			if ((fabs((*it).getY() - _y) < 33.5))
			{
				(*it).SetAsShot();
				_isShot = true;
			}
	}
}