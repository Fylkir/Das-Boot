#include "NonPlayableObject.h"



NonPlayableObject::NonPlayableObject()
{
	_isShot = false;
	_isHit = false;
}


NonPlayableObject::~NonPlayableObject()
{
}

void NonPlayableObject::MoveDown(const float& time)
{
	_y = _y0 + GAME_SPEED*(time-_t0);
}

bool NonPlayableObject::IsOutOfScreen()
{
	return _y >= 700;
}

void NonPlayableObject::Update(const float& time)
{
	MoveDown(time);
}

bool NonPlayableObject::IsHit()
{
	return _isHit;
}

bool NonPlayableObject::IsShot()
{
	return _isShot;
}
