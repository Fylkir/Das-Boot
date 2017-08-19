#pragma once
#include "GameObject.h"
#include "PlayerBoat.h"
class NonPlayableObject : public GameObject
{
public:
	NonPlayableObject();
	~NonPlayableObject();

	virtual bool IsHit(PlayerBoat* pB) = 0;//SPRAWDZ CZY OBIEKT ZOSTAL TRAFIONY PRZEZ LODKE
	bool IsOutOfScreen();
	void MoveDown(float& time); //PRZESUWAJ W DOL Z CZASEM
	void Update(float& time);
};

