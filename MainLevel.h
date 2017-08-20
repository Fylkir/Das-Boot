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
	PlayerBoat _playerBoat;
	River _river;
	FuelIndicator _fInd;
	ScoreIndicator _sInd;
	float _time;
	float _fuel;
	static int _score;

public:

	MainLevel();
	~MainLevel();

	void Load() override;
	void Unload() override;
	void Update(const float& time, const float& dtime) override;
	void Render() override;
	void ProcessKey(int& h, int& v, int& s, double dtime) override;
};

