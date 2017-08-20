#include "PlayerBoat.h"


Texture* PlayerBoat::_tex;

PlayerBoat::PlayerBoat()
{
	Reset();
}


PlayerBoat::~PlayerBoat()
{
}

bool PlayerBoat::ProcessKey(int& h, int& v, int& s, const double& dtime)
{
	Move(h, v, dtime);
	return Shoot(s);
}
void PlayerBoat::Move(const int& h, const int& v, const double& dtime)
{
	
	_x +=  dtime * BOAT_MOVEMENT_SPEED * h;
	_y +=  dtime * BOAT_MOVEMENT_SPEED * v;

	if (_y < 50.) _y = 50.;
	if (_y > 550.) _y = 550.;

}


bool PlayerBoat::Shoot(int& s)
{
	if (s == 1) return true;
	return false;
}
void PlayerBoat::Update(const float& time)
{
}
void PlayerBoat::Render()
{
	_tex->Draw(_x, _y);
}

void PlayerBoat::LoadTexture()
{
	PlayerBoat::_tex = new Texture(L"pBoat.png");
}

void PlayerBoat::UnloadTexture()
{
	delete PlayerBoat::_tex;
}

void PlayerBoat::Reset()
{
	_x = 400;
	_y = 550;
	_isHit = false;
}

void PlayerBoat::SetAsHit()
{
	_isHit = true;
}
