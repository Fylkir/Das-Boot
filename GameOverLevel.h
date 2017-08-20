#pragma once
#include "GameLevel.h"
#include "MainLevel.h"
class GameOverLevel :
	public GameLevel
{
public:
	GameOverLevel();
	~GameOverLevel();

	void Load() override;
	void Unload() override;
	void Update(const float& time, const float& dtime) override;
	void Render() override;
	void ProcessKey(int& h, int& v, int& s, double dtime);
};

