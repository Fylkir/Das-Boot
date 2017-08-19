#include "FuelIndicator.h"



FuelIndicator::FuelIndicator()
{
	_x = 650;
	_y = 550;
	_x0 = 650;
	_y0 = 550;
	_fuel = 100;
}


FuelIndicator::~FuelIndicator()
{
}

void FuelIndicator::Update(float& fuel)
{
	_fuel = fuel;
}
void FuelIndicator::Render()
{

	gfx->DrawWhiteRectangle(_x, _y, 100, 20);
	gfx->DrawRedRectangle(_x, _y, _fuel, 20);
	gfx->DrawBlackRectangleFrame(_x, _y, 100, 20);
	gfx->PrintText(L"FUEL:", _x, _y - 20, 80, 20);
}