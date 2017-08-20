#pragma once
#include "NonPlayableObject.h"
class Fuel :
	public NonPlayableObject
{

private:
	static Texture* _tex;

public:

	Fuel(float x, float y, float t0);
	~Fuel();

	void CheckHits(PlayerBoat& pB) override;
	void CheckShots(std::list<Torpedo>& t, std::list<Torpedo>::iterator& it) override;
	void Render() override;
	static void LoadTexture();
	static void UnloadTexture();

};

