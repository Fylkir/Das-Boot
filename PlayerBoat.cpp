#include "PlayerBoat.h"


Texture* PlayerBoat::tex;

PlayerBoat::PlayerBoat()
{
	_x = 400.;
	_y = 550.;

}


PlayerBoat::~PlayerBoat()
{
}

bool PlayerBoat::ProcessKey(int& h, int& v, int& s, double dtime)
{
	Move(h, v, dtime);
	return Shoot(s);
}
void PlayerBoat::Move(int& h, int& v, double dtime)
{
	
	_x +=  dtime * speed * h;
	_y +=  dtime * speed * v;

	if (_y < 50.) _y = 50.;
	if (_y > 550.) _y = 550.;

}


bool PlayerBoat::Shoot(int& s)
{
	if (s == 1) return true;
	return false;
}
void PlayerBoat::Update(float& time)
{
}
void PlayerBoat::Render()
{
	tex->Draw(_x, _y);
}