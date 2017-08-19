#include "NonPlayableObject.h"



NonPlayableObject::NonPlayableObject()
{
}


NonPlayableObject::~NonPlayableObject()
{
}

void NonPlayableObject::MoveDown(float& time)
{
	_y = _y0 + 100*(time-_t0);
}

bool NonPlayableObject::IsHit(PlayerBoat* pB)
{
	return false;
}

bool NonPlayableObject::IsOutOfScreen()
{
	return _y >= 700;
}

void NonPlayableObject::Update(float& time)
{
	MoveDown(time);
}