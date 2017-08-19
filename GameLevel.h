#pragma once
#include "Graphics.h"
class GameLevel
{



protected:
	static Graphics* gfx;

public:
	int switchTo = -1;
	GameLevel();
	static void Init(Graphics* graphics);

	virtual ~GameLevel();
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Update(double time, double dtime) = 0;
	virtual void Render() = 0;
	virtual void ProcessKey(int& h, int& v, int& s, double dtime) = 0;
};

