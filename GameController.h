#pragma once
#include "GameLevel.h"
#include "Timer.h"
#include <vector>
#include <algorithm>
class GameController
{
	GameController();


	static Timer _timer;
	static GameLevel* _currentLevel;
	static std::vector<GameLevel*> _levels_v;
	static std::vector<GameLevel*>::iterator _levels_it;
	static bool Loading;


public:


	static void LoadLevels(std::vector<GameLevel*> levels);
	static void SwitchLevel(int a);
	static void Init();
	static void Render();
	static void Update();
	static void ProcessKey(int& h, int& v, int& s);
	
	~GameController();
};

