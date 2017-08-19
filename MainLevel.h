#pragma once
#include "GameLevel.h"
#include "GameObject.h"
#include "Boat.h"
#include "River.h"
#include "PlayerBoat.h"
#include "FuelIndicator.h"
#include "ScoreIndicator.h"
#include "GameOverLevel.h"
#include <list>
#include <algorithm>
class MainLevel : public GameLevel
{
	friend class GameOverLevel;
private:
	PlayerBoat* playerBoat;
	River* river;
	FuelIndicator* fInd;
	ScoreIndicator* sInd;
	static float _time;
	static float _fuel;
	static int _score;

public:

	MainLevel();
	~MainLevel();

	void Load() override;
	void Unload() override;
	void Update(double time, double dtime) override;
	void Render() override;
	void ProcessKey(int& h, int& v, int& s, double dtime) override;
};

