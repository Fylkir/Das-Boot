#pragma once
#include "NonPlayableObject.h"
#include "PlayerBoat.h"
#include "Torpedo.h"
#include <cmath>
#include <list>
#include <algorithm>
class Boat : public NonPlayableObject
{

	static Texture* _tex;
	float _a, _b; // FUNKCJA RUCHU X = ASIN(BT) + X_0
	
public:


	Boat(float x, float y, float a, float b, float t0);
	~Boat();

	static void LoadTexture();
	static void UnloadTexture();

	void Move(const float& time);
	void Update(const float& time);
	void CheckHits(PlayerBoat& pB) override;
	void CheckShots(std::list<Torpedo>& t, std::list<Torpedo>::iterator& it) override;
	void Render() override;


};

