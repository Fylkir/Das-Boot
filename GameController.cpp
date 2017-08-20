#include "GameController.h"

GameLevel* GameController::_currentLevel;
bool GameController::Loading;
std::vector<GameLevel*> GameController::_levels_v;
Timer GameController::_timer;

GameController::GameController()
{
}


GameController::~GameController()
{
}





void GameController::Init()
{
	Loading = true;
	_currentLevel = 0;
}



void GameController::LoadLevels(std::vector<GameLevel*> levels)
{
	
	Loading = true;
	_levels_v = levels;
	_currentLevel = _levels_v[0];
	_currentLevel->Load();
	_timer.Reset();
	Loading = false;
}
void GameController::SwitchLevel(int a)
{
	Loading = true;
	_currentLevel->Unload();
	_currentLevel = _levels_v[a];
	_currentLevel->Load();
	_timer.Reset();
	Loading = false;
}
void GameController::Render()
{
	if (Loading) return;
	_currentLevel->Render();
}
void GameController::Update()
{
	if (Loading) return;
	_timer.Update();
	if(_currentLevel->switchTo <0) _currentLevel->Update(_timer.GetTimeTotal(), _timer.GetTimeDelta());
	else SwitchLevel(_currentLevel->switchTo);
}

void GameController::ProcessKey(int& h, int& v, int& s)
{
	_currentLevel->ProcessKey(h, v, s, _timer.GetTimeDelta());
}