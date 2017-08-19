#pragma once
#include "GameObject.h"
class Torpedo :
	public GameObject
{
public:
	static Texture* tex;
	bool Shot;
	Torpedo(float x, float y, float t0);
	~Torpedo();

	void Move(float& time);
	void Update(float& time);
	bool IsOutOfScreen();
	void Render();



};

