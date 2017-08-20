#pragma once
#include "GameObject.h"
class FuelIndicator :
	public GameObject
{
private:
	float _fuel;
public:
	FuelIndicator();
	~FuelIndicator();
	void Update(const float& fuel);
	void Render();
};

