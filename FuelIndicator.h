#pragma once
#include "GameObject.h"
class FuelIndicator :
	public GameObject
{
	float _fuel;
public:
	FuelIndicator();
	~FuelIndicator();
	void Update(float& fuel);
	void Render();
};

