#pragma once
#include "GameObject.h"
#include "Torpedo.h"
#include <list>
#include <algorithm>


class PlayerBoat :
	public GameObject
{

private:
	static Texture* _tex;
	bool _isHit;

public:

	PlayerBoat();
	~PlayerBoat();

	bool ProcessKey(int&h, int&v, int&s, const double& dtime);
	void Move(const int& h,const int& v, const double& dtime);
	bool Shoot(int& s);
	void Update(const float& time);
	void Render();
	static void LoadTexture();
	static void UnloadTexture();
	void Reset();
	void SetAsHit();

};

