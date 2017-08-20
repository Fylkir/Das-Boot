#pragma once
#include "GameObject.h"
#include "PlayerBoat.h"
class NonPlayableObject : public GameObject
{
protected:
	bool _isHit;
	bool _isShot;

public:
	NonPlayableObject();
	~NonPlayableObject();

	virtual void CheckHits(PlayerBoat& pB) = 0;//SPRAWDZ CZY OBIEKT ZOSTAL TRAFIONY PRZEZ LODKE
	virtual void CheckShots(std::list<Torpedo>& t, std::list<Torpedo>::iterator& it) = 0;
	bool IsOutOfScreen();
	void MoveDown(const float& time); //PRZESUWAJ W DOL Z CZASEM
	void Update(const float& time);
	bool IsHit();
	bool IsShot();



};

