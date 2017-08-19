#include "Level1.h"

Level1::Level1() 
{

}
Level1::~Level1()
{

}

void Level1::Load()
{
	y = 0.;
	yspeed = 0.;

}
void Level1::Unload() {};
void Level1::Update()
{
	//UPDATE
	yspeed += 0.2;
	y += yspeed;

	if (y > 600)
	{
		y = 600;
		yspeed = -yspeed;
	}
}
void Level1::Render()
{
	gfx->DrawObject(400, y);
}