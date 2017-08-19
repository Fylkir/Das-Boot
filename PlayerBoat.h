#pragma once
#include "GameObject.h"
#include "Torpedo.h"
#include <list>
#include <algorithm>


class PlayerBoat :
	public GameObject
{

	const float speed = 200.;

public:
	static Texture* tex;
	PlayerBoat();
	~PlayerBoat();

	bool ProcessKey(int&h, int&v, int&s, double dtime);
	void Move(int& h, int& v, double dtime);
	bool Shoot(int& s);
	void Update(float& time);
	void Render();

};

