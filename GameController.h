#pragma once
#include "GameLevel.h"
#include "Timer.h"
#include <vector>
#include <algorithm>
class GameController
{
	GameController();


	static Timer* timer;
	static GameLevel* currentLevel;
public:
	static std::vector<GameLevel*> _levels;
	static std::vector<GameLevel*>::iterator itLev;
	static bool Loading;
	static void LoadLevels(std::vector<GameLevel*> levels);
	static void SwitchLevel(int a);
	static void Init();
	static void Render();
	static void Update();
	static void ProcessKey(int& h, int& v, int& s);
	
	~GameController();
};

