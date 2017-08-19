#include "Torpedo.h"


Texture* Torpedo::tex;

Torpedo::Torpedo(float x, float y, float t0)
{
	_y = y;
	_x = x;
	_y0 = y;
	_x0 = x;
	_t0 = t0;
	Shot = false;

}


Torpedo::~Torpedo()
{
}

void Torpedo::Move(float& time)
{
	_y = _y0 - 500 * (time - _t0);
}
void Torpedo::Update(float& time)
{
	Move(time);
}

bool Torpedo::IsOutOfScreen()
{
	return _y < 0;
}

void Torpedo::Render()
{
	tex->Draw(_x, _y);
}