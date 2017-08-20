#include "Torpedo.h"


Texture* Torpedo::_tex;

Torpedo::Torpedo(float x, float y, float t0)
{
	_y = y;
	_x = x;
	_y0 = y;
	_x0 = x;
	_t0 = t0;
	_isShot = false;

}


Torpedo::~Torpedo()
{
}

void Torpedo::Move(const float& time)
{
	_y = _y0 - 500 * (time - _t0);
}
void Torpedo::Update(const float& time)
{
	Move(time);
}

bool Torpedo::IsOutOfScreen()
{
	return _y < 0;
}

void Torpedo::Render()
{
	_tex->Draw(_x, _y);
}

void Torpedo::LoadTexture()
{
	Torpedo::_tex = new Texture(L"Torpedo.png");
}

void Torpedo::UnloadTexture()
{
	delete Torpedo::_tex;
}

void Torpedo::SetAsShot()
{
	_isShot = true;
}

bool Torpedo::IsShot()
{
	return _isShot;
}
